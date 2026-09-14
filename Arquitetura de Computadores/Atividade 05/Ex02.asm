; Atividade 05 - Exercício 02
; Encontra o maior elemento de um vetor de 9 posições (RAM[30h..38h])
; e o armazena em RAM[39h].

    MOV 30h, #2h
    MOV 31h, #2h
    MOV 32h, #1h
    MOV 33h, #1h
    MOV 34h, #9h
    MOV 35h, #0h
    MOV 36h, #0h
    MOV 37h, #1h
    MOV 38h, #0h
    MOV 39h, #0h        ; maior valor encontrado até o momento

LEITURA:
    MOV R0, #30h        ; início do vetor
    MOV R1, #9h         ; tamanho do vetor

PROXIMO:
    MOV A, @R0
    ACALL CONFERE
    INC R0
    DJNZ R1, PROXIMO
    SJMP $

; Se A >= RAM[39h], substitui o maior valor por A.
CONFERE:
    CLR C
    MOV R6, A           ; cópia temporária do elemento atual
    SUBB A, 39h
    JNC SUBSTITUI
    RET

SUBSTITUI:
    MOV 39h, R6
    RET
