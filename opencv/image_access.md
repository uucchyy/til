
## 画素へのアクセス

### test code

```cpp
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, const char* argv[]) {

    int x = 0;
    int y = 0;

    cv::Mat image = cv::imread("data.jpg" , 0);
    if (image.empty()) {
       std::cout << "read error.\n";
       return -1;
    }

    cv::Vec3b bgr = image.at<cv::Vec3b>(0,0);
    printf("%d,%d,%d\n",bgr[0],bgr[1],bgr[2]);

    return 0;
}
```
