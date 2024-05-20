#ifndef CONTROL_HPP
#define CONTROL_HPP

#include "Constants.hpp"
#include "Util.hpp"

class Control {
  public:
    Control();

    void execute(word_t instruction);

    // Gets.
    bit_t getDataDestReg();
    bit_t getDestReg();
    bit_t getExtIM();
    bit_t getExtIMJump();
    bit_t getMemToReg();
    bit_t getOrigAlu();
    bit_t getOrigRegA();
    bit_t getWriteMem();
    bit_t getWriteReg();
    bit_t isHalt();
    bit_t isJump();
    word_t getCondJump();
    word_t getJumpType();
    word_t getOpAlu();

  private:
    bit_t m_dataDestReg;
    bit_t m_destReg;
    bit_t m_extIM;
    bit_t m_extIMJump;
    bit_t m_isHalt;
    bit_t m_isJump;
    bit_t m_memToReg;
    bit_t m_origAlu;
    bit_t m_origRegA;
    bit_t m_writeMem;
    bit_t m_writeReg;
    word_t m_condJump;
    word_t m_jumpType;
    word_t m_opAlu;
};

#endif // CONTROL_HPP
