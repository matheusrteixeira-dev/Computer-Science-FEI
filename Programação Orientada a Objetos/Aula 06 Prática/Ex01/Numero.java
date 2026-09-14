package Ex01;

/**
 * Calcula o quadrado de um número, com versões sobrecarregadas para int e double.
 *
 * @author Matheus Teixeira
 */
public class Numero {
    public Numero() {
    }

    double square(double valor) {
        return (Math.pow(valor, 2));
    }

    int square(int valor) {
        return (valor * valor);
    }
}
