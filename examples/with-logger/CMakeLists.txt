if(NOT OCPPI_WITH_SPDLOG)
  return()
endif()

find_package(
  PkgConfig REQUIRED)
pkg_check_modules(systemd REQUIRED IMPORTED_TARGET libsystemd)

pfl_add_executable(
  INTERNAL
  SOURCES
  src/main.cpp
  LINK_LIBRARIES
  PUBLIC
  ocppi::ocppi
  spdlog::spdlog
  PkgConfig::systemd)
