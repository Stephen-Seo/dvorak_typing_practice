cmake_minimum_required(VERSION 3.22.1)
project(DvorakTypingPractice)

set(DvorakTypingPractice_SOURCES
	"${CMAKE_CURRENT_SOURCE_DIR}/src/main.cc"
	"${CMAKE_CURRENT_SOURCE_DIR}/src/screen.cc"
)

set(DvorakTypingPractice_HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/screen.h"
)

add_executable(DvorakTypingPractice ${DvorakTypingPractice_SOURCES})

find_package(raylib REQUIRED)

target_include_directories(DvorakTypingPractice PUBLIC ${raylib_INCLUDE_DIRS})
target_link_libraries(DvorakTypingPractice PUBLIC ${raylib_LIBRARIES})

target_compile_options(DvorakTypingPractice PUBLIC
    -Wall -Wextra -Wpedantic
    $<$<COMPILE_LANGUAGE:CXX>:-Weffc++>
    $<$<CONFIG:DEBUG>:-Og>
)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to 'Debug', none was specified.")
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif()

if(EXISTS /usr/bin/clang-format)
    add_custom_target(
        ClangFormatTarget
        COMMAND clang-format -i --style=google ${DvorakTypingPractice_SOURCES} ${DvorakTypingPractice_HEADERS}
    )
    add_dependencies(DvorakTypingPractice ClangFormatTarget)
    message(STATUS "Enabled clang-format formatting.")
endif()
