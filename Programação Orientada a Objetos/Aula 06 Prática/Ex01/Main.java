package Ex01;

/**
 * Aula 06 - Exercício 1: sobrecarga de métodos.
 *
 * @author Matheus Teixeira
 */
public class Main {
    public static void main(String[] args) {
        Numero n = new Numero();

        System.out.println("Resultado com parametro double:" + n.square(0.5));
        System.out.println("Resultado com parametro int:" + n.square(5));
    }
}
