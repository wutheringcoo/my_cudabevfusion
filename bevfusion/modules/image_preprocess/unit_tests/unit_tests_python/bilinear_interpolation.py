import cv2
import pytest
import numpy as np
import matplotlib.pyplot as plt


def test_bilinear():
    def BiLinearInterPolation(img, dstH, dstW, dstC):
        H, W, _ = img.shape
        dstimg = np.zeros((dstH, dstW, dstC), dtype=np.uint8)
        for h in range(dstH):
            for w in range(dstW):
                for c in range(dstC):
                    x = (w + 0.5) * (W / dstW) - 0.5
                    y = (h + 0.5) * (H / dstH) - 0.5

                    x1 = int(x)
                    y1 = int(y)
                    u = x - x1
                    v = y - y1
                    dstimg[h, w, c] = (
                        (1 - u) * (1 - v) * img[y1, x1, c]  # Q11
                        + (1 - u) * v * img[y1 + 1, x1, c]  # Q12
                        + u * (1 - v) * img[y1, x1 + 1, c]  # Q21
                        + u * v * img[y1 + 1, x1 + 1, c]  # Q22
                    )
        # plt.imshow(dstimg[..., ::-1])
        # plt.show()

        return dstimg

    # src
    img = cv2.imread("../data/1616344634199.jpg")
    dstH = int(img.shape[0] / 2)
    dstW = int(img.shape[1] / 2)
    dstC = img.shape[2]

    # method1  opencv api
    dst_img = cv2.resize(
        src=img,
        dsize=(int(dstW), int(dstH)),
        interpolation=cv2.INTER_LINEAR,
    )

    dst_img2 = BiLinearInterPolation(img, dstH, dstW, dstC)

    print("max_error=", np.abs(dst_img - dst_img2).max())


if __name__ == "__main__":
    pytest.main(["-s", "-v", "bilinear_interpolation.py"])
