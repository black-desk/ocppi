// Thish file is generated by /tools/codegen
// DO NOT EDIT IT.

// clang-format off

//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Solaris.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <nlohmann/json.hpp>
#include "ocppi/runtime/config/types/helper.hpp"

#include "ocppi/runtime/config/types/Anet.hpp"
#include "ocppi/runtime/config/types/CappedCPU.hpp"
#include "ocppi/runtime/config/types/CappedMemory.hpp"

namespace ocppi {
namespace runtime {
namespace config {
namespace types {
/**
* Solaris platform-specific configurations
*/

using nlohmann::json;

/**
* Solaris platform-specific configurations
*/
struct Solaris {
std::optional<std::vector<Anet>> anet;
std::optional<CappedCPU> cappedCPU;
std::optional<CappedMemory> cappedMemory;
std::optional<std::string> limitpriv;
std::optional<std::string> maxShmMemory;
std::optional<std::string> milestone;
};
}
}
}
}

// clang-format on
