package POO;

import java.util.Scanner;

/** Exercício 1: produto de três números inteiros. */
public class Ex1 {
    private final Scanner input;

    public Ex1(Scanner input) {
        this.input = input;
    }

    public void calculaProduto() {
        System.out.print("Digite o primeiro numero: ");
        int num1 = input.nextInt();

        System.out.print("Digite o segundo numero: ");
        int num2 = input.nextInt();

        System.out.print("Digite o terceiro numero: ");
        int num3 = input.nextInt();

        System.out.printf("Produto = %d%n", num1 * num2 * num3);
    }
}
