#include <unistd.h>

#include <algorithm>
#include <cstdio>
#include <exception>
#include <filesystem>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include <bits/types/struct_FILE.h>

#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"
#include "ocppi/cli/CLI.hpp"
#include "ocppi/cli/crun/Crun.hpp"
#include "ocppi/runtime/Signal.hpp"
#include "ocppi/runtime/state/types/Generators.hpp" // IWYU pragma: keep
#include "ocppi/types/ContainerListItem.hpp"
#include "ocppi/types/Generators.hpp" // IWYU pragma: keep
#include "tl/expected.hpp"

namespace spdlog
{
namespace sinks
{
class sink;
} // namespace sinks
} // namespace spdlog

void printException(std::string_view msg, std::exception_ptr ptr) noexcept
try {
        std::rethrow_exception(std::move(ptr));
} catch (const std::exception &e) {
        std::cerr << msg << ": " << e.what() << std::endl;
} catch (...) {
        std::cerr << msg << ": unknown exception" << std::endl;
}

auto main() -> int
{
        try {
                std::unique_ptr<ocppi::cli::CLI> cli;
                {
                        auto crun =
                                ocppi::cli::crun::Crun::New("/usr/bin/crun");
                        if (!crun) {
                                printException("New crun object failed",
                                               crun.error());
                                return -1;
                        }
                        cli = std::move(crun.value());
                }

                auto bin = cli->bin();
                std::cerr << "Using OCI runtime CLI program \"" << bin.string()
                          << "\"" << std::endl;

                auto containerList = cli->list();
                if (!containerList) {
                        printException("Run crun list failed",
                                       containerList.error());
                        return -1;
                }

                if (containerList->empty()) {
                        std::cerr << "No container exists." << std::endl;
                        return 0;
                }

                for (auto container : containerList.value()) {
                        nlohmann::json containerJSON = container;
                        std::cerr << "Existing container "
                                  << containerJSON.dump() << std::endl;
                }

                auto state = cli->state(containerList->front().id);

                if (!state) {
                        printException("Run crun state failed", state.error());
                        return -1;
                }

                nlohmann::json stateJSON = state.value();
                std::cout << stateJSON.dump(1, '\t') << std::endl;

                auto killResult = cli->kill(containerList->front().id,
                                            ocppi::runtime::Signal("SIGTERM"));

                if (!killResult) {
                        printException("Run crun kill failed",
                                       killResult.error());
                        return -1;
                }

                return 0;
        } catch (...) {
                printException("Failed to kill first crun container",
                               std::current_exception());
                return -1;
        }

        return 0;
}
