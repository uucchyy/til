
## 画像の書き込み

### test code

```cpp
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, const char* argv[]) {

    // 300*300 要素が123の画像を表示
    cv::Mat image = cv::Mat::ones(300,300,CV_8U) * 123;
    cv::imshow("image", image);
    cv::waitKey(0);

    // 300*300 要素がすべて0の画像を表示
    cv::Mat image2 = cv::Mat::zeros(cv::Size(300,300), CV_8U);
    cv::imshow("image2", image2);
    cv::waitKey(0);

    // 保存
    imwrite("testimage.jpg", image);

    return 0;
}
```
