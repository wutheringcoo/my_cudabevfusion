// #include "bevfusion/common/bevfusion_params.h"
#include "bevfusion_params.h"
#include <stdio.h>
namespace bevfusion {
namespace camera {

BevFusionParams::BevFusionParams(const NormParams &normparams) : normparams_(normparams) {
    printf("BevFusionParams Initialization.");
}

bool BevFusionParams::IsParamsValid() const {
    printf("BevFusionParams is Valid ");
    return true;
}

}  // namespace camera
}  // namespace bevfusion