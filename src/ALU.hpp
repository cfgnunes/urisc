#ifndef ALU_HPP
#define ALU_HPP

#include "Constants.hpp"

class ALU {
  public:
    ALU();

    void execute(word_t valueA, word_t valueB, word_t op);
    word_t opAdd(word_t valueA, word_t valueB);
    word_t opAddInc(word_t valueA, word_t valueB);
    word_t opAnd(word_t valueA, word_t valueB);
    word_t opAndNotA(word_t valueA, word_t valueB);
    word_t opAsl(word_t valueA);
    word_t opAsr(word_t valueA);
    word_t opDecA(word_t valueA);
    word_t opIncA(word_t valueA);
    word_t opLch(word_t valueA, word_t valueB);
    word_t opLcl(word_t valueA, word_t valueB);
    word_t opLoadLit(word_t valueB);
    word_t opLsl(word_t valueA);
    word_t opLsr(word_t valueA);
    word_t opNand(word_t valueA, word_t valueB);
    word_t opNor(word_t valueA, word_t valueB);
    word_t opOnes();
    word_t opOr(word_t valueA, word_t valueB);
    word_t opOrNotB(word_t valueA, word_t valueB);
    word_t opPassA(word_t valueA);
    word_t opPassNotA(word_t valueA);
    word_t opSub(word_t valueA, word_t valueB);
    word_t opSubDec(word_t valueA, word_t valueB);
    word_t opXNor(word_t valueA, word_t valueB);
    word_t opXOr(word_t valueA, word_t valueB);
    word_t opZeros();
    void setFlags(word_t valueA, word_t valueB, word_t op);

    // Gets.
    bit_t getCarry();
    bit_t getNeg();
    bit_t getNegZero();
    bit_t getOverflow();
    bit_t getTrueBit();
    bit_t getZero();
    s_word_t getOutput();

  private:
    // Flags da ALU.
    bit_t m_carry;
    bit_t m_neg;
    bit_t m_negZero;
    bit_t m_overflow;
    bit_t m_trueBit;
    bit_t m_zero;
    s_word_t m_output;
};

#endif // ALU_HPP
