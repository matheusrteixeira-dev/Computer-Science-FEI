package Ex03;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Aula 06 - Exercício 3: classe abstrata Agente e suas especializações (Empresário, Professor e
 * Advogado). Qualquer pessoa cadastrada pode ser "transformada" em agente.
 *
 * @author Matheus Teixeira
 */
public class Main {
    private static void menu() {
        System.out.println("Deseja realizar qual operação?\n");
        System.out.println("1 - Criar");
        System.out.println("2 - Listar");
        System.out.println("3 - Transformar em agente");
        System.out.println("0 - Sair");
    }

    private static void menuCriacao() {
        System.out.println("Deseja criar qual tipo de pessoa?");
        System.out.println("1 - Empresário");
        System.out.println("2 - Professor");
        System.out.println("3 - Advogado");
    }

    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        List<Agente> agentes = new ArrayList<>();
        boolean executando = true;

        while (executando) {
            menu();
            int operacao = Integer.parseInt(entrada.nextLine());

            switch (operacao) {
                case 1 -> {
                    menuCriacao();
                    int opcao = Integer.parseInt(entrada.nextLine());
                    System.out.println("Qual o nome?");
                    String nome = entrada.nextLine();

                    switch (opcao) {
                        case 1 -> {
                            System.out.println("Qual a empresa?");
                            agentes.add(new Empresario(entrada.nextLine(), nome));
                        }
                        case 2 -> {
                            System.out.println("Qual a escola?");
                            agentes.add(new Professor(entrada.nextLine(), nome));
                        }
                        case 3 -> {
                            System.out.println("Qual a OAB?");
                            agentes.add(new Advogado(entrada.nextLine(), nome));
                        }
                        default -> System.out.println("Tipo inválido.");
                    }
                }
                case 2 -> {
                    for (int i = 0; i < agentes.size(); i++) {
                        System.out.println("#" + (i + 1));
                        agentes.get(i).apresentacao();
                    }
                }
                case 3 -> {
                    System.out.println("Qual o número da pessoa que será transformada em agente?");
                    int indice = Integer.parseInt(entrada.nextLine());
                    if (indice >= 1 && indice <= agentes.size()) {
                        agentes.get(indice - 1).modeAgenteOn(); // despacho polimórfico
                    } else {
                        System.out.println("Número inválido.");
                    }
                }
                case 0 -> executando = false;
                default -> System.out.println("Operação inválida.");
            }
        }
        entrada.close();
    }
}
