package Ex04;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * Aula 04 - Exercício 4: agenda telefônica em memória com inclusão, remoção e listagem.
 *
 * @author Matheus Teixeira
 */
public class Main {
    public static Scanner input;

    public static void exibeMenu() {
        System.out.printf(""
                + "\n=========================================================="
                + "\n n [Nova Entrada]"
                + "\n d [Apaga Registro da Agenda]"
                + "\n p [Imprime toda a agenda]"
                + "\n q [Sai do programa]"
                + "\n==========================================================");
    }

    public static void main(String[] args) {
        input = new Scanner(System.in);

        ArrayList<PhoneBook> pb = new ArrayList<>();
        boolean run = true;

        while (run) {
            exibeMenu();

            System.out.printf("\nDigite a opção: ");
            String choice = input.nextLine();

            switch (choice) {
                case "q":
                    System.out.printf("\nSaindo...\n");
                    run = false;
                    break;
                case "n":
                    System.out.printf("\nDigite o nome: ");
                    String nome = input.nextLine();
                    System.out.printf("\nDigite o telefone: ");
                    String telefone = input.nextLine();
                    pb.add(new PhoneBook(nome, telefone));
                    System.out.printf("\n Usuário criado com sucesso\n");
                    break;
                case "d":
                    System.out.printf("\nDigite o nome: ");
                    String nomeDelete = input.nextLine();
                    boolean removido = pb.removeIf(contato -> contato.getNome().equals(nomeDelete));
                    System.out.printf(removido ? "\nDeletado com sucesso...\n" : "\nContato não encontrado.\n");
                    break;
                case "p":
                    System.out.printf("\nImprimindo todos...\n");
                    for (PhoneBook element : pb) {
                        System.out.println(element.toString() + "\n");
                    }
                    break;
                default:
                    break;
            }
        }
    }
}
