#include "videoencoder.h"


VideoEncoder::VideoEncoder(QJsonObject const &a_config)
{
    H_Logger->info("VideoEncoder::VideoEncoder()");
    configure(a_config);
}

void VideoEncoder::configure(QJsonObject const &a_config)
{
    std::string codecSTR = "avc1";
    m_code = cv::VideoWriter::fourcc(codecSTR[0], codecSTR[1], codecSTR[2], codecSTR[3]);
}

void VideoEncoder::StartVideo(QString path, QString name, double fps, qint32 width, qint32 height)
{
    m_name = path + "/mp4/" + name + ".mp4";
    m_videoShoal = { name.toStdString(), cv::CAP_FFMPEG, m_code, fps, cv::Size(width, height), true };
    H_Logger->trace("name:{}", name.toStdString().c_str());
}

void VideoEncoder::onAddFrames(cv::Mat frame)
{
  cv::Mat Cat1;
  cv::Mat Cat2;
  cv::Mat Cat;
  cv::Mat bg_color;
  cv::Mat gt_color;
  cv::Mat image_color;
  cv::Mat clean_color;
  cv::cvtColor(clean, clean_color, cv::COLOR_GRAY2BGR);
  cv::cvtColor(bg, bg_color, cv::COLOR_GRAY2BGR);
  cv::cvtColor(gt, gt_color, cv::COLOR_GRAY2BGR);
  cv::cvtColor(image, image_color, cv::COLOR_GRAY2BGR);

  cv::hconcat(clean_color, image_color, Cat1);
  cv::hconcat(gt_color, bg_color, Cat2);
  cv::vconcat(Cat1, Cat2, Cat);
  // cv::resize(tempImage, tempImage, cv::Size(640, 480), 0, 0, cv::INTER_NEAREST);
  cv::resize(Cat, Cat, cv::Size(static_cast<int>(640), static_cast<int>(480)), 0, 0, cv::INTER_NEAREST);
  // cv::imshow("Cat", Cat);
  // cv::imshow("gt", gt);
  // cv::imshow("gt_color", gt_color);
  // cv::waitKey(1);
  videoShoal.write(Cat);

    m_videoShoal.write(frame);

}

void VideoEncoder::onRejectVideo()
{
    m_videoShoal.release();
}

void VideoEncoder::onSaveVideo()
{
    m_videoShoal.release();
}
