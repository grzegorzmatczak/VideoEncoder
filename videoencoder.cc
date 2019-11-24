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
