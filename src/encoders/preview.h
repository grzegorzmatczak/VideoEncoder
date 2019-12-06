#ifndef ENCODER_PREVIEW_H
#define ENCODER_PREVIEW_H

#include "baseencoder.h"
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "../../../../IncludeSpdlog/spdlog.h"
#include <QtCore>

class QJsonObject;

namespace Encoder {
class Preview : public BaseEncoder {
 public:
  Preview(QJsonObject const &a_config);

  void process(cv::Mat &a_image,cv::Mat &a_gt,cv::Mat &a_pre,cv::Mat &a_post);

 private:
    QString m_name;
    QString m_type;
    qint32 m_code;
    double m_fps;
    QString m_iter;
    qint32 m_width;
    qint32 m_height;
    cv::VideoWriter m_videoShoal;
};
} // namespace Filter

#endif // ENCODER_PREVIEW_H
