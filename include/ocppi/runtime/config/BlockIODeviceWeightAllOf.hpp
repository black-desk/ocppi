// Thish file is generated by quicktype,
// check /tools/codegen for further information.
// DO NOT EDIT IT.

//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     BlockIODeviceWeightAllOf.hpp data = nlohmann::json::parse(jsonString);
//
//  You can get std::wstring data back out using
//
//     std::wcout << wdump((nlohmann::json) Schema);

#pragma once

#include <optional>
#include <nlohmann/json.hpp>
#include "helper.hpp"

#include "FluffyProperties.hpp"

namespace ocppi {
namespace runtime {
namespace config {
enum class FilePathType : int;
}
}
}

namespace ocppi {
namespace runtime {
namespace config {
using nlohmann::json;

struct BlockIODeviceWeightAllOf {
std::optional<std::wstring> ref;
std::optional<FilePathType> type;
std::optional<FluffyProperties> properties;
};
}
}
}

