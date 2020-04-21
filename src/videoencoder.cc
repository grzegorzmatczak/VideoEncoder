#include "videoencoder.h"

constexpr auto FILTER_NAME{ "Name" };

VideoEncoder::VideoEncoder(QJsonObject const &a_config)
{
  H_Logger->trace("VideoEncoder::VideoEncoder()");
  m_baseEncoder = new Encoder::None();
}

VideoEncoder::~VideoEncoder()
{
  delete m_baseEncoder;
}

void VideoEncoder::configure(QJsonObject const &a_config)
{
  H_Logger->trace("VideoEncoder::configure()");
  auto const NAME_STRING{ a_config[FILTER_NAME].toString().toStdString() };
  H_Logger->trace("encoder type: {}", NAME_STRING);
  auto const NAME_SID{ SID(NAME_STRING.c_str()) };
  delete m_baseEncoder;
  m_timer.reset();

  switch (NAME_SID)
  {
    case SID("Preview"): m_baseEncoder = new Encoder::Preview{ a_config }; break;
    case SID("None"): m_baseEncoder = new Encoder::None(); break;
    default: H_Logger->error("Unsupported encoder type: {}", NAME_STRING); break;
  }
}

void VideoEncoder::process(cv::Mat &a_image, cv::Mat &a_gt, cv::Mat &a_pre, cv::Mat &a_post)
{
  H_Logger->trace("VideoEncoder::process(a_image)");
  m_timer.start();
  m_baseEncoder->process(a_image, a_gt, a_pre, a_post);
  m_timer.stop();
}
double VideoEncoder::getElapsedTimeSubtractor()
{
  return m_timer.getTimeMilli();
}
void VideoEncoder::endVideo()
{
  m_baseEncoder->endVideo();
}
