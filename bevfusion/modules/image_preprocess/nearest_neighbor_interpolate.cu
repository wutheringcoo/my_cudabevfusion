#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <stdio.h>
// #include <ATen/cuda/CUDAContext.h>
#define THREADS_BLOCK_X   3
#define THREADS_BLOCK_Y   3
#define THREADS_PER_BLOCK THREADS_BLOCK_X *THREADS_BLOCK_Y
#define DIVUP(m, n)       ((m) / (n) + ((m) % (n) > 0))

static __global__ void nearest_neighbor_interpolate_kernel(
    int height_dist,
    int width_dist,
    unsigned char *image_dst,
    float scale_x,
    float scale_y,
    int heigth_src,
    int width_src,
    const unsigned char *image_src) {
    int ix_dist = blockIdx.x * blockDim.x + threadIdx.x;
    int iy_dist = blockIdx.y * blockDim.y + threadIdx.y;
    if (ix_dist >= width_dist || iy_dist >= height_dist)
        return;

    // const float eps = 1e-5;
    int ix_src = ix_dist / scale_x;
    int iy_src = iy_dist / scale_y;
    printf(
        "%d, %d, %f, %d,  %d\n",
        ix_src,
        ix_dist,
        scale_x,
        image_src[iy_src * width_src + ix_src],
        iy_dist * width_dist + ix_dist);

    image_dst[iy_dist * width_dist + ix_dist] = image_src[iy_src * width_src + ix_src];
    printf("*%d, *%d\n", iy_dist * width_dist + ix_dist, image_dst[iy_dist * width_dist + ix_dist]);
}

void nearest_neighbor_interpolate_kernel_launcher(
    cudaStream_t stream,
    int height_dist,
    int width_dist,
    unsigned char *image_dst,
    float scale_x,
    float scale_y,
    int heigth_src,
    int width_src,
    unsigned char *image_src) {
    cudaError_t err;

    dim3 threads(THREADS_BLOCK_X, THREADS_BLOCK_Y);
    dim3 blocks(DIVUP(width_dist, THREADS_BLOCK_X), DIVUP(height_dist, THREADS_BLOCK_Y));

    nearest_neighbor_interpolate_kernel<<<blocks, threads, 0, stream>>>(
        height_dist, width_dist, image_dst, scale_x, scale_y, heigth_src, width_src, image_src);

    err = cudaGetLastError();
    if (cudaSuccess != err) {
        fprintf(stderr, "CUDA kernel failed : %s\n", cudaGetErrorString(err));
        exit(-1);
    }
}

int main() {
    // cudaStream_t stream = at::cuda::getCurrentCUDAStream().stream();
    cudaStream_t stream;
    cudaStreamCreate(&stream);

    int height_dist = 3;  // dst
    int width_dist = 3;
    unsigned char *img_dst_cuda;
    cudaError_t cudaStatus = cudaMalloc((void **)&img_dst_cuda, height_dist * width_dist * 1 * sizeof(unsigned char *));
    if (cudaStatus != cudaSuccess) {
        printf("img dst CudaMalloc failed!");
    }

    int heigth_src = 4;
    int width_src = 4;
    unsigned char img_arr[] = {20, 50, 80, 160, 110, 140, 170, 244, 200, 230, 255, 215, 1, 2, 3, 4};
    unsigned char *img_src = img_arr;
    unsigned char *img_src_cuda;

    float scale_x = static_cast<float>(width_dist) / width_src;
    float scale_y = static_cast<float>(height_dist) / heigth_src;

    cudaError_t cudaStatus2 = cudaMalloc((void **)&img_src_cuda, heigth_src * width_src * 1 * sizeof(unsigned char *));
    if (cudaStatus2 != cudaSuccess) {
        printf("img_src_cuda CudaMalloc failed!");
    }
    cudaMemcpy(img_src_cuda, img_src, heigth_src * width_src * sizeof(unsigned char), cudaMemcpyHostToDevice);

    nearest_neighbor_interpolate_kernel_launcher(
        stream, height_dist, width_dist, img_dst_cuda, scale_x, scale_y, heigth_src, width_src, img_src_cuda);

    unsigned char *img_dst_cpu = (unsigned char *)malloc(height_dist * width_dist * 1 * sizeof(unsigned char *));
    cudaMemcpy(
        img_dst_cpu, img_dst_cuda, height_dist * width_dist * 1 * sizeof(unsigned char *), cudaMemcpyDeviceToHost);

    for (int i = 0; i < height_dist * width_dist; i++) {
        if (i % height_dist == 0) {
            printf("\n");
        }
        printf("--%d ", img_dst_cpu[i]);
    }

    cudaFree(img_dst_cuda);
    cudaFree(img_src_cuda);

    return 0;
}