cmake_minimum_required(VERSION 3.0)

# set headers
message(STATUS "MY_LIBRARY_SOURCE_DIR ==> " "${MY_LIBRARY_SOURCE_DIR}" )
set(header_path "${MY_LIBRARY_SOURCE_DIR}/include/my_library")
set(header ${header_path}/header-a.hpp)

# set source files
set(src src.cpp)

# configure config.hpp.in
configure_file("config.hpp.in" "${CMAKE_CURRENT_BINARY_DIR}/config_impl.hpp")

# define library target
add_library(my_library ${header} ${src})

#target_include_directories(my_library PUBLIC ${MY_LIBRARY_SOURCE_DIR}/include ${CMAKE_CURRENT_BINARY_DIR})

target_include_directories(my_library PUBLIC
                       $<BUILD_INTERFACE:${MY_LIBRARY_SOURCE_DIR}/include>
                       $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>
                       $<INSTALL_INTERFACE:${include_dest}>
                       $<INSTALL_INTERFACE:${lib_dest}>)

IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
	SET(CMAKE_INSTALL_PREFIX ../runtime/ CACHE PATH "this is new path" FORCE)
ENDIF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)


install(TARGETS my_library DESTINATION "${lib_dest}")
install(FILES ${header} DESTINATION "${include_dest}")
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/config_impl.hpp DESTINATION "${include_dest}")
install(TARGETS my_library EXPORT my_library DESTINATION "${lib_dest}")
