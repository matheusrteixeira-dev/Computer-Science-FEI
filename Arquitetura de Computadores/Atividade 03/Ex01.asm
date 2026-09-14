; Atividade 03 - Exercício 01
; Uso dos bancos de registradores (RS0/RS1): inicializa os bancos 0 e 1,
; soma os registradores do banco 1 e grava o resultado em R0 do banco 3.

; Banco 0
MOV R0, #02h
MOV R1, #02h
MOV R2, #01h
MOV R3, #01h
MOV R4, #09h
MOV R5, #00h
MOV R6, #00h
MOV R7, #01h

; Banco 1
SETB RS0
MOV R0, #02h
MOV R1, #02h
MOV R2, #01h
MOV R3, #01h
MOV R4, #09h
MOV R5, #00h
MOV R6, #00h
MOV R7, #01h

CLR A
ADD A, R0
ADD A, R1
ADD A, R2
ADD A, R3
ADD A, R4
ADD A, R5
ADD A, R6
ADD A, R7

; Banco 3 (RS0 = 1, RS1 = 1)
SETB RS1
MOV R0, A
