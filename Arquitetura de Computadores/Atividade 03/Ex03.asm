; Atividade 03 - Exercício 03
; Compara R3 e R4: grava o maior valor em R5 e o menor em R6.

    MOV R3, #08h
    MOV R4, #03h

    MOV A, R4
    CLR C
    SUBB A, R3          ; A = R4 - R3
    JNC R4_MAIOR        ; C = 0 -> R4 >= R3; C = 1 -> R4 < R3

R3_MAIOR:
    MOV A, R3
    MOV R5, A
    MOV A, R4
    MOV R6, A
    SJMP FIM

R4_MAIOR:
    MOV A, R4
    MOV R5, A
    MOV A, R3
    MOV R6, A

FIM:
    SJMP $
