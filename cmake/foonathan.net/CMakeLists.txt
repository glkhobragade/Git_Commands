cmake_minimum_required(VERSION 3.0)
project(MY_LIBRARY)

# define library version (update: apparently you can also do it in project()!)
set(MY_LIBRARY_VERSION_MAJOR 1 CACHE STRING "major version" FORCE)
set(MY_LIBRARY_VERSION_MINOR 0 CACHE STRING "minor version" FORCE)
set(MY_LIBRARY_VERSION ${MY_LIBRARY_VERSION_MAJOR}.${MY_LIBRARY_VERSION_MINOR} CACHE STRING "version" FORCE)

# some options
option(MY_LIBRARY_USE_FANCY_NEW_CLASS "whether or not to use fancy new class" ON)
option(MY_LIBRARY_DEBUG_MODE "whether or not debug mode is activated" OFF)

## this variables percolates to the child directories as well
## these are used in src and tool cmake files

set(tool_dest "bin")
set(include_dest "include/my_library-${MY_LIBRARY_VERSION}")
set(main_lib_dest "lib/my_library-${MY_LIBRARY_VERSION}")
set(lib_dest "${main_lib_dest}/${CMAKE_BUILD_TYPE}")

# add subdiretories
add_subdirectory(src)
add_subdirectory(example)
add_subdirectory(tool)
add_subdirectory(test)


install(EXPORT my_library DESTINATION "${lib_dest}")
install(FILES ./runtime/lib/my_library-1.0/my_library-config.cmake DESTINATION ${main_lib_dest})


## traversing the subdirectories from root directory:
## The below lines has to debugged properly why it is not working??
message(STATUS "This is printing=> " "${tool_dest}")
#get_directory_property(subdir_list  SUBDIRECTORIES)
get_property(subdir_list DIRECTORY  PROPERTY  SUBDIRECTORIES)
#message(STATUS "This is printing=> " "${subdir_list}")

FOREACH(subdir ${subdir_list})
	#ADD_SUBDIRECTORY(${subdir})
    message(STATUS "This is printing=> " "${tool_dest}")
	message(STATUS "Dir" "${subdir}")
    #MATH(EXPR i "${i}+1")
ENDFOREACH()
