; Atividade 01 - Exercício 01
; Transferência de dados entre registradores, RAM interna e acumulador.

MOV R1, #20h    ; R1 = 20h
MOV A, R1       ; A = R1
MOV 50h, #20h   ; RAM[50h] = 20h
MOV R2, A       ; R2 = A
INC R2          ; R2 = R2 + 1
DEC 50h         ; RAM[50h] = RAM[50h] - 1
MOV A, #0h      ; A = 0
