#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
    unsigned char img_arr[] = {20, 50, 80, 160, 110, 140, 170, 244, 200, 230, 255, 215, 1, 2, 3, 4};

    unsigned char* img = img_arr;
    unsigned char* img = (unsigned char*)malloc(4 * 4 * 1 * sizeof(unsigned char*));

    float scale = 3 / 4;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
        }
    }
    // unsigned char* img = (unsigned char*)malloc(4 * 4 * 1 * sizeof(unsigned char*));

    // if (img == NULL) {
    //     printf("memory allocate failed\n");
    //     return 0;
    // }

    // free(img);
    // img = NULL;
    return 0;
}
