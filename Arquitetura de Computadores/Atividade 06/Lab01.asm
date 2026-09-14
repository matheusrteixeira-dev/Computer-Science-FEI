; Atividade 06 - Laboratório 01
; Geração de sinais em P1.0 e P1.4 por varredura (polling) do temporizador 0
; no modo 2 (enunciado em ../images/lab06_01.png).
; Recarga 156 -> 100 contagens; recarga 101 -> 155 contagens.

CONFIG:
    MOV TMOD, #2        ; T/C0 no modo 2 (8 bits com recarga automática)
    SETB TR0            ; liga o T/C0

ROT:
    MOV TH0, #156       ; valor de recarga
    MOV TL0, #156       ; valor da primeira contagem
    JNB TF0, $          ; aguarda o bit de estouro
    CLR TF0             ; apaga o bit de estouro
    CPL P1.0            ; complementa P1.0

ROT1:
    MOV TH0, #101
    MOV TL0, #101
    JNB TF0, $          ; aguarda o bit de estouro
    CLR TF0             ; apaga o bit de estouro
    CPL P1.4            ; complementa P1.4
    SJMP ROT            ; fecha o laço
