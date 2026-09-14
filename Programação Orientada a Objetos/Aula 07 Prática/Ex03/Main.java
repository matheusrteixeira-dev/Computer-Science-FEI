package Ex03;

import java.util.Random;
import java.util.Scanner;

/**
 * Aula 07 - Exercício 3: padrões Factory e Singleton para escolher a saída (tela ou arquivo).
 *
 * @author Matheus Teixeira
 */
public class Main {
    public static Scanner input;

    public static void main(String[] args) {
        input = new Scanner(System.in);
        System.out.printf("\nDigite o nome: ");
        String nome = input.nextLine();
        Factory factory = Singleton.getInstance();

        Random value = new Random();
        Output output = factory.getOutput(value.nextInt(2));
        output.print(nome);
    }
}
