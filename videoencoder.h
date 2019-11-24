#ifndef VIDEOENCODER_H
#define VIDEOENCODER_H

#include "../../IncludeSpdlog/spdlog.h"

#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <QObject>
#include <QDir>


class VideoEncoder
{
public:
    VideoEncoder(QJsonObject const &a_config);

public slots:
    void configure(QJsonObject const &a_config);
    void StartVideo(QString path, QString name, double fps, qint32 width, qint32 height);
    void onAddFrames(cv::Mat frame);
    void onRejectVideo();
    void onSaveVideo();

private:
    int m_code;
    QString m_name;

    cv::VideoWriter m_videoShoal;
};

#endif // VIDEOENCODER_H
