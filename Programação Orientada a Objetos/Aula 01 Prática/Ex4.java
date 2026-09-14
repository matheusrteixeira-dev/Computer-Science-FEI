package POO;

import java.util.Scanner;

/** Exercício 4: lê 20 números e conta quantos são positivos. */
public class Ex4 {
    private static final int QUANTIDADE = 20;
    private final Scanner input;

    public Ex4(Scanner input) {
        this.input = input;
    }

    public void contaPositivos() {
        int positivos = 0;

        for (int i = 1; i <= QUANTIDADE; i++) {
            System.out.printf("Digite o numero %d: ", i);
            float num = input.nextFloat();

            if (num > 0.0f) {
                System.out.printf("POSITIVO: %.2f%n", num);
                positivos++;
            }
        }

        System.out.printf("Quantidade de numeros positivos: %d%n%n", positivos);
    }
}
