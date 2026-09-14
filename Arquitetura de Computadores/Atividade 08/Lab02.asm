; Atividade 08 - Laboratório 02
; Contador crescente/decrescente exibido em P1:
; INT0 incrementa e INT1 decrementa (ambas sensíveis à borda de descida).

ORG 0000h
    LJMP START          ; pula incondicionalmente para START

ORG 0003h               ; vetor da interrupção externa 0
INT_EXT0:
    INC R7              ; incrementa o contador
    MOV P1, R7
    CLR IE0
    RETI

ORG 0013h               ; vetor da interrupção externa 1
INT_EXT1:
    DEC R7              ; decrementa o contador
    MOV P1, R7
    CLR IE1
    RETI

ORG 0080h
START:
    MOV R7, #0          ; zera o contador
    SETB EA             ; habilita as interrupções
    SETB EX0            ; habilita a interrupção externa 0
    SETB EX1            ; habilita a interrupção externa 1
    SETB IT0            ; INT0 sensível à borda de descida
    SETB IT1            ; INT1 sensível à borda de descida
    SJMP $
