#include "ALU.hpp"
#include "Util.hpp"

ALU::ALU() {
    m_neg = false;
    m_zero = false;
    m_carry = false;
    m_negZero = false;
    m_trueBit = false;
    m_overflow = false;
    m_output = 0;
}

void ALU::execute(word_t valueA, word_t valueB, word_t op) {
    switch (op) {
    case (OP_ADD):
        m_output = opAdd(valueA, valueB);
        setFlags(valueA, valueB, OP_ADD);
        break;
    case (OP_ADD_INC):
        m_output = opAddInc(valueA, valueB);
        setFlags(valueA, valueB, OP_ADD_INC);
        break;
    case (OP_AND):
        m_output = opAnd(valueA, valueB);
        setFlags(valueA, valueB, OP_AND);
        break;
    case (OP_AND_NOT_A):
        m_output = opAndNotA(valueA, valueB);
        setFlags(valueA, valueB, OP_AND_NOT_A);
        break;
    case (OP_ASL):
        m_output = opAsl(valueA);
        setFlags(valueA, valueB, OP_ASL);
        m_overflow = (static_cast<bit_t>(Util::selectBits(valueA, 15, 15))) ^
                     (static_cast<bit_t>(Util::selectBits(valueA, 14, 14)));
        m_carry = static_cast<bit_t>(Util::selectBits(valueA, 15, 15));
        break;
    case (OP_ASR):
        m_output = opAsr(valueA);
        setFlags(valueA, valueB, OP_ASR);
        break;
    case (OP_DECA):
        m_output = opDecA(valueA);
        setFlags(valueA, valueB, OP_DECA);
        break;
    case (OP_INCA):
        m_output = opIncA(valueA);
        setFlags(valueA, valueB, OP_INCA);
        break;
    case (OP_LSL):
        m_output = opLsl(valueA);
        setFlags(valueA, valueB, OP_LSL);
        m_overflow = false;
        m_carry = static_cast<bit_t>(Util::selectBits(valueA, 15, 15));
        break;
    case (OP_LSR):
        m_output = opLsr(valueA);
        setFlags(valueA, valueB, OP_LSR);
        break;
    case (OP_NAND):
        m_output = opNand(valueA, valueB);
        setFlags(valueA, valueB, OP_NAND);
        break;
    case (OP_NOR):
        m_output = opNor(valueA, valueB);
        setFlags(valueA, valueB, OP_NOR);
        break;
    case (OP_ONES):
        m_output = opOnes();
        setFlags(valueA, valueB, OP_ONES);
        break;
    case (OP_OR):
        m_output = opOr(valueA, valueB);
        setFlags(valueA, valueB, OP_OR);
        break;
    case (OP_OR_NOT_B):
        m_output = opOrNotB(valueA, valueB);
        setFlags(valueA, valueB, OP_OR_NOT_B);
        break;
    case (OP_PASSA):
        m_output = opPassA(valueA);
        setFlags(valueA, valueB, OP_PASSA);
        break;
    case (OP_PASS_NOT_A):
        m_output = opPassNotA(valueA);
        setFlags(valueA, valueB, OP_PASS_NOT_A);
        break;
    case (OP_SUB):
        m_output = opSub(valueA, valueB);
        setFlags(valueA, valueB, OP_SUB);
        break;
    case (OP_SUB_DEC):
        m_output = opSubDec(valueA, valueB);
        setFlags(valueA, valueB, OP_SUB_DEC);
        break;
    case (OP_X_NOR):
        m_output = opXNor(valueA, valueB);
        setFlags(valueA, valueB, OP_X_NOR);
        break;
    case (OP_X_OR):
        m_output = opXOr(valueA, valueB);
        setFlags(valueA, valueB, OP_X_OR);
        break;
    case (OP_ZEROS):
        m_output = opZeros();
        setFlags(valueA, valueB, OP_ZEROS);
        break;
    case (OP_LOAD_LIT):
        m_output = opLoadLit(valueB);
        break;
    case (OP_LCH):
        m_output = opLch(valueA, valueB);
        break;
    case (OP_LCL):
        m_output = opLcl(valueA, valueB);
        break;
    default:
        break;
    }
}

word_t ALU::opZeros() {
    return 0;
}

word_t ALU::opAnd(word_t valueA, word_t valueB) {
    return (valueA & valueB);
}

word_t ALU::opAndNotA(word_t valueA, word_t valueB) {
    return (~valueA & valueB);
}

word_t ALU::opPassA(word_t valueA) {
    return valueA;
}

word_t ALU::opXOr(word_t valueA, word_t valueB) {
    return (valueA ^ valueB);
}

word_t ALU::opOr(word_t valueA, word_t valueB) {
    return (valueA | valueB);
}

word_t ALU::opNor(word_t valueA, word_t valueB) {
    return (~valueA & ~valueB);
}

word_t ALU::opXNor(word_t valueA, word_t valueB) {
    return ~(valueA ^ valueB);
}

word_t ALU::opPassNotA(word_t valueA) {
    return (~valueA);
}

word_t ALU::opOrNotB(word_t valueA, word_t valueB) {
    return (valueA | ~valueB);
}

word_t ALU::opNand(word_t valueA, word_t valueB) {
    return (~valueA | ~valueB);
}

word_t ALU::opOnes() {
    return 1;
}

word_t ALU::opAdd(word_t valueA, word_t valueB) {
    return static_cast<word_t>(static_cast<s_word_t>(valueA) +
                               static_cast<s_word_t>(valueB));
}

word_t ALU::opAddInc(word_t valueA, word_t valueB) {
    return static_cast<word_t>(static_cast<s_word_t>(valueA) +
                               static_cast<s_word_t>(valueB) + 1);
}

word_t ALU::opIncA(word_t valueA) {
    return static_cast<word_t>(static_cast<s_word_t>(valueA) + 1);
}

word_t ALU::opSubDec(word_t valueA, word_t valueB) {
    return static_cast<word_t>(static_cast<s_word_t>(valueA) -
                               static_cast<s_word_t>(valueB) - 1);
}

word_t ALU::opSub(word_t valueA, word_t valueB) {
    return static_cast<word_t>(static_cast<s_word_t>(valueA) -
                               static_cast<s_word_t>(valueB));
}

word_t ALU::opDecA(word_t valueA) {
    return static_cast<word_t>(static_cast<s_word_t>(valueA) - 1);
}

word_t ALU::opLsl(word_t valueA) {
    return (valueA << 1u);
}

word_t ALU::opLsr(word_t valueA) {
    return (valueA >> 1u);
}

word_t ALU::opAsr(word_t valueA) {
    return static_cast<word_t>(static_cast<s_word_t>(valueA) >> 1u);
}

word_t ALU::opAsl(word_t valueA) {
    return static_cast<word_t>(static_cast<s_word_t>(valueA) << 1u);
}

word_t ALU::opLoadLit(word_t valueB) {
    return (valueB);
}

word_t ALU::opLch(word_t valueA, word_t valueB) {
    return ((valueA & 0x00FFu) | (valueB << 8u));
}

word_t ALU::opLcl(word_t valueA, word_t valueB) {
    return ((valueA & 0xFF00u) | (valueB & 0x00FFu));
}

void ALU::setFlags(word_t valueA, word_t valueB, word_t op) {
    // Calcula a flag neg.
    m_neg = m_output < 0;

    // Calcula a flag zero.
    m_zero = m_output == 0;

    // Calcula a flag negZero.
    m_negZero = m_output <= 0;

    // Calcula a flag trueBit.
    m_trueBit = m_output != 0;

    // Calcula a flag carry.
    if (op == OP_ADD || op == OP_ADD_INC || op == OP_INCA || op == OP_SUB ||
        op == OP_SUB_DEC || op == OP_DECA) {
        // carry para operações aritméticas.
        // Se os dois bits significativos for 1, há carry.
        if ((MASK_C & valueA) == MASK_C && (MASK_C & valueB) == MASK_C)
            m_carry = true;
        else
            m_carry = (((MASK_C & valueA) | (MASK_C & valueB)) == MASK_C) &&
                      ((MASK_C & ~(static_cast<word_t>(m_output))) == MASK_C);
    } else {
        // carry para operações lógicas = 0.
        m_carry = false;
    }

    // Calcula a flag overflow.
    if (op == OP_ADD || op == OP_ADD_INC || op == OP_INCA) {
        // overflow para operações de soma.
        m_overflow = (static_cast<s_word_t>(valueA) >= 0 &&
                      static_cast<s_word_t>(valueB) >= 0 && m_output < 0) ||
                     (static_cast<s_word_t>(valueA) < 0 &&
                      static_cast<s_word_t>(valueB) < 0 && m_output >= 0);
    } else if (op == OP_SUB || op == OP_SUB_DEC || op == OP_DECA) {
        // overflow para operações de subtração.
        m_overflow = (static_cast<s_word_t>(valueA) >= 0 &&
                      static_cast<s_word_t>(valueB) < 0 && m_output < 0) ||
                     (static_cast<s_word_t>(valueA) < 0 &&
                      static_cast<s_word_t>(valueB) >= 0 && m_output >= 0);
    } else {
        // overflow para operações lógicas = 0.
        m_overflow = false;
    }
}

// Gets.

bit_t ALU::getCarry() {
    return m_carry;
}

bit_t ALU::getNeg() {
    return m_neg;
}

bit_t ALU::getNegZero() {
    return m_negZero;
}

bit_t ALU::getOverflow() {
    return m_overflow;
}

bit_t ALU::getTrueBit() {
    return m_trueBit;
}

bit_t ALU::getZero() {
    return m_zero;
}

s_word_t ALU::getOutput() {
    return m_output;
}
