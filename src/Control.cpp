#include "Control.hpp"

Control::Control() {
    m_condJump = 0;
    m_dataDestReg = false;
    m_destReg = false;
    m_extIM = false;
    m_extIMJump = false;
    m_isHalt = false;
    m_isJump = false;
    m_jumpType = 0;
    m_memToReg = false;
    m_opAlu = OP_NOP;
    m_origAlu = false;
    m_origRegA = false;
    m_writeMem = false;
    m_writeReg = false;
}

void Control::execute(word_t instruction) {
    // Lê os dois bits mais significativos da instrução.
    auto instrType = Util::selectBits(instruction, 15, 14);

    // Bit que determina se a instrução é de Jump.
    m_isJump = false;

    // Define a operação atual da ALU.
    m_opAlu = OP_NOP;

    switch (instrType) {
    case INSTRUCTION_TYPE_4_5_6:
        // Formato 4, 5 e 6: instruções de jumps.
        m_condJump = Util::selectBits(instruction, 11, 8);
        m_jumpType = Util::selectBits(instruction, 13, 12);
        m_isJump = true;
        switch (m_jumpType) {
        case JUMP_TYPE_FALSE:
        case JUMP_TYPE_TRUE:
            m_extIMJump = true; // Controle do Mux7.
            m_writeReg = false; // Escrita do Banco de Registradores.
            m_writeMem = false; // Escrita da Memória de Dados.
            break;
        case JUMP_TYPE_UNCONDITIONAL:
            m_extIMJump = false; // Controle do Mux7.
            m_writeReg = false;  // Escrita do Banco de Registradores.
            m_writeMem = false;  // Escrita da Memória de Dados.
            // Instrução de HALT = Local: j Local.
            if (instruction == 0x2FFF) {
                m_isHalt = true;
            }
            break;
        case JUMP_TYPE_JAL_JR:
            // O controle do Mux6 é definido no ControlJump.
            // Determina se o Jump é do tipo 'register' ou 'jump and link'.
            if (Util::selectBits(instruction, 11, 11)) {
                // Jump register.
                m_origRegA = false; // Controle do Mux1.
                m_writeReg = false; // Escrita do Banco de Registradores.
                m_writeMem = false; // Escrita da Memória de Dados.
            } else {
                // Jump and link.
                m_origRegA = false;    // Controle do Mux1.
                m_destReg = true;      // Controle do Mux2.
                m_dataDestReg = false; // Controle do Mux3.
                m_writeReg = true;     // Escrita do Banco de Registradores.
                m_writeMem = false;    // Escrita da Memória de Dados.
            }
            break;
        default:
            break;
        }
        break;

    case INSTRUCTION_TYPE_1_7:
        // Formatos 1 e 7: instruções aritméticas e lógicas, load e store.
        m_opAlu = Util::selectBits(instruction, 10, 6);
        if (m_opAlu == OP_LOAD) {
            m_origRegA = false;   // Controle do Mux1.
            m_destReg = false;    // Controle do Mux2.
            m_dataDestReg = true; // Controle do Mux3.
            m_memToReg = false;   // Controle do Mux5.
            m_writeReg = true;    // Escrita do Banco de Registradores.
            m_writeMem = false;   // Escrita da Memória de Dados.
        } else if (m_opAlu == OP_STORE) {
            m_origRegA = false; // Controle do Mux1.
            m_destReg = false;  // Controle do Mux2.
            m_writeReg = false; // Escrita do Banco de Registradores.
            m_writeMem = true;  // Escrita da Memória de Dados.
        } else {
            // Operações lógicas e aritméticas.
            m_origRegA = false;   // Controle do Mux1.
            m_destReg = false;    // Controle do Mux2.
            m_dataDestReg = true; // Controle do Mux3.
            m_origAlu = false;    // Controle do Mux4.
            m_memToReg = true;    // Controle do Mux5.
            m_writeReg = true;    // Escrita do Banco de Registradores.
            m_writeMem = false;   // Escrita da Memória de Dados.
        }
        break;

    case INSTRUCTION_TYPE_2:
        // Formato 2: instrução de load imediato.
        m_opAlu = OP_LOAD_LIT;
        m_destReg = false;    // Controle do Mux2.
        m_dataDestReg = true; // Controle do Mux3
        m_origAlu = true;     // Controle do Mux4.
        m_memToReg = true;    // Controle do Mux5.
        m_extIM = true;       // Controle do Mux8.
        m_writeReg = true;    // Escrita do Banco de Registradores.
        m_writeMem = false;   // Escrita da Memória de Dados.
        break;

    case INSTRUCTION_TYPE_3:
        // Formato 3: instruções de load high e load low.
        m_origRegA = true;    // Controle do Mux1.
        m_destReg = false;    // Controle do Mux2.
        m_dataDestReg = true; // Controle do Mux3.
        m_origAlu = true;     // Controle do Mux4.
        m_memToReg = true;    // Controle do Mux5.
        m_extIM = true;       // Controle do Mux8.
        m_writeReg = true;    // Escrita do Banco de Registradores.
        m_writeMem = false;   // Escrita da Memória de Dados.
        // Define a operação de load da ALU.
        if (Util::selectBits(instruction, 10, 10))
            m_opAlu = OP_LCH;
        else
            m_opAlu = OP_LCL;
        break;
    default:
        break;
    }
}

// Gets.

bit_t Control::getDataDestReg() {
    return m_dataDestReg;
}

bit_t Control::getDestReg() {
    return m_destReg;
}

bit_t Control::getExtIM() {
    return m_extIM;
}

bit_t Control::getExtIMJump() {
    return m_extIMJump;
}

bit_t Control::getMemToReg() {
    return m_memToReg;
}

bit_t Control::getOrigAlu() {
    return m_origAlu;
}

bit_t Control::getOrigRegA() {
    return m_origRegA;
}

bit_t Control::getWriteMem() {
    return m_writeMem;
}

bit_t Control::getWriteReg() {
    return m_writeReg;
}

bit_t Control::isHalt() {
    return m_isHalt;
}

bit_t Control::isJump() {
    return m_isJump;
}

word_t Control::getCondJump() {
    return m_condJump;
}

word_t Control::getJumpType() {
    return m_jumpType;
}

word_t Control::getOpAlu() {
    return m_opAlu;
}
