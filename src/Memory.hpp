#ifndef MEMORY_HPP
#define MEMORY_HPP

#include "Constants.hpp"
#include <iostream>

class Memory {
  public:
    Memory();

    void write(word_t address, word_t writeData, bit_t writeEnable);
    void setAddress(word_t address);
    void loadFile(const std::string &filename);

    // Gets.
    word_t getData();
    word_t *getMemory();

  private:
    word_t m_data;
    word_t m_memory[65536]{};
};

#endif // MEMORY_HPP
