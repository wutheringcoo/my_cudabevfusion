#ifndef BEVFUSION_API_BEVFUSION_H
#define BEVFUSION_API_BEVFUSION_H
#include <memory>
namespace bevfusion {
class BevFusion {
public:
private:
    std::shared_ptr<camera::Preprocess> preprocess_;
    std::shared_ptr<camera::GetPixelDepth> pixel_depth_;
    std::shared_ptr<camera::CameraEncoder> camera_encoder_;
    std::shared_ptr<camera::Geometry> geometry_;
    std::shared_ptr<camera::BevPooling> bev_pooling_;
    std::shared_ptr<lidar::SCN> lidar_scn_;
    std::shared_ptr<fuser::BevEncoder> bev_encoder_;
    std::shared_ptr<head::TransFormerHead> transformer_head_;
}

}  // namespace bevfusion

#endif  // BEVFUSION_API_BEVFUSION_H
