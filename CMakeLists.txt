cmake_minimum_required(VERSION 2.8.12)
project(MyCudaBevFusion)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_RELEASE "-std=c++14 -Wextra -Wall -Wno-missing-field-initializers -Wno-deprecated-declarations -O3 -DENABLE_TEXT_BACKEND_STB")
set(CMAKE_CXX_FLAGS_DEBUG   "-std=c++14 -O0 -g -DENABLE_TEXT_BACKEND_STB")

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

option(BUILD_TEST "Whether or not to build the tests" ON)
if (${BUILD_TEST})
    message(STATUS "Building tests")
    enable_testing()  # Enable testing only works in root scope
    add_subdirectory(bevfusion/modules/image_preprocess/unit_tests )
    # add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/bevfusion/modules/image_preprocess/unit_tests output)
endif ()
