#include "BankRegister.hpp"

BankRegister::BankRegister() {
    m_valueA = 0;
    m_valueB = 0;
    m_registers[8] = {0};
}

void BankRegister::execute(word_t addressA, word_t addressB,
                           word_t writeAddress, word_t dataWrite,
                           bit_t writeEnable) {
    // Lê os registradores nos endereços especificados.
    m_valueA = m_registers[addressA];
    m_valueB = m_registers[addressB];

    // Verifica a flag de escrita, se for alta,
    // escreve os registradores nos endereços especificados.
    if (writeEnable)
        m_registers[writeAddress] = dataWrite;
}

// Gets.

word_t *BankRegister::getRegisters() {
    return m_registers;
}

word_t BankRegister::getValueA() {
    return m_valueA;
}

word_t BankRegister::getValueB() {
    return m_valueB;
}
