package Ex05;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Aula 04 - Exercício 5: monta as peças de um tabuleiro de xadrez em uma lista e remove a peça
 * de uma posição informada.
 *
 * @author Matheus Teixeira
 */
public class Main {
    private static final String COLUNAS = "abcdefgh";
    private static final String[] PECAS_PRIMEIRA_FILEIRA =
    {"Torre", "Cavalo", "Bispo", "Rainha", "Rei", "Bispo", "Cavalo", "Torre"};

    /** Adiciona as 16 peças de uma cor: peões em linhaPeoes e demais peças em linhaPecas. */
    private static void adicionaPecas(List<Peça> xadrez, String cor, int linhaPeoes, int linhaPecas) {
        for (int i = 0; i < COLUNAS.length(); i++) {
            xadrez.add(new Peça("Peão", cor, "" + COLUNAS.charAt(i) + linhaPeoes));
        }
        for (int i = 0; i < COLUNAS.length(); i++) {
            xadrez.add(new Peça(PECAS_PRIMEIRA_FILEIRA[i], cor, "" + COLUNAS.charAt(i) + linhaPecas));
        }
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        List<Peça> xadrez = new ArrayList<>();
        adicionaPecas(xadrez, "Branco", 2, 1);
        adicionaPecas(xadrez, "Preto", 7, 8);

        System.out.print("\nDigite a posição: ");
        String posicao = input.nextLine().trim();

        boolean removida = xadrez.removeIf(peca -> peca.getPosicao().equals(posicao));
        System.out.println(removida ? "\nPeça removida com sucesso." : "\nNenhuma peça nessa posição.");

        System.out.println("\nImprimindo todas...");
        for (Peça peca : xadrez) {
            System.out.println(peca);
        }
    }
}
