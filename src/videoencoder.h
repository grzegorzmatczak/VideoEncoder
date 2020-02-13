#ifndef VIDEO_ENCODER_H
#define VIDEO_ENCODER_H

#include "../../../IncludeSpdlog/spdlog.h"
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
  void process(cv::Mat &a_image,cv::Mat &a_gt,cv::Mat &a_pre,cv::Mat &a_post);
  double getElapsedTimeSubtractor();
  void endVideo();

 private:
  BaseEncoder * m_baseEncoder;
  cv::TickMeter m_timer;
};

#endif // VIDEO_ENCODER_H
