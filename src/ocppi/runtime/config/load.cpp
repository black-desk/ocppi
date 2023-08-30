#include "ocppi/runtime/config/load.hpp"

#include "ocppi/runtime/config/KeyMissingError.hpp"
#include "ocppi/runtime/config/WrongTypeError.hpp"
#include "ocppi/utils/ewrap/EWRAP.hpp"

namespace ocppi::runtime::config
{

auto load(std::istream &input, types::Config *cfg) noexcept
        -> std::optional<std::exception>
try {
        auto j = nlohmann::json::parse(input);

        constexpr auto versionKey = "ociVersion";
        auto versionIt = j.find(versionKey);
        if (versionIt == j.end()) {
                throw KeyMissingError(versionKey);
        }

        if (!versionIt->is_string()) {
                throw WrongTypeError(versionKey);
        }

        return std::nullopt;
} catch (const std::exception &e) {
        return EWRAP(e, std::runtime_error("load"));
}

}
