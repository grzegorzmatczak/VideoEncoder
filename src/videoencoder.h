#ifndef MULTIIMAGEFILTER_H
#define MULTIIMAGEFILTER_H

#include "../../IncludeSpdlog/spdlog.h"
#include "encoder.h"

#include <opencv2/imgproc.hpp>
#include <QVector>
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>

class BaseFilter;
class QJsonArray;
namespace cv
{
class Mat;
class TickMeter;
} // namespace cv

class VideoEncoder
{
 public:
  VideoEncoder(QJsonObject const &m_filter);
  ~VideoEncoder();

  void configure(QJsonObject const &m_filter);
  void process(cv::Mat &a_image);
  double getElapsedTimeSubtractor();

 private:
  BaseEncoder * m_baseEncoder{};
  cv::TickMeter m_timer;
};

#endif // MULTIIMAGEFILTER_H
