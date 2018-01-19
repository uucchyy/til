
### 画像の読み込み

cv::imreadで読み込む。第1引数が画像パス。第2引数が読み込みモード。
読み込みモードには以下が用意されている。

	enum  	cv::ImreadModes { 
	  cv::IMREAD_UNCHANGED = -1, 
	  cv::IMREAD_GRAYSCALE = 0, 
	  cv::IMREAD_COLOR = 1, 
	  cv::IMREAD_ANYDEPTH = 2, 
	  cv::IMREAD_ANYCOLOR = 4, 
	  cv::IMREAD_LOAD_GDAL = 8, 
	  cv::IMREAD_REDUCED_GRAYSCALE_2 = 16, 
	  cv::IMREAD_REDUCED_COLOR_2 = 17, 
	  cv::IMREAD_REDUCED_GRAYSCALE_4 = 32, 
	  cv::IMREAD_REDUCED_COLOR_4 = 33, 
	  cv::IMREAD_REDUCED_GRAYSCALE_8 = 64, 
	  cv::IMREAD_REDUCED_COLOR_8 = 65, 
	  cv::IMREAD_IGNORE_ORIENTATION = 128 
	}

##### MREAD_UNCHANGED 
If set, return the loaded image as is (with alpha channel, otherwise it gets cropped).
そのまま読み込む。（アルファチャンネルはトリミング）

##### IMREAD_GRAYSCALE 
If set, always convert image to the single channel grayscale image.
シングルチャンネルグレースケールで読み込む。

##### IMREAD_COLOR 
If set, always convert image to the 3 channel BGR color image.
3チャンネルのBGRカラーで読み込む。

##### IMREAD_ANYDEPTH 
If set, return 16-bit/32-bit image when the input has the corresponding depth, otherwise convert it to 8-bit.

##### IMREAD_ANYCOLOR 
If set, the image is read in any possible color format.
可能なカラーで読み込む（？）

##### IMREAD_LOAD_GDAL 
If set, use the gdal driver for loading the image.
gdalドライバを使って画像を読み込む（？）

##### IMREAD_REDUCED_GRAYSCALE_2 
If set, always convert image to the single channel grayscale image and the image size reduced 1/2.
シングルチャンネルグレースケールで読み込み、画像サイズを1/2に縮小する。

##### IMREAD_REDUCED_COLOR_2 
If set, always convert image to the 3 channel BGR color image and the image size reduced 1/2.
3チャンネルのBGRカラーで読み込み、画像サイズを1/2に縮小する。

##### IMREAD_REDUCED_GRAYSCALE_4 
If set, always convert image to the single channel grayscale image and the image size reduced 1/4.
シングルチャンネルグレースケールで読み込み、画像サイズを1/4に縮小する。

##### IMREAD_REDUCED_COLOR_4 
If set, always convert image to the 3 channel BGR color image and the image size reduced 1/4.
3チャンネルのBGRカラーで読み込み、画像サイズを1/4に縮小する。

##### IMREAD_REDUCED_GRAYSCALE_8 
If set, always convert image to the single channel grayscale image and the image size reduced 1/8.
シングルチャンネルグレースケールで読み込み、画像サイズを1/8に縮小する。

##### IMREAD_REDUCED_COLOR_8 
If set, always convert image to the 3 channel BGR color image and the image size reduced 1/8.
3チャンネルのBGRカラーで読み込み、画像サイズを1/8に縮小する。

##### IMREAD_IGNORE_ORIENTATION 
If set, do not rotate the image according to EXIF's orientation flag.
EXIFの orientation flag によって回転しないで読み込む。


### test code

```C++
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, const char* argv[]) {

   cv::Mat image = cv::imread("data.jpg" , 0);
   if (image.empty()) {
      std::cout << "read error.\n";
      return -1;
   }

   cv::imwrite("output.jpg" , image);

   return 0;
}
```
