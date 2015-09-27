#include <iostream>
#include <string>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <conio.h>
#include <Windows.h>

std::string path = "E:/kushal_Main/rtes/embeddedDsp/code/matlab";
std::string filename = path + "/img2.bmp";
std::string outDir = "E:/kushal_Main/rtes/embeddedDsp/code/opencv";

int regionGrowing(const cv::Mat& img, int seed_x, int seed_y, int T, cv::Mat& segImg);

int main()
{
   cv::Mat img = cv::imread(filename,-1);
   cv::Mat segImg = cv::Mat::ones(cv::Size(img.cols, img.rows),CV_8UC1);
   int x = 114;
   int y = 370;
   int T = 7;
   //int start_s = clock();
   LARGE_INTEGER start, finish, freq;
   QueryPerformanceFrequency(&freq);
   QueryPerformanceCounter(&start);
   int number_of_pixels = regionGrowing(img, x, y, T, segImg);
   QueryPerformanceCounter(&finish);

   //int stop_s = clock();
   //std::cout<< "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << std::endl;
   std::cout<< "Execution time: " << (1000*(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart) <<" millisec"<<std::endl;
   std::cout<<"Number of pixels = "<<number_of_pixels;
   std::string outFile = outDir + "/segImg.bmp";
   cv::imwrite(outFile,segImg);

   cv::namedWindow("OutImg");
   cv::imshow("OutImg", segImg);
   cv::waitKey(0);
   return 0;
}

int regionGrowing(const cv::Mat& img, int seed_x, int seed_y, int T, cv::Mat& segImg)
{
   cv::Mat tmpImg = cv::Mat::ones(cv::Size(img.cols, img.rows),CV_8UC1);
   cv::medianBlur(img, tmpImg, 3);
   // make all the initial values as 255
   unsigned char* segData =  segImg.data;
   unsigned char* imgData =  img.data;
   int wdt = segImg.cols;
   int ht = segImg.rows;
   segImg *=255;
   int neigb [] =  { -1, -1, 
                     -1,  0,
                     -1,  1,
                      1, -1,
                      1,  0,
                      1,  1,
                      0, -1,
                      0,  1}; 
   // Start region growing. if pixel meets the threshold criterion add it to the
   // region
   int x = seed_x;
   int y = seed_y;
   int no_of_pixels = 1;
   int count = 0;
   int sum_segmented_pixels = *(imgData+seed_y*wdt+seed_x);
   *(segData+seed_y*wdt+seed_x) = 0;
   int* x_arr = new int [wdt*ht];
   int* y_arr = new int [wdt*ht];
   x_arr[0] = x;
   y_arr[0] = y;
   int M = *(imgData+seed_y*wdt+seed_x);
   while(count<no_of_pixels)
   {
      for (int j=0;j<16;j+=2)
      {
         int xn = x_arr[count] + neigb[j+0];
         int yn = y_arr[count] + neigb[j+1];

         bool flag =  ((xn>=0) && (yn>=0) && (xn<wdt) && (yn<ht));
         if (flag)
         {
            int diff = std::abs(*(imgData+yn*wdt+xn) - M);
            if ((diff<T) && (*(segData+yn*wdt+xn) == 255))
            {
               x_arr[no_of_pixels] = xn;
               y_arr[no_of_pixels] = yn;
               no_of_pixels +=1;
               *(segData+yn*wdt+xn) = 0;
               sum_segmented_pixels += *(imgData+yn*wdt+xn);
            }
         }
      }

       M = sum_segmented_pixels / no_of_pixels;
       count += 1;
   }

   return no_of_pixels;
}