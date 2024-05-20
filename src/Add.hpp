#ifndef ADD_HPP
#define ADD_HPP

#include "Constants.hpp"

class Add {
  public:
    Add();

    void execute(word_t valueA, word_t valueB);

    // Gets.
    word_t getOutput();

  private:
    word_t m_output;
};

#endif // ADD_HPP
