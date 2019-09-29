#include <opencv2/opencv.hpp>

#include <iostream>

void RunOnCPU(const cv::Mat& img) {
  // Get initial time in miliseconds
  const int64 work_begin = cv::getTickCount();

  cv::Mat result_host1, result_host2, result_host3, result_host4, result_host5;

  cv::threshold(img, result_host1, 128.0, 255.0, cv::THRESH_BINARY);
  cv::threshold(img, result_host2, 128.0, 255.0, cv::THRESH_BINARY_INV);
  cv::threshold(img, result_host3, 128.0, 255.0, cv::THRESH_TRUNC);
  cv::threshold(img, result_host4, 128.0, 255.0, cv::THRESH_TOZERO);
  cv::threshold(img, result_host5, 128.0, 255.0, cv::THRESH_TOZERO_INV);

  // Get time after work has finished
  const int64 delta = cv::getTickCount() - work_begin;
  const double work_fps = cv::getTickFrequency() / delta;
  std::cout << "Performance of Thresholding on CPU: " << std::endl;
  std::cout << "Time: " << (1 / work_fps) << std::endl;
  std::cout << "FPS: " << work_fps << std::endl;
}

void RunOnGPU(const cv::Mat& img) {
  // Get initial time in miliseconds
  int64 work_begin = cv::getTickCount();

  cv::cuda::GpuMat d_img1;
  d_img1.upload(img);

  cv::cuda::GpuMat d_result1, d_result2, d_result3, d_result4, d_result5;
  cv::cuda::threshold(d_img1, d_result1, 128.0, 255.0, cv::THRESH_BINARY);
  cv::cuda::threshold(d_img1, d_result2, 128.0, 255.0, cv::THRESH_BINARY_INV);
  cv::cuda::threshold(d_img1, d_result3, 128.0, 255.0, cv::THRESH_TRUNC);
  cv::cuda::threshold(d_img1, d_result4, 128.0, 255.0, cv::THRESH_TOZERO);
  cv::cuda::threshold(d_img1, d_result5, 128.0, 255.0, cv::THRESH_TOZERO_INV);

  cv::Mat h_result1, h_result2, h_result3, h_result4, h_result5;
  d_result1.download(h_result1);
  d_result2.download(h_result2);
  d_result3.download(h_result3);
  d_result4.download(h_result4);
  d_result5.download(h_result5);

  const int64 delta = cv::getTickCount() - work_begin;
  // Measure frames per second
  const double work_fps = cv::getTickFrequency() / delta;
  std::cout << "Performance of Thresholding on GPU: " << std::endl;
  std::cout << "Time: " << (1 / work_fps) << std::endl;
  std::cout << "FPS: " << work_fps << std::endl;
}

int main(int argc, char* argv[]) {
  cv::Mat img = cv::imread("images/cameraman.tif", 0);
  RunOnCPU(img);
  RunOnGPU(img);
  return 0;
}
