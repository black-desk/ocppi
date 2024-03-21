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
#include "spdlog/common.h"
#include "spdlog/logger.h"
#include "spdlog/sinks/ansicolor_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/systemd_sink.h"
#include "spdlog/spdlog.h"
#include "tl/expected.hpp"

namespace spdlog
{
namespace sinks
{
class sink;
} // namespace sinks
} // namespace spdlog

void printException(const std::shared_ptr<spdlog::logger> &logger,
                    std::string_view msg, std::exception_ptr ptr) noexcept
try {
        std::rethrow_exception(std::move(ptr));
} catch (const std::exception &e) {
        SPDLOG_LOGGER_ERROR(logger, "{}: {}", msg, e.what());
} catch (...) {
        SPDLOG_LOGGER_ERROR(logger, "{}: unknown exception", msg);
}

auto main() -> int
{
        std::shared_ptr<spdlog::logger> logger;
        {
                auto sinks = std::vector<std::shared_ptr<spdlog::sinks::sink>>(
                        { std::make_shared<spdlog::sinks::systemd_sink_mt>(
                                "ocppi") });
                if (isatty(stderr->_fileno) != 0) {
                        sinks.push_back(std::make_shared<
                                        spdlog::sinks::stderr_color_sink_mt>());
                }

                logger = std::make_shared<spdlog::logger>(
                        "ocppi", sinks.begin(), sinks.end());

                logger->set_level(spdlog::level::trace);
        }

        try {
                std::unique_ptr<ocppi::cli::CLI> cli;
                {
                        auto crun = ocppi::cli::crun::Crun::New("/usr/bin/crun",
                                                                logger);
                        if (!crun) {
                                printException(logger, "New crun object failed",
                                               crun.error());
                                return -1;
                        }
                        cli = std::move(crun.value());
                }

                auto bin = cli->bin();
                SPDLOG_LOGGER_DEBUG(logger,
                                    R"(Using OCI runtime CLI program "{}")",
                                    bin.string());

                auto containerList = cli->list();
                if (!containerList) {
                        printException(logger, "Run crun list failed",
                                       containerList.error());
                        return -1;
                }

                if (containerList->empty()) {
                        SPDLOG_LOGGER_INFO(logger, "No container exists.");
                        return 0;
                }

                for (auto container : containerList.value()) {
                        nlohmann::json containerJSON = container;
                        SPDLOG_LOGGER_INFO(logger, "Existing container {}",
                                           containerJSON.dump());
                }

                auto state = cli->state(containerList->front().id);

                if (!state) {
                        printException(logger, "Run crun state failed",
                                       state.error());
                        return -1;
                }

                nlohmann::json stateJSON = state.value();
                std::cout << stateJSON.dump(1, '\t') << std::endl;

                auto killResult = cli->kill(containerList->front().id,
                                            ocppi::runtime::Signal("SIGTERM"));

                if (!killResult) {
                        printException(logger, "Run crun kill failed",
                                       killResult.error());
                        return -1;
                }

                return 0;
        } catch (...) {
                printException(logger, "Failed to kill first crun container",
                               std::current_exception());
                return -1;
        }

        return 0;
}
