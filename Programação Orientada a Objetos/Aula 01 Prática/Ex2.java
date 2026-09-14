package POO;

import java.util.Scanner;

/** Exercício 2: lê três números e os exibe em ordem decrescente. */
public class Ex2 {
    private final Scanner input;
    private final int[] lista = new int[3];

    public Ex2(Scanner input) {
        this.input = input;
    }

    public void ordenaDecrescente() {
        leNumeros();
        ordena();
        imprime();
    }

    private void leNumeros() {
        String[] ordinais = {"primeiro", "segundo", "terceiro"};
        for (int i = 0; i < lista.length; i++) {
            System.out.printf("Digite o %s numero: ", ordinais[i]);
            lista[i] = input.nextInt();
        }
    }

    /** Ordenação por seleção em ordem decrescente. */
    private void ordena() {
        for (int i = 0; i < lista.length; i++) {
            for (int j = i + 1; j < lista.length; j++) {
                if (lista[i] < lista[j]) {
                    int temp = lista[i];
                    lista[i] = lista[j];
                    lista[j] = temp;
                }
            }
        }
    }

    private void imprime() {
        System.out.print("Ordem:");
        for (int valor : lista) {
            System.out.printf(" %3d", valor);
        }
        System.out.println();
    }
}
