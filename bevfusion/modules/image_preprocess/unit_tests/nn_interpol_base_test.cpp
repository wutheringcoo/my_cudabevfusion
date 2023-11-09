
#include <gtest/gtest.h>
#include <iostream>
#include "../common/image_preprocess.h"
#include "../nn_interpol_base.h"
using namespace std;

namespace bevfusion {
namespace camera {

TEST(test1, nn_inter_test) {
    /// 1) set normalization parameters: NormParams
    NormParams norm_param;
    norm_param.type = NormType::MeanStd;

    float mean[3] = {0.485, 0.456, 0.406};
    mempcpy(norm_param.mean, mean, sizeof(mean));

    float std[3] = {0.485, 0.456, 0.406};
    mempcpy(norm_param.std, std, sizeof(std));

    norm_param.alpha = 1 / 255.0F;
    norm_param.beta = 0.0F;

    /// 2) set resize parameters: ResizeParams
    norm_param.resizeparams.src_image_width = 1600;
    norm_param.resizeparams.src_image_height = 900;

    norm_param.num_cameras = 6;
    norm_param.dst_image_width = 800;
    norm_param.dst_image_height = 450;
    norm_param.dst_image_channel = 3;
    norm_param.resize_scale = 1.0F;

    BevFusionParams(norm_param);

    EXPECT_EQ(2, 2);
    cout << "xxxxxx" << endl;
}

}  // namespace camera
}  // namespace bevfusion