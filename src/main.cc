#include "videoencoder.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

int main() {
    QJsonObject filterConfig{{"Name", "GaussianBlur"},
                             {"KernelSizeX", 15},
                             {"KernelSizeY", 15},
                             {"SigmaX", 3},
                             {"SigmaY", 3},
                             {"BorderType", 4}};



    return 0;
}
