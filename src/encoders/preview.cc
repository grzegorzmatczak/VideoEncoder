#include "preview.h"
#include <QJsonObject>

constexpr auto COLOR_CODE{ "ColorCode" };

Encoder::Preview::Preview(QJsonObject const &a_config)
  : m_colorCode{ a_config[COLOR_CODE].toInt() }
{
}

void Encoder::Preview::process(cv::Mat &a_src)
{
  cv::cvtColor(a_src, a_src, m_colorCode);
}
