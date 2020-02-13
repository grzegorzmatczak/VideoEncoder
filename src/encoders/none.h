#ifndef ENCODER_NONE_H
#define ENCODER_NONE_H

#include "baseencoder.h"

class QJsonObject;

namespace Encoder {
class None : public BaseEncoder {
 public:
	None();

	void process(cv::Mat &a_image,cv::Mat &a_gt,cv::Mat &a_pre,cv::Mat &a_post);
	  void endVideo();

 private:
};
} // namespace Encoder

#endif // ENCODER_NONE_H
