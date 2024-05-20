#include "Mux.hpp"

Mux::Mux() {
    m_output = 0;
}

void Mux::mux2x1(word_t data1, word_t data2, bit_t sel) {
    // Seleciona o dado que irá sair do Mux.
    if (sel == 0)
        m_output = data1;
    else
        m_output = data2;
}

void Mux::mux3x1(word_t data1, word_t data2, word_t data3, word_t sel) {
    // Seleciona os dados que irão sair do Mux.
    if (sel == 0)
        m_output = data1;
    else if (sel == 1)
        m_output = data2;
    else
        m_output = data3;
}

// Gets.

word_t Mux::getOutput() {
    return m_output;
}
