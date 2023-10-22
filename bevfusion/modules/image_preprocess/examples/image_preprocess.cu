/*
input:

Todolists:
1) C++ Implementation Of Nearest Interpolation/ Cuda Implementation/ Python Implementation
2)  Consistency verification  above
*/
#define cuda_2d_launch(kernel, stream, nx, ny, nz, ...)                          \
    do {                                                                         \
        dim3 __threads__(32, 32);                                                \
        dim3 __blocks__(divup(nx, 32), divup(ny, 32), nz);                       \
        kernel<<<__blocks__, __threads__, 0, stream>>>(nx, ny, nz, __VA_ARGS__); \
        nv::check_runtime(cudaPeekAtLastError(), #kernel, __LINE__, __FILE__);   \
    } while (false)
#endif  // CUDA_DEBUG
}
;       // namespace nv#define cuda_2d_launch(kernel, stream, nx, ny, nz, ...)                      \
  do {                                                                       \
    dim3 __threads__(32, 32);                                                \
    dim3 __blocks__(divup(nx, 32), divup(ny, 32), nz);                       \
    kernel<<<__blocks__, __threads__, 0, stream>>>(nx, ny, nz, __VA_ARGS__); \
    nv::check_runtime(cudaPeekAtLastError(), #kernel, __LINE__, __FILE__);   \
  } while (false)
#endif  // CUDA_DEBUG
}
;  // namespace nv

cuda_2d_launch(
    normalize_to_planar_kernel_function,
    _stream,
    param_.output_width,
    param_.output_height,
    param_.num_camera,
    sx_,
    sy_,
    crop_x_,
    crop_y_,
    reinterpret_cast<uchar3*>(raw_images_),
    param_.image_width,
    param_.image_height,
    normalize_images_,
    param_.method);

template <NormType norm_type, Interpolation interpolation, typename OutputType>
static __global__ void normalize_to_planar_kernel(
    int nx,
    int ny,
    int nz,
    float sx,
    float sy,
    int crop_x,
    int crop_y,
    uchar3* imgs,
    int image_width,
    int image_height,
    void* output,
    NormMethod method) {
    int ix = cuda_2d_x;
    int iy = cuda_2d_y;
    if (ix >= nx || iy >= ny)
        return;

    int icamera = blockIdx.z;
    uchar3* img = imgs + image_width * image_height * icamera;
    uchar3 pixel = load_pixel<interpolation>(img, ix, iy, crop_x, crop_y, sx, sy, image_width, image_height);

    if (method.channel_type == ChannelType::Invert) {
        unsigned char t = pixel.z;
        pixel.z = pixel.x;
        pixel.x = t;
    }

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