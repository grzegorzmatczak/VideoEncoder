#include "gaussianblur.h"
#include <QJsonObject>

constexpr auto KERNEL_SIZE_X{ "KernelSizeX" };
constexpr auto KERNEL_SIZE_Y{ "KernelSizeY" };
constexpr auto SIGMA_X{ "SigmaX" };
constexpr auto SIGMA_Y{ "SigmaY" };
constexpr auto BORDER_TYPE{ "BorderType" };

Filter::GaussianBlur::GaussianBlur(QJsonObject const &a_config)
  : m_kernelSizeX{ a_config[KERNEL_SIZE_X].toInt() }
  , m_kernelSizeY{ a_config[KERNEL_SIZE_Y].toInt() }
  , m_sigmaX{ a_config[SIGMA_X].toDouble() }
  , m_sigmaY{ a_config[SIGMA_Y].toDouble() }
  , m_borderType{ a_config[BORDER_TYPE].toInt() }
{
}

void Filter::GaussianBlur::process(cv::Mat &a_src)
{
  cv::GaussianBlur(a_src, a_src, cv::Size(m_kernelSizeX, m_kernelSizeY), m_sigmaX, m_sigmaY, m_borderType);
}
