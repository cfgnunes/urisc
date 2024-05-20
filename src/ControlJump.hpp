#ifndef CONTROL_JUMP_HPP
#define CONTROL_JUMP_HPP

#include "Constants.hpp"

class ControlJump {
  public:
    ControlJump();

    void execute(bit_t isJump, word_t condJump, word_t jumpType, bit_t neg,
                 bit_t zero, bit_t carry, bit_t negZero, bit_t trueBit,
                 bit_t overflow);

    // Gets.
    word_t getOrigPC();

  private:
    word_t m_origPC;
};

#endif // CONTROL_JUMP_HPP
