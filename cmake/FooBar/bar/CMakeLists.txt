add_executable(bar bar.c)

target_link_libraries(bar foo)

message(STATUS "cmake install prefix dir ====> " "${CMAKE_INSTALL_PREFIX}")
message(STATUS "bar install bin dir ====> " "${INSTALL_BIN_DIR}")

install(TARGETS bar
  # IMPORTANT: Add the bar executable to the "export-set"
  EXPORT FooBarTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin)
