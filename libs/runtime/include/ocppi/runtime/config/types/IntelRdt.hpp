// Thish file is generated by /tools/codegen
// DO NOT EDIT IT.

// clang-format off

//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     IntelRdt.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <nlohmann/json.hpp>
#include "ocppi/runtime/config/types/helper.hpp"

namespace ocppi {
namespace runtime {
namespace config {
namespace types {
using nlohmann::json;

struct IntelRdt {
std::optional<std::string> closID;
std::optional<bool> enableCMT;
std::optional<bool> enableMBM;
std::optional<std::string> l3CacheSchema;
std::optional<std::string> memBWSchema;
};
}
}
}
}

// clang-format on
