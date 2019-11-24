#ifndef NONE_H
#define NONE_H

#include "baseencoder.h"

class QJsonObject;

namespace Encoder {
class None : public BaseEncoder {
 public:
	None();

	void process(cv::Mat &a_src);

 private:
};
} // namespace Encoder

#endif // NONE_H
