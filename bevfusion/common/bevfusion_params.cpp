#include "bevfusion/common/bevfusion_params.h"
#include <stdio.h>
namespace bevfusion {
namespace camera {

BevFusionParams::BevFusionParams(const NormParams normparams) : normparams(normparams) {
    printf("BevFusionParams Initialization.");
}

bool BevFusionParams::IsParamsValid() const {
    printf("BevFusionParams is Valid ");
}

}  // namespace camera
}  // namespace bevfusion