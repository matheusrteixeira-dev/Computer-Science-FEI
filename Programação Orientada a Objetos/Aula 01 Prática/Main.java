package POO;

import java.util.Scanner;

/**
 * Aula 01 - Menu para executar os exercícios introdutórios de Java.
 *
 * @author Matheus Teixeira
 */
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        Ex1 ex1 = new Ex1(input);
        Ex2 ex2 = new Ex2(input);
        Ex3 ex3 = new Ex3();
        Ex4 ex4 = new Ex4(input);
        Ex5 ex5 = new Ex5(input);
        Ex6 ex6 = new Ex6(input);
        Ex7 ex7 = new Ex7(input);
        Ex8 ex8 = new Ex8(input);
        Ex9 ex9 = new Ex9();

        boolean executando = true;
        while (executando) {
            exibeMenu();
            System.out.print("\nDigite a opção: ");
            int opcao = input.nextInt();

            switch (opcao) {
                case 0 -> executando = false;
                case 1 -> ex1.calculaProduto();
                case 2 -> ex2.ordenaDecrescente();
                case 3 -> ex3.mostraImpares();
                case 4 -> ex4.contaPositivos();
                case 5 -> ex5.registraVendas();
                case 6 -> ex6.calculaCaminho();
                case 7 -> ex7.calculaReajuste();
                case 8 -> ex8.desenhaHistograma();
                case 9 -> ex9.mostraTriangulosPitagoricos();
                default -> System.out.println("Opção inválida.");
            }
        }
    }

    private static void exibeMenu() {
        System.out.print("""

                ==========================================================
                0. Sair
                1. Produto de três números
                2. Três números em ordem decrescente
                3. Números ímpares de 1 a 1000
                4. Contagem de números positivos
                5. Vendas de produtos
                6. Flíper
                7. Reajuste salarial
                8. Histograma de asteriscos
                9. Triângulos pitagóricos
                ==========================================================""");
    }
}
