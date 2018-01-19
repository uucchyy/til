
### link
[Installation in Linux](https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html)   
[source](https://opencv.org/releases.html)

---

### install

```shell
# sudo apt-get install build-essential
# sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
# sudo apt-get install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev

# cd /usr/local/src
# wget https://github.com/opencv/opencv/archive/3.4.0.zip
# unzip 3.4.0.zip
# cd opencv-3.4.0/
# mkdir build
# cd build/

# cmake -D CMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX=/usr/local ..
# CMAKE_BUILD_TYPE=Release\Debug
# make -j7 
# sudo make install

# echo /usr/local/lib > /etc/ld.so.conf.d/opencv.conf
# ldconfig -v
```

---

### sample

```C++
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, const char* argv[]) {
   std::cout << "start -- \n";

   cv::Mat image = cv::imread("data.jpg" , 0);
   if (image.empty()) {
      std::cout << "read error.\n";
      return -1;
   }

   std::cout << image.rows ;

   std::cout << "\nend -- \n";
   return 0;
}
```

---

### build

```shell
g++ -o test test.cpp -I/usr/local/include/opencv2 -I/usr/local/include/opencv -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui
```

