; Atividade 01 - Exercício 02
; Operações aritméticas simples com o acumulador.

; Letra A: R0 = A + R0
ADD A, R0
MOV R0, A

; Letra B: R1 = A + R1
ADD A, R1
MOV R1, A

; Letra C: R1 = A + (R1 + 1)
INC R1
ADD A, R1
MOV R1, A

; Letra D: A = A + RAM[R0]
ADD A, @R0
