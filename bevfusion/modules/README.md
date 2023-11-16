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

cv2.resize(interpolation)
interpolation 表示插值方式，有以下取值。

INTER_NEAREST：最近邻插值
INTER_LINEAR：线性插值（默认）
INTER_AREA：区域插值
INTER_CUBIC：三次样条插值
INTER_LANCZOS4：Lanczos 插值




最近邻插值算法，这是一种最基本、最简单的图像缩放算法，效果也是最不好的，放大后的图像有很严重的马赛克，缩小后的图像有很严重的失真；效果不好的根源就是其简单的最临近插值方法引入了严重的图像失真，比如，当由目标图的坐标反推得到的源图的的坐标是一个浮点数的时候，采用了四舍五入的方法，直接采用了和这个浮点数最接近的象素的值，这种方法是很不科学的，当推得坐标值为 0.75的时候，不应该就简单的取为1，既然是0.75，比1要小0.25 ，比0要大0.75 ,那么目标象素值其实应该根据这个源图中虚拟的点四周的四个真实的点来按照一定的规律计算出来的，这样才能达到更好的缩放效果。
ps.
https://www.cnblogs.com/yssongest/p/5303151.html