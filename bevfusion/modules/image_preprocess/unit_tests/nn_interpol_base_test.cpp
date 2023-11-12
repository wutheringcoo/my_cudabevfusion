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
    ImgPreprocess imgpreprocess_params;

    BevFusionParams bevfusion_params(imgpreprocess_params);

    NearestNeighborInterpol nn_interpol(bevfusion_params);

    /// 2) read src and expected image data.
    std::ifstream src_file("src_img.bin", std::ios::binary);
    std::ifstream dst_file("dst_img.bin", std::ios::binary);

    if (!(src_file && dst_file)) {
        std::cerr << "Unable to open file\n";
    }

    int src_byte_size = 2 * 1020 * 1920 * 3;
    int dst_byte_size = 2 * 510 * 960 * 3;
    std::uint8_t *src_img = (std::uint8_t *)malloc(src_byte_size * sizeof(std::uint8_t));
    std::uint8_t *expected_dst_img = (std::uint8_t *)malloc(dst_byte_size * sizeof(std::uint8_t));
    src_file.read(reinterpret_cast<char *>(src_img), sizeof(std::uint8_t *) * src_byte_size);
    dst_file.read(reinterpret_cast<char *>(expected_dst_img), sizeof(std::uint8_t *) * dst_byte_size);
    src_file.close();
    dst_file.close();

    /// 3) use nearest interpolation interface
    unsigned char *dst_img = (unsigned char *)malloc(dst_byte_size * sizeof(unsigned char *));
    nn_interpol.forward(src_img, dst_img);

    // dst_img =

    EXPECT_EQ(2, 2);
    cout << "xxasa111111111111111111xxxx" << endl;
}

}  // namespace camera
}  // namespace bevfusion