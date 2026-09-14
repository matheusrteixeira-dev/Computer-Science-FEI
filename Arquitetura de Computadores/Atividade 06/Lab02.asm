; Atividade 06 - Laboratório 02
; Forma de onda em P1.0 com o temporizador 0 no modo 1 (16 bits)
; (enunciado em ../images/lab06_02.png):
;   1 ms em nível alto, 10 ms em nível baixo, 3,5 ms em nível alto, 7 ms em nível baixo.

CONFIG:
    MOV TMOD, #1        ; T/C0 no modo 1
    MOV TH0, #0FCh      ; FC18h = 64536 -> 1000 contagens (1 ms)
    MOV TL0, #18h
    SETB TR0            ; liga o T/C0
    SETB P1.0

LB1:
    JNB TF0, $          ; aguarda o bit de estouro
    MOV TH0, #0D8h      ; D8F0h = 55536 -> 10000 contagens (10 ms)
    MOV TL0, #0F0h
    CLR TF0             ; apaga o bit de estouro
    CLR P1.0

LB2:
    JNB TF0, $
    CLR TF0
    SETB P1.0
    MOV TH0, #0F2h      ; F253h = 62035 -> 3501 contagens (~3,5 ms)
    MOV TL0, #53h

LB3:
    JNB TF0, $
    MOV TH0, #0E4h      ; E4A8h = 58536 -> 7000 contagens (7 ms)
    MOV TL0, #0A8h
    CLR TF0
    CLR P1.0

LB4:
    JNB TF0, $
    CLR TF0
    SETB P1.0
    MOV TH0, #0FCh      ; 1 ms
    MOV TL0, #18h
    SJMP LB1            ; reinicia o ciclo
