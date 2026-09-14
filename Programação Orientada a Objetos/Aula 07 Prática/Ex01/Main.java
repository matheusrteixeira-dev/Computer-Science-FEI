package Ex01;

import java.util.Scanner;

/**
 * Aula 07 - Exercício 1: tratamento de exceções personalizadas na validação de CPF.
 *
 * @author Matheus Teixeira
 */
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("Entrada de dados\n=======================================");
        System.out.println("Digite o nome: ");
        String nome = input.nextLine();
        System.out.println("Digite o sobrenome: ");
        String sobrenome = input.nextLine();
        System.out.println("Digite a idade: ");
        int idade = Integer.parseInt(input.nextLine());

        Pessoa pessoa = null;
        while (pessoa == null) {
            System.out.println("Digite o CPF: ");
            try {
                pessoa = new Pessoa(nome, sobrenome, idade, input.nextLine());
            } catch (CpfException ex) {
                System.out.println("CPF inválido: " + ex.getMessage());
            }
        }

        System.out.println("Pessoa cadastrada: " + pessoa);
    }
}
