#include "bevfusion/common/bevfusion_params.h"
// #include "bevfusion/common/image_preprocess.h"

namespace bevfusion {
namespace camera {

class NearestNeighborInterpol {
public:
    NearestNeighborInterpol(const BevFusionParams& params);
    unsigned char* forward(const unsigned char* src_img, unsigned char* dst_img);

private:
    const BevFusionParams& params_;
    const int src_w_;
    const int src_h_;
    const int dst_w_;
    const int dst_h_;
    const int dst_c_;

    /// @brief  Dst image width / Src image width.
    const float xscale_ = 1.0f;

    /// @brief  Dst image height / Src image height.
    const float yscale_ = 1.0f;
    const unsigned char* src_img_ = nullptr;
    unsigned char* dst_img_ = nullptr;
};

}  // namespace camera
}  // namespace bevfusion
