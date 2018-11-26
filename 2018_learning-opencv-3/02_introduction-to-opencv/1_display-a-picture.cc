#include <opencv2/opencv.hpp>

int main() {
  const cv::Mat img = cv::imread("dog.png", -1);
  if (img.empty()) {
    return -1;
  }
  cv::namedWindow("Example 2-1", cv::WINDOW_AUTOSIZE);
  cv::imshow("Example 2-1", img);
  cv::waitKey(0);
  cv::destroyWindow("Example 2-1");
  return 0;
}
