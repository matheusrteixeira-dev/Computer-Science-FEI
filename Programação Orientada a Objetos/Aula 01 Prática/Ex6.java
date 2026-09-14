package POO;

import java.util.Scanner;

/**
 * Exercício 6: Flíper (enunciado em ../images/lab01_06.png).
 *
 * <p>Dadas as posições das portinhas P e R (0 = esquerda, 1 = direita), informa em qual
 * caminho (A, B ou C) a bolinha cai.
 */
public class Ex6 {
    private final Scanner input;

    public Ex6(Scanner input) {
        this.input = input;
    }

    /** Retorna o caminho percorrido pela bolinha para as posições das portinhas. */
    public static char caminho(int p, int r) {
        if (p == 0) {
            return 'C';
        }
        return (r == 0) ? 'B' : 'A';
    }

    public void calculaCaminho() {
        System.out.print("Posicao da portinha P: ");
        int p = input.nextInt();
        System.out.print("Posicao da portinha R: ");
        int r = input.nextInt();

        System.out.printf("A bolinha cairá no caminho %c%n%n", caminho(p, r));
    }
}
