### TodoLists:
1)  C++ Implementation Of Nearest Interpolation/ Cuda Implementation/ Python Implementation [10.20]
2)  Consistency verification  above [10.21]

### Attention
1) if occures warning: module ‘cv2‘ has no attribute resize, please install opencv-contrib-python:  
pip install opencv-contrib-python -i https://pypi.tuna.tsinghua.edu.cn/simple
2) if occures warning: 
vscode ctrl+shift+p setting: convert indentation to spaces


### Make 
1) cd build
2) cmake ..
3) make
4) ./bevfusion/modules/image_preprocess/unit_tests/bin/nn_interpol_base_test_exec.out
4) instead 3/4 step: ctest / make test
