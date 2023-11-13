add_library(nn_interpol_base   STATIC  nn_interpol_base.cpp)

# target_include_directories(nn_interpol_base PUBLIC image_preprocess)
target_include_directories(nn_interpol_base PUBLIC ../)

message("........", ${CMAKE_CURRENT_SOURCE_DIR})