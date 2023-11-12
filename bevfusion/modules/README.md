### TodoLists:
1)  C++ Implementation Of Nearest Interpolation/ Cuda Implementation/ Python Implementation [10.20]
2)  Consistency verification  above [10.21]

### Attention
1) if occures warning: module ‘cv2‘ has no attribute resize, please install opencv-contrib-python:  
pip install opencv-contrib-python -i https://pypi.tuna.tsinghua.edu.cn/simple
2) if occures warning: 
vscode ctrl+shift+p setting: convert indentation to spaces
3) 使用std::int32_t可以提高代码的可移植性，并确保整数类型在不同的平台上具有相同的大小。这在处理需要精确控制整数范围和大小的情况下特别有用。
4) 使用cmake 编译构建，cpp 引入头文件的处理方法是使用相对引用的方法。
5) class带入struct的表达中，如果成员变量有struct，会报错的问题优化为class类传参进入bevfusion_param class.

### Make 
1) cd build
2) cmake ..
3) make
4) ./bevfusion/modules/image_preprocess/unit_tests/bin/nn_interpol_base_test_exec.out
4) instead 3/4 step: ctest / make test
ps: cmake --build [build] 可以替换1，2步骤；