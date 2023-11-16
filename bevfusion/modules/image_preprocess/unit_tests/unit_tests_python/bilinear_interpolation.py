import cv2
import pytest
import numpy as np
import matplotlib.pyplot as plt


# src
img = cv2.imread("../data/1616344634199.jpg")
W = int(img.shape[1] / 2)
H = int(img.shape[0] / 2)

# dst
img_dst = cv2.resize(
    src=img,
    dsize=(int(img.shape[1] / 2), int(img.shape[0] / 2)),
    interpolation=cv2.INTER_LINEAR,
)


def BiLinearInterPolation(img, dstH, dstW):
    scrH, scrW, _ = img.shape
    img = np.pad(img, ((0, 1), (0, 1), (0, 0)), "constant")
    retimg = np.zeros((dstH, dstW, 3), dtype=np.uint8)
    for i in range(dstH):
        for j in range(dstW):
            scrx = (i + 1) * (scrH / dstH) - 1
            scry = (j + 1) * (scrW / dstW) - 1
            x = math.floor(scrx)
            y = math.floor(scry)
            u = scrx - x
            v = scry - y
            retimg[i, j] = (
                (1 - u) * (1 - v) * img[x, y]
                + u * (1 - v) * img[x + 1, y]
                + (1 - u) * v * img[x, y + 1]
                + u * v * img[x + 1, y + 1]
            )
    return retimg
