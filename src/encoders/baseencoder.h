#ifndef BASE_ENCODER_H
#define BASE_ENCODER_H

#include <opencv2/imgproc.hpp>

class BaseEncoder
{
 public:
  BaseEncoder();
  virtual ~BaseEncoder();

  virtual void process(cv::Mat &a_src) = 0;
};

#endif // BASE_ENCODER_H
