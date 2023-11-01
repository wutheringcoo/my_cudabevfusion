set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin) # define relative dir build if cmake.. and make here
cmake_minimum_required(VERSION 2.8.12)

project(image_preprocess_ut) # Built target name called image_preprocess_ut


enable_testing()
find_package(GTest  REQUIRED)
# include_directories(/usr/local/include/gtest/)
# find_package(GTest)
include_directories(${GTEST_INCLUDE_DIRS})
MESSAGE(${GTEST_INCLUDE_DIRS})
MESSAGE(${GTEST_BOTH_LIBRARIES})
MESSAGE(${GTEST_LIBRARIES})
MESSAGE(${GTEST_MAIN_LIBRARIES})
add_executable(nn_interpol_base_test_exec.out nn_interpol_base_test.cpp)
target_link_libraries(nn_interpol_base_test_exec.out gtest_main gmock_main pthread)
# add_test(NAME NN_INTERPOL_BASE_TEST COMMAND nn_interpol_base_test_exec.out)
gtest_discover_tests(nn_interpol_base_test_exec.out)
# set_property(
#     TEST NN_INTERPOL_BASE_TEST
#     PROPERTY LABELS lib NN_INTERPOL_BASE_TEST
#     )

### gen CXX static library libimage_preprocess_ut.a
# add_library(${PROJECT_NAME} nn_interpol_base_test.cpp) #
# target_link_libraries(nn_interpol_base_test_exec.out image_preprocess_ut)


# run with: ctest -L lib
