#include <fstream>
#include <memory>
#include <iostream>
#include <stdint.h>  //std::uint8_t

// file.read([读取到指定buff内存的指针，该指针需要强制转换成char*] , [字节数]） 需要再次确认下是字节数还是长度
// file.read(img, sizeof(std::uint8_t *) * byte_size);
// error: invalid conversion from ‘uint8_t*’ {aka ‘unsigned char*’} to ‘std::basic_istream<char>::char_type*’
//  这个错误提示的是类型转换错误，你试图将 uint8_t*（也就是 unsigned char*）类型的指针转换为
// std::basic_istream<char>::char_type* 类型，但这是不允许的
// std::basic_istream<char>::char_type* 是流输入的字符类型

int main() {
    std::ifstream src_file("src_img.bin", std::ios::binary);
    std::ifstream dst_file("dst_img.bin", std::ios::binary);

    if (!(src_file && dst_file)) {
        std::cerr << "Unable to open file\n";
        return 1;
    }

    int src_byte_size = 2 * 1020 * 1920 * 3;
    int dst_byte_size = 2 * 510 * 960 * 3;
    std::uint8_t *src_img = (std::uint8_t *)malloc(src_byte_size * sizeof(std::uint8_t));
    std::uint8_t *expected_dst_img = (std::uint8_t *)malloc(dst_byte_size * sizeof(std::uint8_t));
    src_file.read(reinterpret_cast<char *>(src_img), sizeof(std::uint8_t *) * src_byte_size);
    dst_file.read(reinterpret_cast<char *>(expected_dst_img), sizeof(std::uint8_t *) * dst_byte_size);
    src_file.close();
    dst_file.close();

    std::cout << (unsigned int)src_img[0] << " " << (unsigned int)src_img[1] << " " << (unsigned int)src_img[2] << " "
              << (unsigned int)src_img[3] << " " << (unsigned int)src_img[4] << std::endl;

    std::cout << (unsigned int)src_img[5875200 - 5] << " " << (unsigned int)src_img[5875200 - 4] << " "
              << (unsigned int)src_img[5875200 - 3] << " " << (unsigned int)src_img[5875200 - 2] << " "
              << (unsigned int)src_img[5875200 - 1] << std::endl;

    delete src_img, expected_dst_img;
    src_img, expected_dst_img = nullptr, nullptr;

    return 0;
}