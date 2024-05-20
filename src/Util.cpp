#include "Util.hpp"

word_t Util::selectBits(word_t bus, word_t msbBit, word_t lsbBit) {
    auto value = bus;

    // Desloca os bits para esquerda (trunca a parte esquerda).
    value = value << (SIZE_WORD - msbBit - 1);

    // Desloca os bits para direita (trunca a parte direita).
    value = value >> (SIZE_WORD - msbBit + lsbBit - 1);

    return value;
}

word_t Util::signalExtend(word_t bus, word_t msbBit, word_t lsbBit) {
    auto value = static_cast<s_word_t>(bus);

    // Desloca os bits para esquerda (trunca a parte esquerda).
    value = value << (SIZE_WORD - msbBit - 1);

    // Desloca os bits para direita estendendo o sinal (trunca a parte dir.).
    value = value >> (SIZE_WORD - msbBit + lsbBit - 1);

    return static_cast<word_t>(value);
}
