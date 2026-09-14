; Atividade 02 - Exercício 01
; Leitura de uma constante armazenada na memória de programa (ROM).

ORG 0000h
    MOV A, #0           ; deslocamento dentro da tabela
    MOV DPTR, #0050h    ; DPTR aponta para a constante
    MOVC A, @A+DPTR     ; A = ROM[DPTR + A]
    MOV R2, A           ; R2 = 10
    SJMP $

ORG 0050h
    DB 10
