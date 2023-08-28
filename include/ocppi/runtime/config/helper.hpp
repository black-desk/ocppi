// Thish file is generated by quicktype,
// check /tools/codegen for further information.
// DO NOT EDIT IT.

//  To parse this JSON data, first install
//
//      json.hpp  https://github.com/nlohmann/json
//
//  Then include this file, and then do
//
//     helper.hpp data = nlohmann::json::parse(jsonString);
//
//  You can get std::wstring data back out using
//
//     std::wcout << wdump((nlohmann::json) Schema);

#pragma once

#include <codecvt>
#include <locale>
#include <optional>
#include <sstream>

#include <nlohmann/json.hpp>

namespace ocppi
{
namespace runtime
{
namespace config
{
using nlohmann::json;

template <typename T>
struct tag {};

template <typename fromType, typename toType>
class Utf16_Utf8 {
    private:
        template <typename TF, typename TT>
        static toType convert(tag<std::shared_ptr<TF>>,
                              tag<std::shared_ptr<TT>>, fromType ptr)
        {
                if (ptr == nullptr)
                        return std::unique_ptr<TT>();
                else
                        return std::unique_ptr<TT>(
                                new TT(Utf16_Utf8<TF, TT>::convert(*ptr)));
        }

        template <typename TF, typename TT>
        static toType convert(tag<std::vector<TF>>, tag<std::vector<TT>>,
                              fromType v)
        {
                auto it = v.begin();
                auto newVector = std::vector<TT>();
                while (it != v.end()) {
                        newVector.push_back(Utf16_Utf8<TF, TT>::convert(*it));
                        it++;
                }
                return newVector;
        }

        template <typename KF, typename VF, typename KT, typename VT>
        static toType convert(tag<std::map<KF, VF>>, tag<std::map<KT, VT>>,
                              fromType m)
        {
                auto it = m.begin();
                auto newMap = std::map<KT, VT>();
                while (it != m.end()) {
                        newMap.insert(std::pair<KT, VT>(
                                Utf16_Utf8<KF, KT>::convert(it->first),
                                Utf16_Utf8<VF, VT>::convert(it->second)));
                        it++;
                }
                return newMap;
        }

        template <typename TF, typename TT>
        static fromType convert(tag<TF>, tag<TT>, fromType from)
        {
                return from;
        }

        static std::wstring convert(tag<std::string>, tag<std::wstring>,
                                    std::string str)
        {
                return std::wstring_convert<
                               std::codecvt_utf8_utf16<wchar_t, 0x10ffff,
                                                       std::little_endian>,
                               wchar_t>{}
                        .from_bytes(str.data());
        }

        static std::string convert(tag<std::wstring>, tag<std::string>,
                                   std::wstring str)
        {
                return std::wstring_convert<
                               std::codecvt_utf8_utf16<wchar_t, 0x10ffff,
                                                       std::little_endian>,
                               wchar_t>{}
                        .to_bytes(str.data());
        }

    public:
        static toType convert(fromType in)
        {
                return convert(tag<fromType>(), tag<toType>(), in);
        }
};

template <typename T>
std::wstring wdump(const T &j)
{
        std::ostringstream s;
        s << j;
        return Utf16_Utf8<std::string, std::wstring>::convert(s.str());
}

#ifndef NLOHMANN_UNTYPED_ocppi_runtime_config_HELPER
#define NLOHMANN_UNTYPED_ocppi_runtime_config_HELPER
inline json get_untyped(const json &j, const char *property)
{
        if (j.find(property) != j.end()) {
                return j.at(property).get<json>();
        }
        return json();
}

inline json get_untyped(const json &j, std::string property)
{
        return get_untyped(j, property.data());
}
#endif

#ifndef NLOHMANN_OPTIONAL_ocppi_runtime_config_HELPER
#define NLOHMANN_OPTIONAL_ocppi_runtime_config_HELPER
template <typename T>
inline std::shared_ptr<T> get_heap_optional(const json &j, const char *property)
{
        auto it = j.find(property);
        if (it != j.end() && !it->is_null()) {
                return j.at(property).get<std::shared_ptr<T>>();
        }
        return std::shared_ptr<T>();
}

template <typename T>
inline std::shared_ptr<T> get_heap_optional(const json &j, std::string property)
{
        return get_heap_optional<T>(j, property.data());
}
template <typename T>
inline std::optional<T> get_stack_optional(const json &j, const char *property)
{
        auto it = j.find(property);
        if (it != j.end() && !it->is_null()) {
                return j.at(property).get<std::optional<T>>();
        }
        return std::optional<T>();
}

template <typename T>
inline std::optional<T> get_stack_optional(const json &j, std::string property)
{
        return get_stack_optional<T>(j, property.data());
}
#endif
}
}
}

#ifndef NLOHMANN_OPT_HELPER
#define NLOHMANN_OPT_HELPER
namespace nlohmann
{
template <typename T>
struct adl_serializer<std::shared_ptr<T>> {
        static void to_json(json &j, const std::shared_ptr<T> &opt)
        {
                if (!opt)
                        j = nullptr;
                else
                        j = *opt;
        }

        static std::shared_ptr<T> from_json(const json &j)
        {
                if (j.is_null())
                        return std::make_shared<T>();
                else
                        return std::make_shared<T>(j.get<T>());
        }
};
template <typename T>
struct adl_serializer<std::optional<T>> {
        static void to_json(json &j, const std::optional<T> &opt)
        {
                if (!opt)
                        j = nullptr;
                else
                        j = *opt;
        }

        static std::optional<T> from_json(const json &j)
        {
                if (j.is_null())
                        return std::make_optional<T>();
                else
                        return std::make_optional<T>(j.get<T>());
        }
};
}
#endif
