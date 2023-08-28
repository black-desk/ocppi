// Thish file is generated by quicktype,
// check /tools/codegen for further information.
// DO NOT EDIT IT.

//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     SchemaProperties.hpp data = nlohmann::json::parse(jsonString);
//
//  You can get std::wstring data back out using
//
//     std::wcout << wdump((nlohmann::json) Schema);

#pragma once

#include <optional>

#include <nlohmann/json.hpp>

#include "ArrayOfGiDs.hpp"
#include "Env.hpp"
#include "FilePath.hpp"
#include "Hooks.hpp"
#include "NamespaceType.hpp"
#include "OciVersion.hpp"
#include "Pid.hpp"
#include "Process.hpp"
#include "Root.hpp"
#include "helper.hpp"

namespace ocppi
{
namespace runtime
{
namespace config
{
using nlohmann::json;

struct SchemaProperties {
        std::optional<Env> ociVersion;
        std::optional<Hooks> hooks;
        Env annotations;
        std::optional<FilePath> hostname;
        std::optional<FilePath> domainname;
        std::optional<ArrayOfGiDs> mounts;
        std::optional<Root> root;
        std::optional<Process> process;
        std::optional<Env> linux;
        std::optional<Env> solaris;
        std::optional<Env> windows;
        std::optional<Env> vm;
        std::optional<Env> zos;
        std::optional<Env> ociVersionMin;
        std::optional<Env> ociVersionMax;
        std::optional<Env> mountOptions;
        std::optional<OciVersion> id;
        std::optional<NamespaceType> status;
        std::optional<Pid> pid;
        std::optional<FilePath> bundle;
};
}
}
}
