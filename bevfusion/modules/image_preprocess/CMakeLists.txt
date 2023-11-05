
# aux_source_directory (. SRC_LIST)
add_library(nn_interpol_base   STATIC  nn_interpol_base.cpp)
# add_library(nn_interpol_base   STATIC  ${SRC_LIST})

# target_include_directories(nn_interpol_base PUBLIC image_preprocess)
target_include_directories(nn_interpol_base PUBLIC ../)
#   ${CMAKE_CURRENT_SOURCE_DIR}/../api
#   ${CMAKE_CURRENT_SOURCE_DIR}/../common
#   ${CMAKE_CURRENT_SOURCE_DIR}

# )
message("........", ${CMAKE_CURRENT_SOURCE_DIR})