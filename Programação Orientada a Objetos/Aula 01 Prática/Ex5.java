package POO;

import java.util.Scanner;

/** Exercício 5: registra vendas (código do produto e quantidade) e calcula o total vendido. */
public class Ex5 {
    /** Preço de cada produto; o índice corresponde ao código (1 a 5). */
    private static final float[] PRECOS = {0f, 2.98f, 4.50f, 3.98f, 4.49f, 6.87f};

    private final Scanner input;

    public Ex5(Scanner input) {
        this.input = input;
    }

    public void registraVendas() {
        int produtosVendidos = 0;
        float valorTotal = 0;

        System.out.println("Digite o codigo 0 para sair.");

        while (true) {
            System.out.print("Digite o codigo do produto: ");
            int codigo = input.nextInt();
            if (codigo == 0) {
                break;
            }
            if (codigo < 1 || codigo >= PRECOS.length) {
                System.out.println("Codigo invalido.");
                continue;
            }

            System.out.print("Digite a quantidade vendida: ");
            int quantidade = input.nextInt();

            produtosVendidos += quantidade;
            valorTotal += PRECOS[codigo] * quantidade;
        }

        System.out.printf("%nNumero de produtos vendidos: %d%nValor total = R$ %.2f%n%n",
                produtosVendidos, valorTotal);
    }
}
