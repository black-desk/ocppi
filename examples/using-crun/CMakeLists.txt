list(APPEND LINK_LIBRARIES PUBLIC ocppi::ocppi)

if(OCPPI_WITH_SPDLOG)
  list(APPEND LINK_LIBRARIES PRIVATE spdlog::spdlog)
endif()

pfl_add_executable(INTERNAL SOURCES src/main.cpp LINK_LIBRARIES
                   ${LINK_LIBRARIES})
