#include <opencv2/opencv.hpp>

#include <iostream>

int main(int argc, char* argv[]) {
  cv::Mat h_img1 = cv::imread("images/cameraman.tif");
  cv::Mat h_img2 = cv::imread("images/circles.png");
  // Create Memory for storing Images on device
  cv::cuda::GpuMat d_result1, d_img1, d_img2;
  cv::Mat h_result1;
  // Upload Images to device
  d_img1.upload(h_img1);
  d_img2.upload(h_img2);

  // d_result1 = d_img1 + d_img2
  cv::cuda::add(d_img1, d_img2, d_result1);

  // d_result1 = d_img1 - d_img2
  // cv::cuda::subtract(d_img1, d_img2, d_result1);

  // d_result1 = α * d_img1 + β * d_img2 + γ
  // cv::cuda::addWeighted(d_img1, 0.7, d_img2, 0.3, 0, d_result1);

  // d_result1 = 255 - d_img1
  // cv::cuda::bitwise_not(d_img1, d_result1);

  // Change color space.
  // cv::cuda::cvtColor(d_img1, d_result2, cv::COLOR_BGR2RGB);

  // Download Result back to host
  d_result1.download(h_result1);
  cv::imshow("Image1 ", h_img1);
  cv::imshow("Image2 ", h_img2);
  cv::imshow("Result addition ", h_result1);
  cv::imwrite("images/result_add.png", h_result1);
  cv::waitKey();
  return 0;
}
