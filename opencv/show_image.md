
## 画像の表示
画像の表示はcv::Matオブジェクトをcv::imshow関数に渡す。

https://docs.opencv.org/3.4.0/d7/dfc/group__highgui.html#ga453d42fe4cb60e5723281a89973ee563


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

   cv::imshow("Show image", image);
   // waitKeyを呼ばないとウィンドウが瞬時に消える
   // 引数0は何かキーを押すと消える、数値を入れるとms後に消える
   cv::waitKey(0);

   return 0;
}
```
