; Atividade 04 - Exercício 02
; Sub-rotina de atraso de 600 ciclos de máquina (MC).

DELAY:
    MOV R0, #199        ; 1 MC
ROT1:
    NOP                 ; 1 MC
    DJNZ R0, ROT1       ; 2 MC  -> laço: 199 * (1 + 2)
    RET                 ; 2 MC

; T = 1 + 199 * 3 + 2 = 600 MC
