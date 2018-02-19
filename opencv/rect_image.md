
## 画像の切り抜き

cv::Rectで矩形切り抜きが可能。
始点と終点を指定する。画像データの左上が[0, 0]。
画像データサイズを超えたアクセスはできない。

### test code

```cpp
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, const char* argv[]) {

    cv::Mat image = cv::imread("data.jpg" , 0);
    if (image.empty()) {
       std::cout << "read error.\n";
       return -1;
    }

    cv::Mat roi1(image, cv::Rect(0, 0, 150, 230));
    cv::Mat roi2(image, cv::Rect(0, 0, 250, 290));
    // 画像データのサイズを超えた場合はNG
    // image.rows, image.colsをチェックする
    cv::Mat roi3(image, cv::Rect(0, 0, 1000, 350));

    cv::imshow("Original", image);
    cv::imshow("Roi1", roi1);
    cv::imshow("Roi2", roi2);
    cv::imshow("Roi3", roi3);
    cv::waitKey(0);

    return 0;
}
```
