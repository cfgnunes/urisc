#ifndef MUX_HPP
#define MUX_HPP

#include "Constants.hpp"

class Mux {
  public:
    Mux();

    void mux2x1(word_t data1, word_t data2, bit_t sel);
    void mux3x1(word_t data1, word_t data2, word_t data3, word_t sel);

    // Gets.
    word_t getOutput();

  private:
    word_t m_output;
};

#endif // MUX_HPP
