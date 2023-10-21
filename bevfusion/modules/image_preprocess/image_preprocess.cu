/*
input:

Todolists:
1) C++ Implementation Of Nearest Interpolation/ Cuda Implementation/ Python Implementation
2)  Consistency verification  above
*/

template <>
__device__ uchar3 load_pixel<Interpolation::Nearest>(
    const uchar3* image,  // src_image
    int x,                // dst_x
    int y,
    int tox,
    int toy,
    float sx,
    float sy,
    int width,
    int height) {
    // In some cases, the floating point precision will lead to miscalculation of the value,
    // making the result not exactly match with opencv,
    // so here you need to add eps as precision compensation
    //
    // A special case is when the input is 3840 and the output is 446, x = 223:
    // const int src_x_double = 223.0  * (3840.0  / 446.0);            // -> 1920
    // const int src_x_float  = 223.0f * (3840.0f / 446.0f);           // -> 1919
    // const int src_x_float  = 223.0f * (3840.0f / 446.0f) + 1e-5;    // -> 1920
    //
    // !!! If you want to use the double for sx/sy, you'll get a 2x speed drop
    const float eps = 1e-5;
    int ix = (x + tox) * sx + eps;
    int iy = (y + toy) * sy + eps;
    return image[iy * width + ix];
}
