; Atividade 07 - Laboratório 03
; T/C0 como contador de eventos externos (pino T0): a cada 20 pulsos,
; a interrupção complementa P1.7.

ORG 0000h
    LJMP START          ; pula incondicionalmente para START

ORG 000Bh               ; vetor de interrupção do T/C0
INT_TEMP0:
    CPL P1.7            ; complementa P1.7
    RETI                ; retorna da interrupção

ORG 0080h
START:
    MOV TMOD, #00001110b ; T/C0: GATE = 1, C/T = 1 (contador), modo 2
    MOV TH0, #236       ; recarga: 256 - 236 = 20 eventos
    MOV TL0, #236
    SETB EA             ; habilita as interrupções
    SETB ET0            ; habilita a interrupção do T/C0
    SETB TR0            ; liga o T/C0 (com GATE = 1, conta apenas com INT0 em nível alto)
    SJMP $
