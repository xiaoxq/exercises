#include <string>

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main() {
  cv::namedWindow("Example 2-3", cv::WINDOW_AUTOSIZE);
  cv::VideoCapture cap;
  cap.open("aaron.mp4");

  cv::Mat frame;
  constexpr int kFrameDelay = 33;
  while (cv::waitKey(kFrameDelay) < 0) {
    cap >> frame;
    if (frame.empty()) {
      break;
    }
    cv::imshow("Example 2-3", frame);
  }

  return 0;
}