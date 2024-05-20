#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

// Define constantes.
const auto SIZE_WORD = 16u; // Define o tamanho da word no uRISC.

// Código de operação das instruções - bits da instrução [15:14].
enum instructionType {
    INSTRUCTION_TYPE_4_5_6 = 0,
    INSTRUCTION_TYPE_1_7 = 1,
    INSTRUCTION_TYPE_2 = 2,
    INSTRUCTION_TYPE_3 = 3,
};

// Valores das instruções da ALU - bits da instrução [10:16].
enum aluOperation {
    OP_ADD = 24,
    OP_ADD_INC = 26,
    OP_AND = 2,
    OP_AND_NOT_A = 10,
    OP_ASL = 17,
    OP_ASR = 19,
    OP_DECA = 29,
    OP_INCA = 28,
    OP_LCH = 13,
    OP_LCL = 14,
    OP_LOAD = 20,
    OP_LOAD_LIT = 12,
    OP_LSL = 16,
    OP_LSR = 18,
    OP_NAND = 3,
    OP_NOP = 15,
    OP_NOR = 5,
    OP_ONES = 1,
    OP_OR = 4,
    OP_OR_NOT_B = 11,
    OP_PASSA = 9,
    OP_PASS_NOT_A = 8,
    OP_STORE = 22,
    OP_SUB = 25,
    OP_SUB_DEC = 27,
    OP_X_NOR = 7,
    OP_X_OR = 6,
    OP_ZEROS = 0,
};

// Valores da instrução 'jumpType' - bits da instrução [13:12].
enum jumpType {
    JUMP_TYPE_FALSE = 0,
    JUMP_TYPE_TRUE = 1,
    JUMP_TYPE_UNCONDITIONAL = 2,
    JUMP_TYPE_JAL_JR = 3,
};

// Valores da instrução 'condJump' - bits da instrução [11:8].
enum condJump {
    COND_JUMP_NEG = 4,
    COND_JUMP_ZERO = 5,
    COND_JUMP_CARRY = 6,
    COND_JUMP_NEG_ZERO = 7,
    COND_JUMP_TRUE = 0,
    COND_JUMP_OVERFLOW = 3,
};

typedef signed short int s_word_t;
typedef unsigned short int word_t;
typedef bool bit_t;

const word_t MASK_C = 0x8000u; // Define a máscara para o cálculo de carry.

#endif // CONSTANTS_HPP
