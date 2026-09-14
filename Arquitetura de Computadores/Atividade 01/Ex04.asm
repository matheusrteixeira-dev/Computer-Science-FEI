; Atividade 01 - Exercício 04
; Expressões aritméticas. Cada item assume A = 00h no início.

; A = A + R1
ADD A, R1

; A = R0 + R1
ADD A, R1
ADD A, R0

; A = R0 + 1
ADD A, R0
INC A

; A = R0 - 1
ADD A, R0
DEC A

; R2 = R0 + R1
ADD A, R0
ADD A, R1
MOV R2, A

; R2 = RAM[R0] + RAM[R1]
ADD A, @R0
ADD A, @R1
MOV R2, A
