#ifndef BEVFUSION_COMMON_BEVFUSION_PARAMS_H
#define BEVFUSION_COMMON_BEVFUSION_PARAMS_H

// #include "bevfusion/common/image_preprocess.h"
#include "image_preprocess.h"

namespace bevfusion {
namespace camera {
class BevFusionParams {
public:
    BevFusionParams(const NormParams normparams);
    bool IsParamsValid() const;

public:
    const NormParams normparams;
};
}  // namespace camera
}  // namespace bevfusion

#endif  // BEVFUSION_COMMON_BEVFUSION_PARAMS_H
