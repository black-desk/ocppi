#include <ocppi/runtime/config/types/Config.hpp>

namespace ocppi::runtime::config
{

[[nodiscard]]
auto load(std::istream &, types::Config &) noexcept
        -> std::optional<std::exception>;

}
