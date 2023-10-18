#ifndef BC795D66_F82A_44B2_90D1_59C3AE504E01
#define BC795D66_F82A_44B2_90D1_59C3AE504E01
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

#endif /* BC795D66_F82A_44B2_90D1_59C3AE504E01 */
