; Atividade 07 - Laboratório 02
; Onda quadrada em P1.0 com período de 10 ms usando a interrupção do
; temporizador 0 no modo 1 (enunciado em ../images/lab07_02.png).

ORG 0000h
    LJMP START          ; pula incondicionalmente para START

ORG 000Bh               ; vetor de interrupção do temporizador 0
INT_TEMP0:
    MOV TH0, #0ECh      ; EC78h = 60536 -> 5000 contagens (5 ms)
    MOV TL0, #78h
    CPL P1.0            ; complementa P1.0
    RETI                ; retorna da interrupção

ORG 0080h
START:
    MOV TMOD, #1        ; T/C0 no modo 1 (16 bits)
    MOV TH0, #0ECh
    MOV TL0, #78h
    SETB EA             ; habilita as interrupções
    SETB ET0            ; habilita a interrupção do T/C0
    SETB TR0            ; liga o T/C0
    SJMP $
