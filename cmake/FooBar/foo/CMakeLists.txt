configure_file(config.h.in "${CMAKE_CURRENT_BINARY_DIR}/config.h" @ONLY)

add_library(foo SHARED foo.c foo.h config.h.in)

set_target_properties(foo PROPERTIES
  PUBLIC_HEADER "foo.h;${CMAKE_CURRENT_BINARY_DIR}/config.h")

install(TARGETS foo
  # IMPORTANT: Add the foo library to the "export-set"
  EXPORT FooBarTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
  LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
  PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/foo"
    COMPONENT dev)
