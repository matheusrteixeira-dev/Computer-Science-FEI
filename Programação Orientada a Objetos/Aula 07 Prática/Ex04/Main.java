package Ex04;

/**
 * Aula 07 - Exercício 4: classe genérica Pair com dois tipos parametrizados.
 *
 * @author Matheus Teixeira
 */
public class Main {
    public static void main(String[] args) {
        Pair<Double, Integer> pair = new Pair<>();
        pair.setValue1(2.5);
        pair.setValue2(1);
        System.out.println("Par (setters): (" + pair.getValue1() + ", " + pair.getValue2() + ")");

        Pair<String, Boolean> outro = new Pair<>("texto", true);
        System.out.println("Par (construtor): (" + outro.getValue1() + ", " + outro.getValue2() + ")");
    }
}
