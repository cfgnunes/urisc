#ifndef BANK_REGISTER_HPP
#define BANK_REGISTER_HPP

#include "Constants.hpp"

class BankRegister {
  public:
    BankRegister();

    void execute(word_t addressA, word_t addressB, word_t writeAddress,
                 word_t dataWrite, bit_t writeEnable);

    // Gets.
    word_t *getRegisters();
    word_t getValueA();
    word_t getValueB();

  private:
    word_t m_registers[8]{};
    word_t m_valueA;
    word_t m_valueB;
};

#endif // BANK_REGISTER_HPP
