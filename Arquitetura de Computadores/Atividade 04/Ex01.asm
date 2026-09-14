; Atividade 04 - Exercício 01
; Zera as posições RAM[1..99] e calcula o tempo de execução em ciclos de máquina (MC).

ZERAR:
    CLR A               ; 1 MC
    MOV R0, #99         ; 1 MC

ROT:
    MOV @R0, A          ; 1 MC
    NOP                 ; 1 MC
    DJNZ R0, ROT        ; 2 MC  -> laço: 99 * (1 + 1 + 2)
    RET                 ; 2 MC

; T = 1 + 1 + 99 * 4 + 2 = 400 MC
