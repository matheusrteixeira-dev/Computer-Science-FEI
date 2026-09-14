; Atividade 09 - Laboratório 09
; Contador de 0 a 9 em display de 7 segmentos (anodo comum) conectado a P1.
; Cada pulso na interrupção externa 0 avança um dígito (enunciado em ../images/lab09_01.png).

ORG 0000h
    LJMP START

ORG 0003h               ; vetor da interrupção externa 0
INT_0:
    ACALL COMP
    CLR IE0
    RETI

ORG 0060h
; Reinicia o índice ao passar do dígito 9 e exibe o próximo dígito.
COMP:
    MOV A, R2
    CJNE A, #0, PROXIMO_DIGITO
    MOV R2, #10         ; volta para o dígito 0
    ACALL PROXIMO_DIGITO
    RET

; Decrementa o índice R2 e envia o código de 7 segmentos correspondente para P1.
PROXIMO_DIGITO:
    DEC R2
    MOV A, R2
    MOV DPTR, #TABELA
    MOVC A, @A+DPTR
    MOV P1, A
    RET

ORG 0080h
START:
    MOV R2, #10
    SETB EA             ; habilita as interrupções
    SETB EX0            ; habilita a interrupção externa 0
    SJMP $

; Códigos de 7 segmentos (anodo comum), do índice 0 ao 9: dígitos 9, 8, ..., 0.
TABELA:
    DB 98H, 80H, 0F8H, 83H, 92H, 99H, 0B0H, 0A4H, 0F9H, 0C0H
