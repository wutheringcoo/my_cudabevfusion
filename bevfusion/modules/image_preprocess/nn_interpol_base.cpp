#include "bevfusion/modules/image_preprocess/nn_interpol_base.h"
#include <stdio.h>
namespace bevfusion {
namespace camera {
// copy  const variable a to const variable b by constructor initialization list.
NearestNeighborInterpol::NearestNeighborInterpol(const BevFusionParams& params) :
        params_(params),
        src_w_(params_.normparams.resizeparams.src_image_width),
        src_h_(params_.normparams.resizeparams.src_image_height),
        dst_w_(params_.normparams.resizeparams.dst_image_width),
        dst_h_(params_.normparams.resizeparams.dst_image_height),
        xscale_(params_.normparams.resizeparams.resize_scale),
        yscale_(params_.normparams.resizeparams.resize_scale) {
    printf("NearestNeighborInterpol Construct Success.");
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