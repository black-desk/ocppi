// Thish file is generated by quicktype,
// check /tools/codegen for further information.
// DO NOT EDIT IT.

//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     PurpleProperties.hpp data = nlohmann::json::parse(jsonString);
//
//  You can get std::wstring data back out using
//
//     std::wcout << wdump((nlohmann::json) Schema);

#pragma once

#include <optional>

#include <nlohmann/json.hpp>

#include "Env.hpp"
#include "helper.hpp"

namespace ocppi
{
namespace runtime
{
namespace config
{
using nlohmann::json;

struct PurpleProperties {
        Env rate;
};
}
}
}
