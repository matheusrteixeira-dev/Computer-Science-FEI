; Atividade 01 - Exercício 03
; Execução passo a passo com endereçamento direto, imediato e indireto
; (enunciado em ../images/lab01_03.png).

MOV A, #00H
MOV 10H, #10B   ; RAM[10h] = 2 (binário)
MOV 11H, #10    ; RAM[11h] = 10 (decimal)
MOV 12H, #10H   ; RAM[12h] = 16 (hexadecimal)
MOV R0, #10H    ; R0 aponta para RAM[10h]

ADD A, R0       ; soma o ponteiro
ADD A, @R0      ; soma o conteúdo apontado
INC R0
ADD A, R0
ADD A, @R0
INC R0
ADD A, R0
ADD A, @R0
