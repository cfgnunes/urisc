#include "ControlJump.hpp"

ControlJump::ControlJump() {
    m_origPC = 0;
}

void ControlJump::execute(bit_t isJump, word_t condJump, word_t jumpType,
                          bit_t neg, bit_t zero, bit_t carry, bit_t negZero,
                          bit_t trueBit, bit_t overflow) {
    // isJump   - especifica se a instrução é de Jump ou não.
    // condJump - especifica qual condição de jump condicional será testada.
    // jumpType - indica qual tipo de jump (JumpAndLink e register,
    //            condicional true ou false, incondicional)

    m_origPC = 0;
    // Verifica se a instrução é de jump.
    if (isJump)
        // Determina qual é o tipo de jump.
        switch (jumpType) {
        case (JUMP_TYPE_FALSE):
            // Caso for jump condicional false,
            // verifica as flags e seta o valor de origPC.
            switch (condJump) {
            case (COND_JUMP_NEG):
                if (!neg)
                    m_origPC = 1;
                break;
            case (COND_JUMP_ZERO):
                if (!zero)
                    m_origPC = 1;
                break;
            case (COND_JUMP_CARRY):
                if (!carry)
                    m_origPC = 1;
                break;
            case (COND_JUMP_NEG_ZERO):
                if (!negZero)
                    m_origPC = 1;
                break;
            case (COND_JUMP_TRUE):
                if (!trueBit)
                    m_origPC = 1;
                break;
            case (COND_JUMP_OVERFLOW):
                if (!overflow)
                    m_origPC = 1;
                break;
            default:
                break;
            }
            break;
        case (JUMP_TYPE_TRUE):
            // Caso for jump condicional true,
            // verifica as flags e seta o valor de origPC.
            switch (condJump) {
            case (COND_JUMP_NEG):
                if (neg)
                    m_origPC = 1;
                break;
            case (COND_JUMP_ZERO):
                if (zero)
                    m_origPC = 1;
                break;
            case (COND_JUMP_CARRY):
                if (carry)
                    m_origPC = 1;
                break;
            case (COND_JUMP_NEG_ZERO):
                if (negZero)
                    m_origPC = 1;
                break;
            case (COND_JUMP_TRUE):
                if (trueBit)
                    m_origPC = 1;
                break;
            case (COND_JUMP_OVERFLOW):
                if (overflow)
                    m_origPC = 1;
                break;
            default:
                break;
            }
            break;

        case (JUMP_TYPE_UNCONDITIONAL):
            // Caso for Jump incondicional escolhe a 2 entrada do Mux6.
            m_origPC = 1;
            break;

        case (JUMP_TYPE_JAL_JR):
            // Caso for Jump link ou register escolhe a 3 entrada do Mux6.
            m_origPC = 2;
            break;
        default:
            break;
        }
}

// Gets.

word_t ControlJump::getOrigPC() {
    return m_origPC;
}
