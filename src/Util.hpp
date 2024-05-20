#ifndef UTIL_HPP
#define UTIL_HPP

#include "Constants.hpp"

namespace Util {
word_t selectBits(word_t bus, word_t msbBit, word_t lsbBit);
word_t signalExtend(word_t bus, word_t msbBit, word_t lsbBit);
} // namespace Util.

#endif // UTIL_HPP
