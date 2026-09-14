; Atividade 02 - Exercício 03
; Divisão inteira R1 / R0: quociente em R5 e resto em R4.

MOV A, R1       ; dividendo
MOV B, R0       ; divisor
DIV AB          ; A = quociente, B = resto
MOV R5, A
MOV R4, B
