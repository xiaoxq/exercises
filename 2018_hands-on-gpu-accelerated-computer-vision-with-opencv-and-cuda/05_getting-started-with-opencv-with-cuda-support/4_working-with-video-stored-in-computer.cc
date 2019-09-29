#include <opencv2/opencv.hpp>

#include <iostream>

int main(int argc, char* argv[]) {
  // open the video file from PC
  cv::VideoCapture cap("images/rhinos.avi");
  // if not success, exit program
  if (!cap.isOpened()) {
    std::cout << "Cannot open the video file" << std::endl;
    return -1;
  }

  std::cout << "Press Q to Quit" << std::endl;
  cv::String win_name = "First Video";
  cv::namedWindow(win_name);

  cv::Mat frame;
  while (cap.read(frame)) {
    // display the frame
    cv::imshow(win_name, frame);
    // Wait for 100 ms and key 'q' for exit
    if (cv::waitKey(100) == 'q') {
      break;
    }
  }
  cv::destroyWindow(win_name);
  return 0;
}
