// Thish file is generated by /tools/codegen
// DO NOT EDIT IT.

// clang-format off

//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     PurpleCPU.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <nlohmann/json.hpp>
#include "ocppi/runtime/config/types/helper.hpp"

namespace ocppi {
namespace runtime {
namespace config {
namespace types {
using nlohmann::json;

struct PurpleCPU {
std::optional<int64_t> burst;
std::optional<std::string> cpus;
std::optional<int64_t> idle;
std::optional<std::string> mems;
std::optional<int64_t> period;
std::optional<int64_t> quota;
std::optional<int64_t> realtimePeriod;
std::optional<int64_t> realtimeRuntime;
std::optional<int64_t> shares;
};
}
}
}
}

// clang-format on
