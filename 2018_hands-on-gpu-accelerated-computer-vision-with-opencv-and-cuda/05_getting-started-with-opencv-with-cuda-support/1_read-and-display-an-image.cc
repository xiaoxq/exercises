#include <opencv2/opencv.hpp>

#include <iostream>

int main(int argc, char** argv) {
  std::string image_path = "dog.png";

  // Read image.
  const auto img = cv::imread(image_path, cv::IMREAD_COLOR);
  if (img.empty()) {
    std::cerr << "Could not open image " << image_path << std::endl;
    return -1;
  }

  // Show image.
  const std::string window_name = "OpenCV Window";
  cv::namedWindow(window_name);
  cv::imshow(window_name, img);

  // Wait for any keystroke in the window.
  cv::waitKey(0);
  cv::destroyWindow(window_name);
  return 0;
}
