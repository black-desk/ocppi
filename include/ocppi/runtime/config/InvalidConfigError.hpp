#pragma once

#include <ocppi/InvalidArgumentError.hpp>

namespace ocppi::runtime::config
{
class InvalidConfigError : public InvalidArgumentError {
        using InvalidArgumentError::InvalidArgumentError;
        static constexpr const char *prefix = "invalid config: ";

    public:
        explicit InvalidConfigError(const std::string &arg)
                : InvalidArgumentError(prefix + arg)
        {
        }
        explicit InvalidConfigError(const char *arg)
                : InvalidArgumentError(prefix + std::string(arg))
        {
        }
};

}
