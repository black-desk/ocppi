// Thish file is generated by /tools/codegen powered by quicktype.
// DO NOT EDIT IT.

// clang-format off

//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     Anet.hpp data = nlohmann::json::parse(jsonString);

#pragma once

#include <optional>
#include <nlohmann/json.hpp>
#include <ocppi/runtime/config/types/helper.hpp>

namespace ocppi {
namespace runtime {
namespace config {
namespace types {
using nlohmann::json;

struct Anet {
std::optional<std::string> allowedAddress;
std::optional<std::string> configureAllowedAddress;
std::optional<std::string> defrouter;
std::optional<std::string> linkname;
std::optional<std::string> linkProtection;
std::optional<std::string> lowerLink;
std::optional<std::string> macAddress;
};
}
}
}
}

// clang-format on