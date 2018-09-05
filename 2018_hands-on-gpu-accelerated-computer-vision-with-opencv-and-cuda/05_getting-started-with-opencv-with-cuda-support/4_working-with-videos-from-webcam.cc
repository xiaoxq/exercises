#include <opencv2/opencv.hpp>

#include <iostream>

int main(int argc, char* argv[]) {
  // open the Webcam
  cv::VideoCapture cap(0);
  // if not success, exit program
  if (!cap.isOpened()) {
    std::cout << "Cannot open Webcam" << std::endl;
    return -1;
  }
  // Get the frames rate of the video from webcam
  double frames_per_second = cap.get(cv::CAP_PROP_FPS); 
  std::cout << "Frames per seconds: " << frames_per_second << std::endl;
  std::cout << "Press Q to Quit" << std::endl;
  cv::String win_name = "Webcam Video";
  cv::namedWindow(win_name); //create a window

  cv::Mat frame;
  while (cap.read(frame)) {
    // show the frame in the created window
    cv::imshow(win_name, frame);
    if (cv::waitKey(1) == 'q') {
      break;
    }
  }
  return 0;
}
