package POO;

import java.util.Scanner;

/** Exercício 8: para cada um de cinco números, desenha uma barra com essa quantidade de asteriscos. */
public class Ex8 {
    private static final int QUANTIDADE = 5;
    private final Scanner input;

    public Ex8(Scanner input) {
        this.input = input;
    }

    public void desenhaHistograma() {
        for (int i = 1; i <= QUANTIDADE; i++) {
            System.out.printf("Digite o %dº numero: ", i);
            int num = input.nextInt();
            System.out.println("Conversão: " + "*".repeat(Math.max(0, num)));
        }
        System.out.println();
    }
}
