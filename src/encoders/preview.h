#ifndef COLOR_H
#define COLOR_H

#include "baseencoder.h"

class QJsonObject;

namespace Encoder {
class Preview : public BaseEncoder {
 public:
  Preview(QJsonObject const &a_config);

  void process(cv::Mat &a_src);

 private:
  int const m_colorCode;
};
} // namespace Filter

#endif // COLOR_H
