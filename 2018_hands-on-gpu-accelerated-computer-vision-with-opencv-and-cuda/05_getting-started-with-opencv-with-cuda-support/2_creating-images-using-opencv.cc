#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
 // Create blank black grayscale Image with size 256x256
 const cv::Mat img(256, 256, CV_8UC1, 0);
 const cv::String win_name = "Blank Image";
 cv::namedWindow(win_name); 
 cv::imshow(win_name, img); 
 cv::waitKey(0); 
 cv::destroyWindow(win_name); 
 return 0;
}
