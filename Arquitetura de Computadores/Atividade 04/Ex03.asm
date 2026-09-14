; Atividade 04 - Exercício 03
; Sub-rotina de atraso de 8000 ciclos de máquina (MC) com laços aninhados.

DELAY:
    MOV R0, #195        ; 1 MC

ROT1:
    MOV R1, #19         ; 1 MC

ROT2:
    DJNZ R1, ROT2       ; 2 MC * R1
    DJNZ R0, ROT1       ; 2 MC  -> laço externo: R0 * (1 + 2 * R1 + 2)
    NOP                 ; 1 MC
    NOP                 ; 1 MC
    RET                 ; 2 MC

; T = 1 + 195 * (1 + 2 * 19 + 2) + 1 + 1 + 2
;   = 5 + 195 * 41 = 8000 MC
