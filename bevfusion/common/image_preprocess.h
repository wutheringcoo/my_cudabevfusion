#ifndef BEVFUSION_COMMON_IMAGE_PREPROCESS_H
#define BEVFUSION_COMMON_IMAGE_PREPROCESS_H

#include <cstdint>
namespace bevfusion {
namespace camera {

enum class NormType : std::uint8_t { Nothing = 0U, MeanStd = 1U, AlphaBeta = 2U };
enum class ChannelType : std::uint8_t { Nothing = 0U, Invert = 1U };
enum class InterpolType : std::uint8_t { Nearest = 0U, Bilinear = 1U };

//  shiyong 数组作为形参初始化需要使用memcpy, 否则报错could not convert
//  ‘{2.29000002e-1f, 2.24000007e-1f, 2.24999994e-1f}’ from ‘<brace-enclosed initializer list>’ to ‘const float*’
class NormParams {
public:
    NormParams(
        // Image Resize
        const std::uint32_t src_image_width = 1600U,
        const std::uint32_t src_image_height = 900U,
        const std::uint32_t num_cameras = 6U,
        const std::uint32_t dst_image_width = 768U,  // resize_ratio=0.48
        const std::uint32_t dst_image_height = 432U,
        const std::uint32_t dst_image_channel = 3U,
        const float resize_scale = 0.48F,
        const InterpolType &interpolation = InterpolType::Bilinear,

        // Image Normalization
        const float mean_r = 0.485F,
        const float mean_g = 0.456F,
        const float mean_b = 0.406F,

        const float std_r = 0.229F,
        const float std_g = 0.224F,
        const float std_b = 0.225F,

        /// @brief Image Normalization Scale: 1.f/255.
        const float alpha = 1 / 255.0F,

        /// @brief Image Normalization bias: 0.f.
        float beta = 0.0F,

        const NormType &normtype = NormType::MeanStd,

        /// @brief Whether to inverse C channel or not.
        const ChannelType &channel_type = ChannelType::Nothing);

public:
    const std::uint32_t src_image_width;

    const std::uint32_t src_image_height;

    const std::uint32_t num_cameras;

    const std::uint32_t dst_image_width;

    const std::uint32_t dst_image_height;

    const std::uint32_t dst_image_channel;

    const float resize_scale;

    const InterpolType &interpolation;

    const float mean_r;

    const float mean_g;

    const float mean_b;

    const float std_r;

    const float std_g;

    const float std_b;

    const float alpha;

    float beta;

    const NormType &normtype;

    const ChannelType &channel_type;
};

}  // namespace camera
}  // namespace bevfusion

#endif  // BEVFUSION_COMMON_IMAGE_PREPROCESS_H
