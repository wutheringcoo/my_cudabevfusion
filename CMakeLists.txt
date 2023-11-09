cmake_minimum_required(VERSION 3.10.0)
project(MyCudaBevFusion)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_RELEASE "-std=c++14 -Wextra -Wall -Wno-missing-field-initializers -Wno-deprecated-declarations -O3 -DENABLE_TEXT_BACKEND_STB")
set(CMAKE_CXX_FLAGS_DEBUG   "-std=c++14 -O0 -g -DENABLE_TEXT_BACKEND_STB")

# 1) 编译common目录下的静态库
include_directories(
    bevfusion/common
    bevfusion/modules/image_preprocess
    )
add_library(bevfusion_params bevfusion/common/bevfusion_params.cpp)

add_subdirectory(third_party/googletest)
# add_subdirectory(bevfusion/modules/image_preprocess)
# add_subdirectory(bevfusion/common)

option(BUILD_TEST "Whether or not to build the tests" ON)
if (${BUILD_TEST})
    message(STATUS "Building tests")
    enable_testing()  # Enable testing only works in root scope
    add_subdirectory(bevfusion/modules/image_preprocess/unit_tests )
    # add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/bevfusion/modules/image_preprocess/unit_tests output)
endif ()

# 设置编译输出的目录？
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build)

# add_subdirectory 指定路径下需要有CMakeLists.txt文件，并且添加 bevfusion/modules/image_preprocess子目录，将其输出的.a文件存到output目录
#add_subdirectory(bevfusion/modules/image_preprocess output)