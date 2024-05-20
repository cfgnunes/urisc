/* Emulador de processador uRISC
 *
 * Autor: Cristiano Fraga G. Nunes <cfgnunes@gmail.com>
 * Data: 31/10/2010
 */

#include "ALU.hpp"
#include "Add.hpp"
#include "BankRegister.hpp"
#include "Constants.hpp"
#include "Control.hpp"
#include "ControlJump.hpp"
#include "Memory.hpp"
#include "Mux.hpp"
#include "Util.hpp"
#include <iostream>

using namespace std;
using namespace Util;

int main(int argc, char **argv) {
    // Instancia os componentes do data path.
    Add add1, add2;
    ALU alu;
    BankRegister bankRegister;
    Control control;
    ControlJump controlJump;
    Memory dataMemory, instrMemory;
    Mux mux1, mux2, mux3, mux4, mux5, mux6, mux7, mux8;

    // Componente: Contador de programa - pc.
    word_t pc{0};

    cout << "Emulador uRisc" << endl
         << "Autor: Cristiano Fraga G. Nunes <cfgnunes@gmail.com>" << endl
         << endl;

    // Verifica se foi passado por linha de comando o nome do arquivo.
    if (argc != 2) {
        cout << "É necessário definir um arquivo para a simulação." << endl
             << "Uso: urisc <ARQUIVO>" << endl
             << endl;
        return EXIT_SUCCESS;
    }

    // Carrega as instruções na memória (lê o arquivo de instruções).
    try {
        instrMemory.loadFile(string(argv[1]));
    } catch (std::exception &e) {
        cout << "Erro ao abrir o arquivo: Arquivo não encontrado!" << endl;
        return EXIT_FAILURE;
    }

    // Loop principal: representação real do data path e suas conexões.
    while (true) {
        // Componente: Memória de instruções.
        instrMemory.setAddress(pc);

        // Componente: Controle.
        control.execute(instrMemory.getData());

        // Finaliza quando encontrar uma instrução de halt.
        if (control.isHalt()) {
            cout << "Halt executado!" << endl;
            break;
        }

        // Componente: Mux1.
        mux1.mux2x1(selectBits(instrMemory.getData(), 5, 3),
                    selectBits(instrMemory.getData(), 13, 11),
                    control.getOrigRegA());

        // Componente: Mux2.
        mux2.mux2x1(selectBits(instrMemory.getData(), 13, 11), 7,
                    control.getDestReg());

        // Componente: Mux7.
        mux7.mux2x1(signalExtend(instrMemory.getData(), 11, 0),
                    signalExtend(instrMemory.getData(), 7, 0),
                    control.getExtIMJump());

        // Componente: Add1.
        add1.execute(pc, 1);

        // Componente: Add2.
        add2.execute(add1.getOutput(), mux7.getOutput());

        // Componente: Mux8.
        mux8.mux2x1(signalExtend(instrMemory.getData(), 7, 0),
                    signalExtend(instrMemory.getData(), 10, 0),
                    control.getExtIM());

        // Componente: Banco de registradores (etapa de leitura).
        bankRegister.execute(mux1.getOutput(),
                             selectBits(instrMemory.getData(), 2, 0),
                             mux2.getOutput(), mux3.getOutput(), false);

        // Componente: Mux4.
        mux4.mux2x1(bankRegister.getValueB(), mux8.getOutput(),
                    control.getOrigAlu());

        // Componente: ALU.
        alu.execute(bankRegister.getValueA(), mux4.getOutput(),
                    control.getOpAlu());

        // Componente: Controle Jump.
        controlJump.execute(control.isJump(), control.getCondJump(),
                            control.getJumpType(), alu.getNeg(), alu.getZero(),
                            alu.getCarry(), alu.getNegZero(), alu.getTrueBit(),
                            alu.getOverflow());

        // Componente: Mux6.
        mux6.mux3x1(add1.getOutput(), add2.getOutput(),
                    bankRegister.getValueB(), controlJump.getOrigPC());

        // Componente: Memória de dados.
        dataMemory.write(bankRegister.getValueA(), bankRegister.getValueB(),
                         control.getWriteMem());

        // Redireciona os dados da memória de dados para
        // a memória de instruções, simulando uma memória única.
        instrMemory.write(bankRegister.getValueA(), bankRegister.getValueB(),
                          control.getWriteMem());

        // Componente: Mux5.
        mux5.mux2x1(dataMemory.getData(), static_cast<word_t>(alu.getOutput()),
                    control.getMemToReg());

        // Componente: Mux3.
        mux3.mux2x1(static_cast<word_t>(pc + 1u), mux5.getOutput(),
                    control.getDataDestReg());

        // Componente: Banco de registradores (etapa de escrita, se houver).
        bankRegister.execute(
            mux1.getOutput(), selectBits(instrMemory.getData(), 2, 0),
            mux2.getOutput(), mux3.getOutput(), control.getWriteReg());

        // Exibe os valores na tela.
        cout << hex << "PC=" << pc << "\tA=" << bankRegister.getValueA()
             << "\tB=" << bankRegister.getValueB()
             << "\tAluOutput=" << alu.getOutput() << "\tR1=" << dec
             << bankRegister.getRegisters()[1] << "\tR4=" << dec
             << bankRegister.getRegisters()[4] << endl;

        // Escrita no PC.
        pc = mux6.getOutput();
    }

    // Exibe o resultado do teste.
    cout << dec << endl
         << "Resultado do teste: " << dataMemory.getMemory()[0x3e8] << endl;

    return EXIT_SUCCESS;
}
