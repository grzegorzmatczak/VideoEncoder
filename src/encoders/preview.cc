#include "preview.h"
#include <QJsonObject>

Encoder::Preview::Preview(QJsonObject const &a_config)
{
  std::string codecSTR = "avc1";
  m_code = cv::VideoWriter::fourcc(codecSTR[0], codecSTR[1], codecSTR[2], codecSTR[3]);

  m_name = a_config["Path"].toString();
  m_fps = (double)a_config["FPS"].toInt();
  m_iter = QString::number(a_config["Iter"].toInt());
  m_type = a_config["Type"].toString();
  m_width = a_config["Width"].toInt();
  m_height = a_config["Height"].toInt();
  m_videoShoal = {
    (m_name + m_iter + m_type).toStdString(), cv::CAP_FFMPEG, m_code, m_fps, cv::Size(m_width, m_height), true
  };
  H_Logger->trace("name:{}", (m_name + m_iter + m_type).toStdString().c_str());
}

void Encoder::Preview::process(cv::Mat &a_image, cv::Mat &a_gt, cv::Mat &a_pre, cv::Mat &a_post)
{
  cv::Mat m_image;
  cv::Mat m_gt;
  cv::Mat m_pre;
  cv::Mat m_post;

  cv::cvtColor(a_image, m_image, cv::COLOR_GRAY2BGR);
  cv::cvtColor(a_gt, m_gt, cv::COLOR_GRAY2BGR);
  cv::cvtColor(a_pre, m_pre, cv::COLOR_GRAY2BGR);
  cv::cvtColor(a_post, m_post, cv::COLOR_GRAY2BGR);

  cv::Mat Cat1;
  cv::Mat Cat2;
  cv::Mat Cat;

  cv::hconcat(m_image, m_gt, Cat1);
  cv::hconcat(m_pre, m_post, Cat2);
  cv::vconcat(Cat1, Cat2, Cat);

  cv::resize(Cat, Cat, cv::Size(static_cast<int>(m_width), static_cast<int>(m_height)), 0, 0, cv::INTER_NEAREST);
  m_videoShoal.write(Cat);
}
void Encoder::Preview::endVideo()
{
  m_videoShoal.release();
}
