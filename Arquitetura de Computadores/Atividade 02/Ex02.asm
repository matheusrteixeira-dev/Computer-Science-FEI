; Atividade 02 - Exercício 02
; Uso de constantes (EQU), endereçamento direto e troca de conteúdo (XCH).

VALOR EQU 30h

MOV 50h, #VALOR     ; RAM[50h] = 30h
MOV A, #0FFh        ; A = FFh
XCH A, VALOR        ; troca A com RAM[30h]
MOV R2, #VALOR      ; R2 = 30h
