; Atividade 02 - Exercício 04
; Soma de 16 bits: (R3:R2) + (R1:R0) = R7:R6:R5 (R7 recebe o carry final).

MOV A, R2
ADD A, R0       ; byte menos significativo
MOV R5, A
MOV A, R3
ADDC A, R1      ; byte mais significativo + carry
MOV R6, A
CLR A
ADDC A, #0      ; propaga o carry final
MOV R7, A
