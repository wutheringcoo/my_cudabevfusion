set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin) # define relative dir build if cmake.. and make here
cmake_minimum_required(VERSION 3.10.0)

project(image_preprocess_ut) # Built target name called image_preprocess_ut

enable_testing()
add_executable(nn_interpol_base_test_exec.out nn_interpol_base_test.cpp)

# target_link_libraries(nn_interpol_base_test_exec.out nn_interpol_base gtest gtest_main gmock_main pthread)
target_link_libraries(nn_interpol_base_test_exec.out  gtest gtest_main gmock_main pthread bevfusion_params)
# add_test(NAME NN_INTERPOL_BASE_TEST COMMAND nn_interpol_base_test_exec.out)
# set_property(
#     TEST NN_INTERPOL_BASE_TEST
#     PROPERTY LABELS lib NN_INTERPOL_BASE_TEST
#     )

### gen CXX static library libimage_preprocess_ut.a
# add_library(${PROJECT_NAME} nn_interpol_base_test.cpp) #
# target_link_libraries(nn_interpol_base_test_exec.out image_preprocess_ut)

