#include "bevfusion/common/image_preprocess.h"

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