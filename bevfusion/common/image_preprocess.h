namespace bevfusion {
namespace camera {

enum class NormType : int { Nothing = 0, MeanStd = 1, AlphaBeta = 2 };
enum class ChannelType : int { Nothing = 0, Invert = 1 };
enum class InterpolType : int { Nearest = 0, Bilinear = 1 };

struct NormParams {
    float mean[3];
    float std[3];

    /// @brief Image Normalization Scale: 1.f/255.
    float alpha;

    /// @brief Image Normalization bias: 0.f.
    float beta;
    NormType type = NormType::Nothing;
    ChannelType channel_type = ChannelType::Nothing;
    ResizeParams resizeparams;
};

struct ResizeParams {
    const int src_image_width;
    const int src_image_height;
    const int num_cameras;
    const int dst_image_width;
    const int dst_image_height;
    const float resize_scale;
    InterpolType interpolation;
};
}  // namespace camera
}  // namespace bevfusion