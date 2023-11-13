#include "nn_interpol_base.h"
#include <stdio.h>
#include <iostream>
using namespace std;
namespace bevfusion {
namespace camera {
// copy  const variable a to const variable b by constructor initialization list.
NearestNeighborInterpol::NearestNeighborInterpol(const BevFusionParams& params) :
        params_(params),
        src_w_(params_.imgpreprocess_params.src_image_width),
        src_h_(params_.imgpreprocess_params.src_image_height),
        dst_n_(params_.imgpreprocess_params.num_cameras),
        dst_w_(params_.imgpreprocess_params.dst_image_width),
        dst_h_(params_.imgpreprocess_params.dst_image_height),
        dst_c_(params_.imgpreprocess_params.dst_image_channel),
        xscale_(params_.imgpreprocess_params.resize_scale),
        yscale_(params_.imgpreprocess_params.resize_scale) {
    printf("NearestNeighborInterpol Construct Success.");
}

void NearestNeighborInterpol::forward(const unsigned char* src_img, unsigned char* dst_img) {
    //
    for (int n = 0; n < dst_n_; ++n) {
        for (int h = 0; h < dst_h_; ++h) {
            for (int w = 0; w < dst_w_; ++w) {
                for (int c = 0; c < dst_c_; ++c) {
                    int y = h / yscale_;
                    int x = w / xscale_;
                    dst_img[n * dst_h_ * dst_w_ * dst_c_ + h * dst_w_ * dst_c_ + w * dst_c_ + c] =
                        src_img[n * src_h_ * src_w_ * dst_c_ + y * src_w_ * dst_c_ + x * dst_c_ + c];
                    // cout << i * width << " " << j << " " << static_cast<int>(img[src_y * src_width + src_x]) << endl;
                }
            }
        }
    }
}
}  // namespace camera
}  // namespace bevfusion

// unsigned char* img_resize = (unsigned char*)malloc(height * width * 1 * sizeof(unsigned char*));
// if (img_resize == NULL) {
//     printf("memory allocate failed\n");
//     return 0;
// }

// float scale_y = static_cast<float>(height) / src_height;  //=3/4
// float scale_x = static_cast<float>(width) / src_width;    //=3/4

// for (int i = 0; i < height; ++i) {
//     for (int j = 0; j < width; ++j) {
//         int src_y = i / scale_y;
//         int src_x = j / scale_x;
//         img_resize[i * width + j] = img[src_y * src_width + src_x];
//         cout << i * width << " " << j << " " << static_cast<int>(img[src_y * src_width + src_x]) << endl;
//     }
// }