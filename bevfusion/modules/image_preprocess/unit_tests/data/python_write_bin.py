import matplotlib.pyplot as plt
import numpy as np
import struct
import cv2

# src
img = cv2.imread("1616344634199.jpg")
img2 = cv2.imread("1616617746999.jpg")

img_mosaic = np.stack([img, img2], axis=0)
byte_size1 = (
    img_mosaic.shape[0]
    * img_mosaic.shape[1]
    * img_mosaic.shape[2]
    * img_mosaic.shape[3]
)

# dst
img_resize = cv2.resize(
    src=img,
    dsize=(int(img.shape[1] / 2), int(img.shape[0] / 2)),
    interpolation=cv2.INTER_NEAREST,
)
img2_resize = cv2.resize(
    src=img2,
    dsize=(int(img2.shape[1] / 2), int(img2.shape[0] / 2)),
    interpolation=cv2.INTER_NEAREST,
)
img_resize_mosaic = np.stack(
    [img_resize, img2_resize], axis=0
)  # (N, H, W, C) [2, 510, 960, 3]
byte_size2 = (
    img_resize_mosaic.shape[0]
    * img_resize_mosaic.shape[1]
    * img_resize_mosaic.shape[2]
    * img_resize_mosaic.shape[3]
)


src_img_bin = struct.pack("B" * byte_size1, *img_mosaic.flatten())  # B for usigned char
dst_img_bin = struct.pack(
    "B" * byte_size2, *img_resize_mosaic.flatten()
)  # B for usigned char


with open("src_img.bin", "wb") as f:
    f.write(src_img_bin)

with open("dst_img.bin", "wb") as f:
    f.write(dst_img_bin)


### test img1 resize

H, W, C = img_resize.shape
dst_self = np.zeros([H, W, 3], dtype="uint8")
for c in range(C):
    for i in range(W):
        for j in range(H):
            x = (img.shape[1] / W) * i + 1e-5
            y = (img.shape[0] / H) * j + 1e-5
            dst_self[j, i, c] = img[int(y), int(x), c]
# cv2.imshow("dst_self", dst_self)
# cv2.waitKey(0)

print(np.abs(dst_self - img_resize).max())  # 保证一致性
# print(np.abs(dst_self - img_resize))


plt.imshow(img)
plt.show()
plt.imshow(img2)
plt.show()
plt.imshow(img_resize)
plt.show()
plt.imshow(img2_resize)
plt.show()


# cd  bevfusion/modules/image_preprocess/unit_tests/data/
# python python_write_bin.py
