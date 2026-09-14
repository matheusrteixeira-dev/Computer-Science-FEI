; Atividade 05 - Exercício 01
; Percorre um vetor de 9 posições (RAM[30h..38h]) e envia para P1
; os elementos iguais a 9 ou a 3.

    MOV 30h, #2h
    MOV 31h, #2h
    MOV 32h, #1h
    MOV 33h, #1h
    MOV 34h, #9h
    MOV 35h, #0h
    MOV 36h, #0h
    MOV 37h, #1h
    MOV 38h, #0h

LEITURA:
    MOV R0, #30h        ; início do vetor
    MOV R1, #9h         ; tamanho do vetor

PROXIMO:
    MOV A, @R0
    CJNE A, #9h, TESTA_3
    MOV P1, A           ; elemento igual a 9
    SJMP CONTINUA

TESTA_3:
    CJNE A, #3h, CONTINUA
    MOV P1, A           ; elemento igual a 3

CONTINUA:
    INC R0
    DJNZ R1, PROXIMO
    SJMP $
