#pragma once

#include <filesystem>
#include <system_error>

namespace ocppi::cli
{

class ExecutableNotFoundError : public std::system_error {
        using system_error::system_error;

    public:
        explicit ExecutableNotFoundError(const std::filesystem::path &exe)
                : std::system_error(ENOENT, std::generic_category(),
                                    "check executable at [" + exe.string() +
                                            "]")
        {
        }
};

}
