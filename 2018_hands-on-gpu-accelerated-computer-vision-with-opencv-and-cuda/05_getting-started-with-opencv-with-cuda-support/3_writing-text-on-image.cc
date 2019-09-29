#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  const cv::Mat img(512, 512, CV_8UC3, cv::Scalar(0, 0, 0));
  cv::line(img, cv::Point(0, 0), cv::Point(511, 511), cv::Scalar(0, 255, 0), 7);
  cv::rectangle(img, cv::Point(384, 0), cv::Point(510, 128),
                cv::Scalar(255, 255, 0), 5);
  cv::circle(img, cv::Point(447, 63), 63, cv::Scalar(0, 0, 255), -1);
  cv::ellipse(img, cv::Point(256, 256), cv::Point(100, 100), 0, 0, 180, 255,
              -1);
  cv::putText(img, "OpenCV!", cv::Point(10, 500), cv::FONT_HERSHEY_SIMPLEX, 3,
              cv::Scalar(255, 255, 255), 5, 8);

  const cv::String win_name = "Shapes on blank Image";
  cv::namedWindow(win_name);
  cv::imshow(win_name, img);
  cv::waitKey(0);
  cv::destroyWindow(win_name);
  return 0;
}
