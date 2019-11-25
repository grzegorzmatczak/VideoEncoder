#ifndef BASE_ENCODER_H
#define BASE_ENCODER_H

#include <opencv2/imgproc.hpp>

class BaseEncoder
{
 public:
  BaseEncoder();
  virtual ~BaseEncoder();

  virtual void process(cv::Mat &a_image,cv::Mat &a_gt,cv::Mat &a_pre,cv::Mat &a_post) = 0;
};

#endif // BASE_ENCODER_H
