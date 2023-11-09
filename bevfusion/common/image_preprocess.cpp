#include "image_preprocess.h"
#include <stdio.h>
namespace bevfusion {
namespace camera {

NormParams::NormParams(
    const std::uint32_t src_image_width,
    const std::uint32_t src_image_height,
    const std::uint32_t num_cameras,
    const std::uint32_t dst_image_width,
    const std::uint32_t dst_image_height,
    const std::uint32_t dst_image_channel,
    const float resize_scale,
    const InterpolType &interpolation,
    const float mean_r,
    const float mean_g,
    const float mean_b,
    const float std_r,
    const float std_g,
    const float std_b,
    const float alpha,
    float beta,
    const NormType &normtype,
    const ChannelType &channel_type) :
        src_image_width(src_image_width),
        src_image_height(src_image_height),
        num_cameras(num_cameras),
        dst_image_width(dst_image_width),
        dst_image_height(dst_image_height),
        dst_image_channel(dst_image_channel),
        resize_scale(resize_scale),
        interpolation(interpolation),
        mean_r(mean_r),
        mean_g(mean_g),
        mean_b(mean_b),
        std_r(std_r),
        std_g(std_g),
        std_b(std_b),
        alpha(alpha),
        beta(beta),
        normtype(normtype),
        channel_type(channel_type) {
    printf("NormParams Initialization.");
}

}  // namespace camera
}  // namespace bevfusion