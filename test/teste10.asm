.module m0
.pseg
.global _main
; TESTE uRISC - Flags, Jumps condicionais e
;               incondicionais, instrucoes de
;               carregamento de constantes, operacoes
;               aritmeticas
; RESULTADO DO TESTE: nota de 0 a 10, que no final
;                     da execucao do programa, estara
;                     na posicao 1000 de memoria(3e8 em hexa)

; Instrucoes que saltam para as rotinas de tratamento de
; de interrupcoes
j RESET
j INT1
j INT2
j INT3

; Inicio do programa
RESET:
; Carrega registradores
loadlit r4, 0   ; r4 contera o score
lcl r0, LOWBYTE 32768  ; carrega 8000 em r0
lch r0, HIGHBYTE 32768 ;
lcl r1, LOWBYTE 56750  ; carrega ddae em r1
lch r1, HIGHBYTE 56750 ;
lcl r2, LOWBYTE 32746  ; carrega 7fea em r2
lch r2, HIGHBYTE 32746 ;
lcl r3, LOWBYTE 11207  ; carrega 2bc7 em r3
lch r3, HIGHBYTE 11207 ;

; -----------------------------------------
; Primeira bateria de teste:
; testa jump condicional quando a condicao
; e falsa

; Teste 1: ocorre overflow
add r6, r0, r0
jf.overflow T2    ; erro se saltar
inca r4, r4      ; OK ! Mais um ponto

T2:
; Teste 2: nao ocorre overflow
add r6, r3, r3
jt.overflow T3   ; erro se saltar
inca r4, r4      ; OK ! Mais um ponto

T3:
; Teste 3: resultado e negativo
sub r6, r3, r2
jf.neg T4         ; erro se saltar
inca r4, r4      ; OK ! Mais um ponto

T4:
; Teste 4: resultado nao e negativo
sub r6, r2, r3
jt.neg T5         ; erro se saltar
inca r4, r4      ; OK ! Mais um ponto

T5:
; Teste 5: resultado e zero
sub r6, r2, r2
jf.zero T6       ; erro se saltar
inca r4, r4      ; OK ! Mais um ponto

T6:
; Teste 6: resultado nao e zero
sub r6, r3, r2
jt.zero T7       ; erro se saltar
inca r4, r4      ; OK ! Mais um ponto

T7:
; Teste 7: resultado e negativo ou zero
sub r6, r3, r3
jf.negzero T8    ; erro se saltar
inca r4, r4      ; OK ! Mais um ponto

T8:
; Teste 8: resultado nao e negativo e nem igual a zero
sub r6, r2, r3
jt.negzero T9    ; erro se saltar
inca r4, r4      ; OK ! Mais um ponto

T9:
; Teste 9: ocorre carry
add r6, r0, r0
jf.carry T10     ; erro se saltar
inca r4, r4      ; OK ! Mais um ponto

T10:
; Teste 10: nao ocorre carry
add r6, r2, r3
jt.carry T11     ; erro se saltar
inca r4, r4      ; OK ! Mais um ponto

; -----------------------------------------
; Segunda bateria de teste:
; testa jump condicional quando a condicao
; e verdadeira

T11:
; Teste 1: ocorre overflow
sub r6, r0, r2
jt.overflow T11a ; OK se saltar
j T12
T11a:
inca r4, r4      ; OK ! Mais um ponto

T12:
; Teste 2: nao ocorre overflow
add r6, r3, r3
jf.overflow T12a ; OK se saltar
j T13
T12a:
inca r4, r4      ; OK ! Mais um ponto

T13:
; Teste 3: resultado e negativo
sub r6, r3, r2
jt.neg T13a      ; OK se saltar
j T14
T13a:
inca r4, r4      ; OK ! Mais um ponto

T14:
; Teste 4: resultado nao e negativo
sub r6, r2, r3
jf.neg T14a      ; OK se saltar
j T15
T14a:
inca r4, r4      ; OK ! Mais um ponto

T15:
; Teste 5: resultado e zero
sub r6, r6, r6
jt.zero T15a     ; OK se saltar
j T16
T15a:
inca r4, r4      ; OK ! Mais um ponto

T16:
; Teste 6: resultado nao e zero
subdec r6, r3, r2
jf.zero T16a     ; OK se saltar
j T17
T16a:
inca r4, r4      ; OK ! Mais um ponto

T17:
; Teste 7: resultado e negativo ou zero
sub r6, r1, r1
jt.negzero T17a  ; OK se saltar
j T18
T17a:
inca r4, r4      ; OK ! Mais um ponto

T18:
; Teste 8: resultado nao e negativo e nem igual a zero
sub r6, r2, r3
jf.negzero T18a  ; OK se saltar
j T19
T18a:
inca r4, r4      ; OK ! Mais um ponto

T19:
; Teste 9: ocorre carry
add r6, r0, r1
jt.carry T19a    ; OK se saltar
j T20
T19a:
inca r4, r4      ; OK ! Mais um ponto

T20:
; Teste 10: nao ocorre carry
add r6, r2, r3
jf.carry T20a    ; OK se saltar
j FIM
T20a:
inca r4, r4      ; OK ! Mais um ponto

FIM:
asr r4, r4
loadlit r5, 1000 ; resultado do teste na posicao 0x3e8 de memoria
store r5, r4
L: j L
INT1: jr r7
INT2: jr r7
INT3: jr r7
.end
