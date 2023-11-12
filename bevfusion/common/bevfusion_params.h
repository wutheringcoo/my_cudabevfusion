#ifndef BEVFUSION_COMMON_BEVFUSION_PARAMS_H
#define BEVFUSION_COMMON_BEVFUSION_PARAMS_H

// #include "bevfusion/common/image_preprocess.h"
#include "image_preprocess.h"

namespace bevfusion {
namespace camera {
class BevFusionParams {
public:
    BevFusionParams(const ImgPreprocess &imgpreprocess_params);
    bool IsParamsValid() const;

public:
    // const NormParams normparams_; 这种带入struct的表达容易出问题
    const ImgPreprocess imgpreprocess_params;
};
}  // namespace camera
}  // namespace bevfusion

#endif  // BEVFUSION_COMMON_BEVFUSION_PARAMS_H
