package POO;

import java.util.Scanner;

/** Exercício 7: reajuste salarial por faixa (enunciado em ../images/lab01_07.png). */
public class Ex7 {
    private final Scanner input;

    public Ex7(Scanner input) {
        this.input = input;
    }

    /** Percentual de reajuste para o salário informado. */
    public static int percentualReajuste(float salario) {
        if (salario <= 400) {
            return 15;
        } else if (salario <= 800) {
            return 12;
        } else if (salario <= 1200) {
            return 10;
        } else if (salario <= 2000) {
            return 7;
        }
        return 4;
    }

    public void calculaReajuste() {
        System.out.print("Digite o salário atual: ");
        float salario = input.nextFloat();

        int percentual = percentualReajuste(salario);
        float reajuste = salario * percentual / 100f;

        System.out.printf("Novo salário: R$ %.2f%n", salario + reajuste);
        System.out.printf("Reajuste ganho: R$ %.2f%n", reajuste);
        System.out.printf("Em percentual: %d%%%n%n", percentual);
    }
}
