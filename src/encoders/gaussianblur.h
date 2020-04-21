#ifndef GAUSSIANBLUR_H
#define GAUSSIANBLUR_H

#include "basefilter.h"

class QJsonObject;

namespace Filter
{
class GaussianBlur : public BaseFilter
{
 public:
  GaussianBlur(QJsonObject const &a_config);

  void process(cv::Mat &a_src);

 private:
  int const m_kernelSizeX;
  int const m_kernelSizeY;
  double const m_sigmaX;
  double const m_sigmaY;
  int const m_borderType;
};
} // namespace Filter

#endif // GAUSSIANBLUR_H
