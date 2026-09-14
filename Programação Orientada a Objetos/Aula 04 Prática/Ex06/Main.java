package Ex06;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * Aula 04 - Exercício 6: depósitos e saques em uma lista de contas correntes.
 *
 * @author Matheus Teixeira
 */
public class Main {
    public static Scanner input;

    public static void main(String[] args) {
        input = new Scanner(System.in);

        ArrayList<ContaCorrente> banco = new ArrayList<>();

        for (int i = 0; i < 10; i++) {
            banco.add(new ContaCorrente(10*i));
        }
        for (ContaCorrente i: banco) {
            i.depositar(1000);
            System.out.println(i.getSaldo());
            i.sacar(500);
            System.out.println(i.getSaldo());
            System.out.printf("=====================================\n");
        }
    }
}
