#include "Memory.hpp"
#include <fstream>
#include <sstream>

Memory::Memory() {
    m_data = 0;
    m_memory[65536] = {0};
}

void Memory::write(word_t address, word_t writeData, bit_t writeEnable) {
    // Lê o dado no endereço especificado.
    m_data = m_memory[address];

    // Se a flag de escrita de dado for alta,
    // escreve o dado no endereço especificado.
    if (writeEnable) {
        m_memory[address] = writeData;
    }
}

void Memory::setAddress(word_t address) {
    // Lê o dado no endereço especificado.
    m_data = m_memory[address];
}

void Memory::loadFile(const std::string &filename) {
    // Define o endereço inicial da memória de instruções.
    word_t address = 0;

    // Variáveis para a abertura do arquivo.
    std::string line;
    std::ifstream file(filename.c_str());
    size_t pos;
    word_t value{0};

    // Abre o arquivo e carrega na memória.
    if (file.is_open()) {
        while (file.good()) {
            // Le as linhas do arquivo.
            getline(file, line);

            // Se encontrar a string "address",
            // reposiciona o endereço da memória.
            pos = line.find("address");

            // Carrega uma linha de instrução.
            std::istringstream iss(line);

            if (pos != std::string::npos) {
                // Lê "address ".
                iss.str(line.substr(8, 4));

                // Lê o endereço.
                iss >> std::hex >> value;

                // Posiciona o endereço com o endereço encontrado.
                address = value;
            } else {
                // Converte a string para inteiro.
                iss >> std::hex >> value;

                // Guarda o dado na memória.
                m_memory[address] = value;

                // Posiciona o próximo endereço.
                address += 1;
            }
        }
        file.close();
    } else
        throw std::exception();
}

// Gets.

word_t Memory::getData() {
    return m_data;
}

word_t *Memory::getMemory() {
    return m_memory;
}
