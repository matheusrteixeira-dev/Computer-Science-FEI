import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.List;

/**
 * Programação de linha de montagem (assembly-line scheduling) por programação dinâmica.
 *
 * <p>Duas linhas paralelas com {@code n} estações cada; o chassi pode trocar de linha entre
 * estações pagando um tempo de transferência. Calcula o menor tempo total e o caminho ótimo.
 *
 * <p>Baseado em código-base fornecido pelo professor da disciplina.
 */
public class LinhaProducao {

  /**
   * Imprime, da primeira à última estação, a linha usada em cada estação do caminho ótimo.
   *
   * @param esc1 {@code esc1[i]}: linha de onde se chega à estação {@code i} da linha 1
   * @param esc2 {@code esc2[i]}: linha de onde se chega à estação {@code i} da linha 2
   * @param escFim linha usada na última estação
   */
  public static void imprimeMenorCaminho(List<Integer> esc1, List<Integer> esc2, int escFim) {
    Deque<Integer> pilha = new ArrayDeque<>();
    pilha.push(escFim);
    for (int i = esc1.size() - 1; i > 0; i--) {
      int linhaAtual = pilha.peek();
      pilha.push(linhaAtual == 1 ? esc1.get(i) : esc2.get(i));
    }

    int estacao = 1;
    while (!pilha.isEmpty()) {
      System.out.println("Estacao " + estacao++ + ": linha " + pilha.pop());
    }
  }

  /**
   * Calcula o menor tempo para atravessar a linha de montagem.
   *
   * @param a1 tempos de processamento das estações da linha 1
   * @param a2 tempos de processamento das estações da linha 2
   * @param t1 tempos de transferência da linha 1 para a linha 2 após cada estação
   * @param t2 tempos de transferência da linha 2 para a linha 1 após cada estação
   * @param e1 tempo de entrada na linha 1
   * @param e2 tempo de entrada na linha 2
   * @param s1 tempo de saída da linha 1
   * @param s2 tempo de saída da linha 2
   * @return menor tempo total
   */
  public static int menorTempo(List<Integer> a1, List<Integer> a2, List<Integer> t1,
      List<Integer> t2, int e1, int e2, int s1, int s2) {

    int n = a1.size();
    List<Integer> acc1 = new ArrayList<>(n);
    List<Integer> acc2 = new ArrayList<>(n);
    List<Integer> esc1 = new ArrayList<>(n);
    List<Integer> esc2 = new ArrayList<>(n);

    acc1.add(e1 + a1.get(0));
    esc1.add(1);
    acc2.add(e2 + a2.get(0));
    esc2.add(2);

    for (int i = 1; i < n; i++) {
      // Linha 1: continua na linha 1 ou vem da linha 2.
      acc1.add(acc1.get(i - 1) + a1.get(i));
      esc1.add(1);
      int tmp = acc2.get(i - 1) + t2.get(i - 1) + a1.get(i);
      if (tmp < acc1.get(i)) {
        acc1.set(i, tmp);
        esc1.set(i, 2);
      }

      // Linha 2: continua na linha 2 ou vem da linha 1.
      acc2.add(acc2.get(i - 1) + a2.get(i));
      esc2.add(2);
      tmp = acc1.get(i - 1) + t1.get(i - 1) + a2.get(i);
      if (tmp < acc2.get(i)) {
        acc2.set(i, tmp);
        esc2.set(i, 1);
      }
    }

    int total1 = acc1.get(n - 1) + s1;
    int total2 = acc2.get(n - 1) + s2;

    imprimeMenorCaminho(esc1, esc2, total1 < total2 ? 1 : 2);

    return Math.min(total1, total2);
  }

  public static void main(String[] args) {
    List<Integer> a1 = Arrays.asList(7, 9, 3, 4, 8, 4);
    List<Integer> a2 = Arrays.asList(8, 5, 6, 4, 5, 7);
    List<Integer> t1 = Arrays.asList(2, 3, 1, 3, 4);
    List<Integer> t2 = Arrays.asList(2, 1, 2, 2, 1);

    int e1 = 2, e2 = 4;
    int s1 = 3, s2 = 2;

    System.out.println("Menor tempo: " + menorTempo(a1, a2, t1, t2, e1, e2, s1, s2));
  }
}
