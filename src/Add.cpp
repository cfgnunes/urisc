#include "Add.hpp"

Add::Add() {
    m_output = 0;
}

void Add::execute(word_t valueA, word_t valueB) {
    m_output = static_cast<s_word_t>(valueA) + static_cast<s_word_t>(valueB);
}

// Gets.

word_t Add::getOutput() {
    return m_output;
}
