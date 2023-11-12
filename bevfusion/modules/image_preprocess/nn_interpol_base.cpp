#include "bevfusion/modules/image_preprocess/nn_interpol_base.h"
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
        for (int i = 0; i < dst_h_; ++i) {
            for (int j = 0; j < dst_w_; ++j) {
                for (int k = 0; k < dst_c_; ++k) {
                    int src_y = i / yscale_;
                    int src_x = j / xscale_;
                    dst_img[n * dst_h_ * dst_w_ * dst_c_ + i * dst_w_ * dst_c_ + j * dst_c_ + k] =
                        src_img[n * src_h_ * src_w_ * dst_c_ + src_y * src_w_ * dst_c_ + src_x * dst_c_ + k];
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