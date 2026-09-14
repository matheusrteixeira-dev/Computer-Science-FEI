package Ex02;

import java.io.IOException;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Aula 07 - Exercício 2: agenda telefônica persistida em arquivo texto (PhoneBook.txt),
 * com tratamento de exceções de entrada e saída.
 *
 * @author Matheus Teixeira
 */
public class Main {
    private static final Path ARQUIVO = Paths.get("PhoneBook.txt");
    private static final String SEPARADOR = ";";

    private static void menu() {
        System.out.print(""
                + "\n=========================================================="
                + "\n n [Nova entrada]"
                + "\n d [Apaga registro da agenda]"
                + "\n p [Imprime toda a agenda]"
                + "\n q [Sai do programa]"
                + "\n==========================================================");
    }

    /** Lê todos os contatos do arquivo (lista vazia se o arquivo ainda não existir). */
    private static List<PhoneBook> carregar() throws IOException {
        List<PhoneBook> contatos = new ArrayList<>();
        if (!Files.exists(ARQUIVO)) {
            return contatos;
        }
        for (String linha : Files.readAllLines(ARQUIVO, StandardCharsets.UTF_8)) {
            String[] partes = linha.split(SEPARADOR, 2);
            if (partes.length == 2) {
                contatos.add(new PhoneBook(partes[0], partes[1]));
            }
        }
        return contatos;
    }

    private static void salvar(List<PhoneBook> contatos) throws IOException {
        List<String> linhas = new ArrayList<>();
        for (PhoneBook contato : contatos) {
            linhas.add(contato.getNome() + SEPARADOR + contato.getTelefone());
        }
        Files.write(ARQUIVO, linhas, StandardCharsets.UTF_8);
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        boolean executando = true;

        while (executando) {
            menu();
            System.out.print("\nDigite a opção: ");
            String opcao = input.nextLine().trim();

            try {
                switch (opcao) {
                    case "q" -> {
                        System.out.println("\nSaindo...");
                        executando = false;
                    }
                    case "n" -> {
                        System.out.print("\nDigite o nome: ");
                        String nome = input.nextLine();
                        System.out.print("Digite o telefone: ");
                        String telefone = input.nextLine();

                        List<PhoneBook> contatos = carregar();
                        contatos.add(new PhoneBook(nome, telefone));
                        salvar(contatos);
                        System.out.println("\nContato criado com sucesso.");
                    }
                    case "d" -> {
                        System.out.print("\nDigite o nome: ");
                        String nome = input.nextLine();

                        List<PhoneBook> contatos = carregar();
                        boolean removido = contatos.removeIf(c -> c.getNome().equalsIgnoreCase(nome));
                        salvar(contatos);
                        System.out.println(removido ? "\nContato apagado." : "\nContato não encontrado.");
                    }
                    case "p" -> {
                        System.out.println("\nImprimindo todos...");
                        for (PhoneBook contato : carregar()) {
                            System.out.println(contato.getNome() + " - " + contato.getTelefone());
                        }
                    }
                    default -> System.out.println("\nOpção inválida.");
                }
            } catch (IOException e) {
                System.out.println("Erro ao acessar a agenda: " + e.getMessage());
            }
        }
    }
}
