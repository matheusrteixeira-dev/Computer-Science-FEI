package Ex02;

import java.util.Scanner;

/**
 * Aula 06 - Exercício 2: polimorfismo com a classe abstrata Formas (enunciado em ../../images/lab06_02.png).
 *
 * @author Matheus Teixeira
 */
public class Main {
    public static void main(String[] args) {
        Formas forma;
        Scanner entrada = new Scanner(System.in);
        String formaEscolhida = entrada.nextLine();

        if (formaEscolhida.equals("Retangulo"))
            forma = new Retangulo(5, 4);
        else
            forma = new Circulo(5);

        forma.print();
        entrada.close();
    }
}
