#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    int src_height = 4;
    int src_width = 4;
    unsigned char img_arr[] = {20, 50, 80, 160, 110, 140, 170, 244, 200, 230, 255, 215, 1, 2, 3, 4};
    unsigned char* img = img_arr;

    int height = 3;  // dst
    int width = 3;
    unsigned char* img_resize = (unsigned char*)malloc(height * width * 1 * sizeof(unsigned char*));
    if (img_resize == NULL) {
        printf("memory allocate failed\n");
        return 0;
    }

    float scale_y = static_cast<float>(height) / src_height;  //=3/4
    float scale_x = static_cast<float>(width) / src_width;    //=3/4

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int src_y = i / scale_y;
            int src_x = j / scale_x;
            img_resize[i * width + j] = img[src_y * src_width + src_x];
            cout << i * width << " " << j << " " << static_cast<int>(img[src_y * src_width + src_x]) << endl;
        }
    }
    free(img_resize);
    img_resize = NULL;

    return 0;
}
