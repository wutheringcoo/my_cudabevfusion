import cv2
import numpy as np

"""
We need to use int not round to keep the same result from cv2 with self impl.
"""


def nn_interpolate_slow(img: np.ndarray, scale: float):
    """Assume the H=W, image with 1 channel, so
    scale: dst_img[H/W] / src_img[H/W]
    """
    height, width = img.shape
    dst_height = int(height * scale)
    dst_width = int(width * scale)

    dst_img = np.zeros((dst_height, dst_width))

    for i in range(dst_height):
        for j in range(dst_width):
            # dst_img[i, j] = img[round((i) / scale), round((j) / scale)]
            dst_img[i, j] = img[int((i) / scale), int((j) / scale)]
    return np.uint8(dst_img)


def nn_interpolate(img, DST_W=3, DST_H=3):
    H, W = img.shape
    scale_x = DST_W / W
    scale_y = DST_H / H

    y = np.arange(DST_H).repeat(DST_W).reshape(DST_H, -1)
    x = np.tile(np.arange(DST_W), (DST_H, 1))
    # src_y = np.round(y / scale_y).astype(np.int64)
    # src_x = np.round(x / scale_x).astype(np.int64)
    src_y = (y / scale_y).astype(np.int64)
    src_x = (x / scale_x).astype(np.int64)
    img_dst = img[src_y, src_x]
    return img_dst.astype(np.uint8)


# 1) without  no grayscale change in the image
image = np.array(
    [[20, 50, 80, 80], [110, 140, 170, 170], [200, 230, 255, 255], [200, 230, 255, 255]]
)
img = cv2.resize(image, (3, 3), interpolation=cv2.INTER_NEAREST)  # type: ignore
print(img)
# output:
# [[ 20  50  80]
#  [110 140 170]
#  [200 230 255]]

# 2) with  no grayscale change in the image
image1 = np.array(
    [[20, 50, 80, 160], [110, 140, 170, 244], [200, 230, 255, 215], [1, 2, 3, 4]]
)
img1 = cv2.resize(image1, (3, 3), interpolation=cv2.INTER_NEAREST)
print(img1)
# output:
# [[ 20  50  80]
#  [110 140 170]
#  [200 230 255]]


img_slow = nn_interpolate_slow(image1, 3 / 4)
print(img_slow)
# [[ 20  50 160]
#  [110 140 244]
#  [  1   2   4]]

img_fast = nn_interpolate(image1)
print(img_fast)
# [[ 20  50 160]
#  [110 140 244]
#  [  1   2   4]]

# 3) random img
img = np.random.randint(low=0, high=256, size=(32, 16))
img_random1 = cv2.resize(src=img, dsize=(11, 22), interpolation=cv2.INTER_NEAREST)
img_random2 = nn_interpolate(img=img, DST_H=22, DST_W=11)
print((img_random1 - img_random2).sum())
img_random3 = nn_interpolate_slow(img=img, scale=22 / 32)
print((img_random1 - img_random3).sum())
