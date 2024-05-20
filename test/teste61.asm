.module m0
.pseg
.global _main
; TESTE uRISC - Flags, Jumps condicionais e
;               incondicionais, instrucoes de
;               carregamento de constantes, operacoes
;               aritmeticas
; RESULTADO DO TESTE: nota de 0 a 61(3d), que no final
;                     da execucao do programa, estara
;                     na posicao 1000 de memoria(3e8 em hexa)

j START

; Inicio do programa
START:

; -----------------------------------------------------
; TESTE DAS INSTRUÇÕES DE ALU
; -----------------------------------------------------

; Testa a instrução zeros
; Zera o contador de pontos = r4
ZEROS1:
zeros r4
jf.zero ZEROS2
inca r4, r4

ZEROS2:
zeros r1
zeros r2
zeros r3
zeros r5
zeros r6
or r7, r1, r2
or r7, r7, r3
or r7, r7, r5
or r7, r7, r6
jf.zero ZEROS3
inca r4, r4

ZEROS3:
zeros r1
jf.zero AND1
jf.negzero AND1
jt.carry AND1
jt.overflow AND1
inca r4, r4

; Testa a instrução and
AND1:
lcl r5, LOWBYTE 65280
lch r5, HIGHBYTE 65280 ; r5 = FF00
lcl r6, LOWBYTE 255
lch r6, HIGHBYTE 255 ; r6 = 00FF
and r1, r5, r6
jf.zero AND2
jf.negzero AND2
jt.carry AND2
jt.overflow AND2
inca r4, r4

AND2:
lcl r5, LOWBYTE 65535
lch r5, HIGHBYTE 65535 ; r5 = FFFF
lcl r6, LOWBYTE 65535
lch r6, HIGHBYTE 65535 ; r6 = FFFF
and r1, r5, r6
jt.zero AND3
jf.negzero AND3
jt.carry AND3
jt.overflow AND3
inca r4, r4 ; R4 = 5

AND3:
lcl r5, LOWBYTE 23435
lch r5, HIGHBYTE 23435 ; R5 = 5B8B
lcl r6, LOWBYTE 43534
lch r6, HIGHBYTE 43534; R6 = AA0E
lcl r7, LOWBYTE 2570
lch r7, HIGHBYTE 2570; R7 = 0A0A
and r3, r5, r6
sub r3, r3, r7
jf.zero ANDNOTA1
inca r4, r4; R4 = 6

; Testa andnota
ANDNOTA1:
andnota r3, r5, r6
lcl r7, LOWBYTE 40964
lch r7, HIGHBYTE 40964
sub r3, r3, r7
jf.zero ANDNOTA2
inca r4, r4

ANDNOTA2:
andnota r3, r6, r5
lcl r7, LOWBYTE 20865
lch r7, HIGHBYTE 20865
sub r3, r3, r7
jf.zero PASSA1
inca r4, r4

; Testa passa
PASSA1:
lcl r7, LOWBYTE 20865
lch r7, HIGHBYTE 20865
zeros r6
passa r6, r7
sub r3, r6, r7
jf.zero XOR1
inca r4, r4

; Testa xor
XOR1:
lcl r5, LOWBYTE 20685
lch r5, HIGHBYTE 20685
lcl r6, LOWBYTE 41685
lch r6, HIGHBYTE 41685
lcl r7, LOWBYTE 61976
lch r7, HIGHBYTE 61976
xor r3, r5, r6
sub r3, r3, r7
jf.zero OR1
inca r4, r4

; Testa or
OR1:
lcl r5, LOWBYTE 20685
lch r5, HIGHBYTE 20685
lcl r6, LOWBYTE 41685
lch r6, HIGHBYTE 41685
lcl r7, LOWBYTE 62173
lch r7, HIGHBYTE 62173
or r3, r5, r6
sub r3, r3, r7
jf.zero NOR1
inca r4, r4

; Testa nor
NOR1:
lcl r5, LOWBYTE 20685
lch r5, HIGHBYTE 20685
lcl r6, LOWBYTE 41685
lch r6, HIGHBYTE 41685
lcl r7, LOWBYTE 3362
lch r7, HIGHBYTE 3362
nor r3, r5, r6
sub r3, r3, r7
jf.zero XNOR1
inca r4, r4

; Testa xnor
XNOR1:
lcl r5, LOWBYTE 20685
lch r5, HIGHBYTE 20685
lcl r6, LOWBYTE 41685
lch r6, HIGHBYTE 41685
lcl r7, LOWBYTE 3559
lch r7, HIGHBYTE 3559
xnor r3, r5, r6
sub r3, r3, r7
jf.zero PASSNOTA1
inca r4, r4

; Testa passnota
PASSNOTA1:
lcl r5, LOWBYTE 20685
lch r5, HIGHBYTE 20685
lcl r6, LOWBYTE 41685
lch r6, HIGHBYTE 41685
lcl r7, LOWBYTE 44850
lch r7, HIGHBYTE 44850
passnota r3, r5
sub r3, r3, r7
jf.zero ORNOTB1
inca r4, r4

; Testa ornotb
ORNOTB1:
lcl r7, LOWBYTE 24047
lch r7, HIGHBYTE 24047
ornotb r3, r5, r6
sub r3, r3, r7
jf.zero NAND1
inca r4, r4

; Testa nand
NAND1:
lcl r7, LOWBYTE 65338
lch r7, HIGHBYTE 65338
nand r3, r5, r6
sub r3, r3, r7
jf.zero ONES1
inca r4, r4

; Testa ones... nao vou testar...por enquanto
ONES1:
ones r3

; Testa add, addinc, inca
ADD1:
lcl r5, LOWBYTE 30000
lch r5, HIGHBYTE 30000
lcl r6, LOWBYTE 2767
lch r6, HIGHBYTE 2767
lcl r7, LOWBYTE 32767
lch r7, HIGHBYTE 32767
add r3, r5, r6
jt.overflow ADD2
jt.neg ADD2
jt.negzero ADD2
jt.carry ADD2
jt.zero ADD2
sub r3, r3, r7
jf.zero ADD2
inca r4, r4

ADD2:
addinc r3, r5, r6
jf.overflow ADD3
jf.neg ADD3
jf.negzero ADD3
jt.carry ADD3
jt.zero ADD3
inca r2, r7
sub r3, r3, r2
jf.zero ADD3
inca r4, r4

ADD3:
inca r3, r7
jf.overflow ADD4
jf.neg ADD4
jf.negzero ADD4
jt.carry ADD4
jt.zero ADD4
sub r3, r3, r2
jf.zero ADD4
inca r4, r4

ADD4:
lcl r5, LOWBYTE 65535
lch r5, HIGHBYTE 65535
lcl r6, LOWBYTE 32768
lch r6, HIGHBYTE 32768
lcl r7, LOWBYTE 32767
lch r7, HIGHBYTE 32767
add r3, r5, r6
jf.overflow SUB1
jt.neg SUB1
jt.negzero SUB1
jf.carry SUB1
jt.zero SUB1
sub r3, r3, r7
jf.zero SUB1
inca r4, r4

; Testa sub, subdec, deca. Subdec e sub sao testadas mais p/frente
SUB1:
lcl r6, LOWBYTE 32768
lch r6, HIGHBYTE 32768
lcl r7, LOWBYTE 32767
lch r7, HIGHBYTE 32767
deca r3, r6
jf.overflow SUB2
jt.neg SUB2
jt.negzero SUB2
jf.carry SUB2
jt.zero SUB2
sub r3, r3, r7
jf.zero SUB2
inca r4, r4

SUB2:
; Testa lsl
LSL1:
lcl r6, LOWBYTE 32768
lch r6, HIGHBYTE 32768
zeros r0
inca r0, r0
lsl r0, r0
lsl r0, r0
lsl r0, r0
lsl r0, r0
lsl r0, r0
lsl r0, r0
lsl r0, r0
lsl r0, r0
lsl r0, r0
lsl r0, r0
lsl r0, r0
lsl r0, r0
lsl r0, r0
lsl r0, r0
lsl r0, r0
jt.overflow LSL2
jf.neg LSL2
jf.negzero LSL2
jt.carry LSL2
jt.zero LSL2
sub r3, r0, r6
jf.zero LSL2
inca r4, r4

LSL2:
lsl r0, r0
jt.overflow LSL3
jt.neg LSL2
jf.negzero LSL3
jf.carry LSL3
jf.zero LSL3
inca r4, r4

; Testa lsr
LSL3:
zeros r6
inca r6, r6
lcl r0, LOWBYTE 32768
lch r0, HIGHBYTE 32768
lsr r0, r0
lsr r0, r0
lsr r0, r0
lsr r0, r0
lsr r0, r0
lsr r0, r0
lsr r0, r0
lsr r0, r0
lsr r0, r0
lsr r0, r0
lsr r0, r0
lsr r0, r0
lsr r0, r0
lsr r0, r0
lsr r0, r0
jt.overflow LSL4
jt.neg LSL4
jt.negzero LSL4
jt.carry LSL4
jt.zero LSL4
sub r3, r0, r6
jf.zero LSL4
inca r4, r4

LSL4:
lcl r0, LOWBYTE 32768
lch r0, HIGHBYTE 32768
zeros r6
deca r6, r6
asr r0, r0
asr r0, r0
asr r0, r0
asr r0, r0
asr r0, r0
asr r0, r0
asr r0, r0
asr r0, r0
asr r0, r0
asr r0, r0
asr r0, r0
asr r0, r0
asr r0, r0
asr r0, r0
asr r0, r0
jt.overflow LSL5
jf.neg LSL5
jf.negzero LSL5
jt.carry LSL5
jt.zero LSL5
sub r3, r0, r6
jf.zero LSL5
inca r4, r4

LSL5:
lcl r6, LOWBYTE 32768
lch r6, HIGHBYTE 32768
lcl r0, LOWBYTE 1
lch r0, HIGHBYTE 1
asl r0, r0
asl r0, r0
asl r0, r0
asl r0, r0
asl r0, r0
asl r0, r0
asl r0, r0
asl r0, r0
asl r0, r0
asl r0, r0
asl r0, r0
asl r0, r0
asl r0, r0
asl r0, r0
asl r0, r0
jf.overflow LSL6
jf.neg LSL6
jf.negzero LSL6
jt.carry LSL6
jt.zero LSL6
sub r3, r0, r6
jf.zero LSL6
asl r0, r0
jf.carry LSL6
jf.overflow LSL6
inca r4, r4; r4 = 26, Ok até aqui!

LSL6:

; -----------------------------------------------------
; TESTE DAS INSTRUÇÕES DE CONSTANTES
; -----------------------------------------------------

; CONSTANTES - TESTE 1 - Testa loadlit. Carrega várias
; contantes nos registradores e faz comparações para
; determinar se elas foram carregadas corretamente.
zeros r6
zeros r5
inca r5, r5
loadlit r5, 2
loadlit r6, 3
subdec r7, r6, r5
jf.zero C1
inca r4, r4; r4 = 27

C1:
loadlit r5, 1023
loadlit r6, 1023
sub r5, r6, r6
jf.zero C2
inca r4, r4; r4 = 28

C2:
loadlit r5, 65535
inca r5, r5
jf.zero C3
inca r4, r4; r4 = 29

C3:
loadlit r5, 1
deca r5, r5
jf.zero C4
inca r4, r4; r4 = 30

; CONSTANTES - TESTE 2 - Testa lcl e lch. Carrega várias
; contantes nos registradores e faz comparações para
; determinar se elas foram carregadas corretamente.
C4:
lcl r6, LOWBYTE 0
lch r6, HIGHBYTE 0
passa r6, r6
jf.zero C5
inca r4, r4; r4 = 31

C5:
lcl r6, LOWBYTE 65535
lch r6, HIGHBYTE 65535
inca r6, r6
jf.zero C6
inca r4, r4; r4 = 32

; Testa se a metade superior de um registrador não
; é apagada em um lcl e verifica se a parte inferior
; foi carregada corretamente.
C6:
lcl r6, LOWBYTE 60355
lch r6, HIGHBYTE 60335; r6 = ebc3
passa r5, r6
lcl r6, LOWBYTE 65535
passa r3, r6
lcl r7, LOWBYTE 65280     ; 65280 = 0xff00 -> mascara
lch r7, HIGHBYTE 65280
and r5, r5, r7
and r6, r6, r7
xor r7, r5, r6
jf.zero mem0
inca r4, r4; r4 = 33

; -----------------------------------------------------
; TESTE DAS INSTRUÇÕES DE MEMÓRIA
; -----------------------------------------------------

; MEMÓRIA - TESTE 1 - Teste básico: escreve-se um
; valor na memória e em seguida realiza-se a leitura
; da posição de memória escrita. Compare-se o valor
; lido e o valor escrito. Se os valores forem
; iguais, o processador executou corretamente.
mem0:
loadlit r5, 1023
loadlit r6, 1000
store r6, r5      ; Escreve 1023 na posição de memória 1000
load r7, r6       ; Carrega o valor da posição de memória 1000 no r7
sub r6, r5, r7    ; Subtrai o valor lido do valor escrito na memória
jf.zero mem1      ; Se o resultado não for zero, MAL SINAL !!!
inca r4, r4       ; UFA ! Ganhei mais um ponto ! Esse foi díficil !
; r4 = 34

; MEMÓRIA - TESTE 2 - Teste do tamanho especificado
; da memória: é verificado se a posição mais alta de
; de memória, a 65535, está disponível. Além disso,
; como consequencia, verifica-se que o endereço
; de memória é tratado como inteiro sem sinal. Se este
; não for o caso, 65535 será -1 se o sinal for considerado
; e possivelmente um erro de execução ocorrerá.
mem1:
loadlit r6, 343         ; Coloca lixo em r6
lcl r6, LOWBYTE 65535   ; Carrega o valor 65535 (no r6) que o endereço
lch r6, HIGHBYTE 65535  ; mais alto de memória
store r6, r6            ; Escreve 65535 na posição de memória 65535
load r7, r6             ; Carrega o valor da posição de memória 65535 no r7
xor r6, r6, r7          ; Faz um xor entre o valor lido e o valor escrito
jf.zero mem2            ; Se o resultado não for zero -> Mais um erro
inca r4, r4             ; Por que este teste vale tão pouco ?
; r4 = 35

; MEMÓRIA - TESTE 3 - Teste do endereço mais baixo de memória (0).
; Este teste é muito fácil. Presente de natal antecipado. Verifica
; a posição de memória mais baixa (0) está disponível.
mem2:
loadlit r6, 343         ; Coloca lixo em r6
lcl r6, LOWBYTE 0       ; Carrega o valor 0 (no r6) que o endereço
lch r6, HIGHBYTE 0      ; mais alto de memória
store r6, r6            ; Escreve 0 na posição de memória 0
load r7, r6             ; Carrega o valor da posição de memória 0 no r7
xnor r6, r6, r7         ; Faz um xnor entre o valor lido e o valor escrito
inca r6, r6             ; r6 = 1 + !(0 ^ 0) = 1 - 1 = 0
jf.zero mem3            ; Se o resultado não for zero -> Mais um erro
inca r4, r4             ; Será que eu vou conseguir ?
mem3:
;Neste momento r4 deve ser igual a 36
; -----------------------------------------------------
; TESTE DAS INSTRUÇÕES DE JUMP
; -----------------------------------------------------

; Você fica tonto facilmente ? Se ficar, NÃO FAÇA ESTE TESTE

; JUMPS - TESTE 1 - Jumps incondicionais. Basicamente um
; conjunto de jump's que levam ao objetivo: ganhar mais um ponto.
j J0; PC = 017c        ; Começa a tortura !
GJ: inca r4, r4 ;PC = 017d Parabéns, você chegou ao final do
                       ; labirinto. Pegue o seu ponto !!!
j ENDJUMP; PC = 017e

J0:                    ; Início da longa caminhada !
j J3; PC = 017f
J1:
j GJ ;PC = 0180
J2:
j J5;PC = 0181
J3:                    ; Já está cansado ?
j J4;PC = 0182
J4:
j J2;PC = 0183
J5:
j J1;PC = 0184         ; Você está quase lá !

;r4 = 37

ENDJUMP:

; JUMPS - TESTE 2 - Testa jal e jr. Neste teste, uma função
; que incrementa o valor de r4 é chamada usando a instrução.
; Depois de executado o incremento, volta-se da função executando
; jr.
lcl r6, LOWBYTE testaJal ;PC = 0185
lch r6, HIGHBYTE testaJal
jal r6
inca r4, r4             ; OK ! Voltou direito da função.
;r4 = 39
j TJ3

testaJal:
inca r4, r4 ;PC = 018A    Este ponto é de graça !
;r4 = 38
jr r7                   ; retorna da função

; JUMPS - Teste 3 - Este teste só garante que não haverá trapaça nos
; jumps como, por exemplo, o processador nunca executar um jump. Neste
; caso, todos os pontos serão perdidos e será executado um HALT, ou
; seja, você ganhará ZERO !!!
TJ3:
j TJ4
zeros r4                ; Neste caso, todos os pontos são perdidos
BYEBYE: j BYEBYE        ; Termina o programa !!!

; JUMPS - Teste 4 - Testa JAL e JR novamente. Este teste é bem
; interessante. Em primeiro lugar, será escrita a instrução jr r7
; na posição de memória 65535 e a intrução inca r4, r4 na posição
; 65534. Em seguida, um jal para r6 (que conterá o valor 65534).
; Assim, a próxima instrução a ser executada será inca r4, r4
; e logo depois jr r7, o que levará o programa a intrução que segue
; jal r6. Vamos ao teste !
TJ4:
lcl r6, LOWBYTE 65535
lch r6, HIGHBYTE 65535
lcl r5, LOWBYTE 14343    ; 14343 é o código da instrução jr r7
lch r5, HIGHBYTE 14343
store r6, r5             ; Armazena jr r7 na última posição de memória
deca r6, r6              ; Coloca r6 = 65534
lcl r5, LOWBYTE 26400    ; 26400 é o código da instrução inca r4, r4
lch r5, HIGHBYTE 26400   ; Incrementa o número de pontos
store r6, r5             ; Armazena inca r4, r4 na penúltima posição
nop
nop
nop
jal r6
;inca r4, r4 : r4 = 40
;jr r7

; JUMPS - TESTE 5 - Testa jt.true e jf.false(nop). Outro labirinto !
jf.true ENDJUMP2        ; NOP !
jt.true J23             ; Começa a nova tortura !
GJ2: inca r4, r4        ; Parabéns, você chegou ao final do
                        ; segundo labirinto. Sorte de principiante.
jt.true ENDJUMP2

jt.true J23                   ; Labirinto 2 - A revanche !
J21:
jf.true ENDJUMP2
jt.true GJ2
J22:
jf.true ENDJUMP2
jt.true J25
J23:
jf.true ENDJUMP2
jt.true J24
J24:
jf.true ENDJUMP2
jt.true J22
J25:
jf.true ENDJUMP2
jt.true J21

ENDJUMP2:

; JUMPS - TESTE 6 - Testa jt.condicao (neg, zero, carry, overflow, negzero)
; neg - quando o flag é 0 e quando é 1
zeros r6
inca r6, r6
jt.neg JT2
inca r4, r4
JT2:
zeros r6
deca r6, r6
jt.neg JT2a
j JT3
JT2a:
inca r4, r4

; negzero - quando o flag é 0 e quando é 1
JT3:
zeros r6
inca r6, r6
jt.negzero JT4
inca r4, r4
JT4:
zeros r6
deca r6, r6
jt.negzero JT4a
j JT5
JT4a:
inca r4, r4

; carry - quando o flag é 0 e quando é 1
JT5:
lcl r6, LOWBYTE 32768
lch r6, HIGHBYTE 32768
passa r6, r6
jt.carry JT6
inca r4, r4

JT6:
add r6, r6, r6
jt.carry JT6a
j JT7
JT6a:
inca r4, r4

; overflow - quando o flag é 0 e quando é 1
JT7:
lcl r6, LOWBYTE 32000
lch r6, HIGHBYTE 32000
lcl r7, LOWBYTE 767
lch r7, HIGHBYTE 767
add r5, r6, r7
jt.overflow JT8
inca r4, r4

JT8:
addinc r5, r6, r7
jt.overflow JT8a
j JT9
JT8a:
inca r4, r4

; zero - quando o flag é 0 e quando é 1
JT9:
lcl r6, LOWBYTE 65535
lch r6, HIGHBYTE 65535
inca r6, r6
inca r6, r6
jt.zero JT10
inca r4, r4

JT10:
deca r6, r6
jt.zero JT10a
j JF1
JT10a:
inca r4, r4

; JUMPS - TESTE 7 - Testa jf.condicao (neg, zero, carry, overflow, negzero)
; neg - quando o flag é 0 e quando é 1
JF1:
lcl r6, LOWBYTE 32768
lch r6, HIGHBYTE 32768
deca r6, r6
jf.neg JF1a
j JF2
JF1a:
inca r4, r4

JF2:
subdec r6, r3, r3
jf.neg JF3
inca r4, r4

; negzero - quando o flag é 0 e quando é 1
JF3:
sub r6, r5, r5
inca r6, r6
jf.negzero JF3a
j JF4
JF3a:
inca r4, r4

JF4:
subdec r6, r5, r5
inca r6, r6
jf.negzero JF5
inca r4, r4

; carry - quando o flag é 0 e quando é 1
JF5:
lcl r6, LOWBYTE 32767
lch r6, HIGHBYTE 32767
lcl r7, LOWBYTE 32768
lch r7, HIGHBYTE 32768
add r6, r6, r7        ; r6 = 32767 + (-32768) -> não há carry
jf.carry JF5a
j JF6
JF5a:
inca r4, r4

JF6:
zeros r6
deca r6, r6
inca r6, r6   ; r6 = -1 + 1 -> carry
jf.carry JF7
inca r4, r4

; overflow - quando o flag é 0 e quando é 1
JF7:
lcl r6, LOWBYTE 32767
lch r6, HIGHBYTE 32767
lcl r7, LOWBYTE 32768
lch r7, HIGHBYTE 32768
addinc r6, r6, r7        ; r6 = 32767 + (-32768) + 1
jf.overflow JF7a
j JF8
JF7a:
inca r4, r4

JF8:
lcl r6, LOWBYTE 32767
lch r6, HIGHBYTE 32767
inca r6, r6
jf.overflow JF9
inca r4, r4

; zero - quando o flag é 0 e quando é 1
JF9:
lcl r6, LOWBYTE 32767
lch r6, HIGHBYTE 32767
lcl r7, LOWBYTE 32768
lch r7, HIGHBYTE 32768
add r6, r6, r7        ; r6 = 32767 + (-32768) = -1
jf.zero JF9a
j JF10
JF9a:
inca r4, r4

JF10:
lcl r6, LOWBYTE 32767
lch r6, HIGHBYTE 32767
lcl r7, LOWBYTE 32768
lch r7, HIGHBYTE 32768
addinc r6, r6, r7
jf.zero FINALIZE
inca r4, r4

FINALIZE:
loadlit r6, 1000
store r6, r4
ENDPROG: j ENDPROG

; se, por acaso, o programa chegar aqui, zera-se o total de pontos
zeros r4
loadlit r6, 1000
store r6, r4
.end
