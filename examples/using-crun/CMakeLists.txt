list(APPEND LINK_LIBRARIES PUBLIC ocppi::ocppi)

if(OCPPI_WITH_SPDLOG)
  list(APPEND LINK_LIBRARIES PRIVATE spdlog::spdlog)
  find_package(PkgConfig REQUIRED)
  pkg_check_modules(systemd REQUIRED IMPORTED_TARGET libsystemd)
  list(APPEND LINK_LIBRARIES PUBLIC PkgConfig::systemd)
endif()

pfl_add_executable(INTERNAL SOURCES src/main.cpp LINK_LIBRARIES
                   ${LINK_LIBRARIES})
