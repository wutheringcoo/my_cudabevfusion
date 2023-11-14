#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include "../common/bevfusion_params.h"
#include "../common/image_preprocess.h"
#include "../nn_interpol_base.h"
using namespace std;

namespace bevfusion {
namespace camera {

TEST(test1, nn_inter_test) {
    /// 1) set imgpreprocess  parameters: ImgPreprocess
    ImgPreprocess imgpreprocess_params(
        1920U,
        1020U,
        2U,
        960U,
        510U,
        3U,
        0.5F,
        InterpolType::Nearest,
        0.485F,
        0.456F,
        0.406F,
        0.229F,
        0.224F,
        0.225F,
        1 / 255.0F,
        0.0F,
        NormType::MeanStd,
        ChannelType::Nothing);

    BevFusionParams bevfusion_params(imgpreprocess_params);

    NearestNeighborInterpol nn_interpol(bevfusion_params);

    /// 2) read src and expected image data.
    std::ifstream src_file("bevfusion/modules/image_preprocess/unit_tests/data/src_img.bin", std::ios::binary);
    std::ifstream dst_file("bevfusion/modules/image_preprocess/unit_tests/data/dst_img.bin", std::ios::binary);

    if (!(src_file && dst_file)) {
        std::cerr << "Unable to open file....!\n";
    }
    // std::cout << "1\n" << std::endl;
    int src_byte_size = 2 * 1020 * 1920 * 3;
    int dst_byte_size = 2 * 510 * 960 * 3;
    std::uint8_t *src_img = (std::uint8_t *)malloc(src_byte_size * sizeof(std::uint8_t));
    std::uint8_t *expected_dst_img = (std::uint8_t *)malloc(dst_byte_size * sizeof(std::uint8_t));
    src_file.read(reinterpret_cast<char *>(src_img), sizeof(std::uint8_t *) * src_byte_size);
    dst_file.read(reinterpret_cast<char *>(expected_dst_img), sizeof(std::uint8_t *) * dst_byte_size);
    src_file.close();
    dst_file.close();
    // std::cout << "2\n" << std::endl;

    /// 3) use nearest interpolation interface
    unsigned char *dst_img = (unsigned char *)malloc(dst_byte_size * sizeof(unsigned char *));
    // std::cout << "2\n" << std::endl;
    nn_interpol.forward(src_img, dst_img);
    // std::cout << "3\n" << std::endl;

    int max_error = 0;
    for (int i = 0; i < dst_byte_size; i++) {
        max_error = std::max(std::abs(expected_dst_img[i] - dst_img[i]), max_error);
        // std::cout << static_cast<int>(expected_dst_img[i]) << " v.s." << static_cast<int>(dst_img[i]) << std::endl;
    }
    nn_interpol.print();

    cout << "\nmax_error=" << max_error << endl;
    EXPECT_EQ(max_error, 0);
}

}  // namespace camera
}  // namespace bevfusion