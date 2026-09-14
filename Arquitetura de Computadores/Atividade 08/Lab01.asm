; Atividade 08 - Laboratório 01
; Contador de pulsos na interrupção externa 0 (borda de descida), exibido em P1.

ORG 0000h
    LJMP START          ; pula incondicionalmente para START

ORG 0003h               ; vetor da interrupção externa 0
INT_EXT0:
    INC R7              ; incrementa o contador
    MOV P1, R7          ; exibe o contador em P1
    RETI                ; retorna da interrupção

ORG 0080h
START:
    MOV R7, #0          ; zera o contador
    SETB EA             ; habilita as interrupções
    SETB EX0            ; habilita a interrupção externa 0
    SETB IT0            ; sensível à borda de descida
    SJMP $
