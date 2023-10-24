set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin) # define relative dir build if cmake.. and make here
cmake_minimum_required(VERSION 2.8.12)

project(image_preprocess_ut) # Built target name called image_preprocess_ut

# add_library(${PROJECT_NAME} nn_interpol_base_test.cpp) #make CXX static library libimage_preprocess_ut.a
enable_testing()
add_executable(nn_interpol_base_test_exec.out nn_interpol_base_test.cpp)
# target_link_libraries(nn_interpol_base_test_exec.out image_preprocess_ut)
add_test(NAME NN_INTERPOL_BASE_TEST COMMAND nn_interpol_base_test_exec.out)