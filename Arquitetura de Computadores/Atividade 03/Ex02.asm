; Atividade 03 - Exercício 02
; Deslocamento circular de um único bit em nível baixo na porta P1.

    MOV A, #0FEh    ; 1111 1110b

ROT:
    RL A            ; rotaciona para a esquerda
    MOV P1, A
    SJMP ROT
