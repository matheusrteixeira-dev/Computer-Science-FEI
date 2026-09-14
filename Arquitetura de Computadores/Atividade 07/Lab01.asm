; Atividade 07 - Laboratório 01
; Mesmos sinais da Atividade 06 (P1.0 e P1.4), agora gerados por interrupção
; dos temporizadores 0 e 1 no modo 2 (enunciado em ../images/lab07_01.png).

ORG 0000h
    LJMP START

ORG 000Bh               ; vetor de interrupção do temporizador 0
INT_TEMP0:
    CPL P1.0
    RETI

ORG 001Bh               ; vetor de interrupção do temporizador 1
INT_TEMP1:
    CPL P1.4
    RETI

ORG 0080h
START:
    MOV TMOD, #22h      ; T/C0 e T/C1 no modo 2 (recarga automática)
    MOV TH0, #156       ; recarga T/C0: 100 contagens
    MOV TL0, #156
    MOV TH1, #101       ; recarga T/C1: 155 contagens
    MOV TL1, #101
    SETB EA             ; habilita as interrupções
    SETB ET0            ; habilita a interrupção do T/C0
    SETB ET1            ; habilita a interrupção do T/C1
    SETB TR0            ; liga o T/C0
    SETB TR1            ; liga o T/C1
    SJMP $
