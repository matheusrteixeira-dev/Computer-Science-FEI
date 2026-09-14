package Model;

/**
 * Operação de soma.
 *
 * @author Matheus Teixeira
 */
public class Soma implements Calculo{
    @Override
    public double calcula(double num1, double num2) {
        return num1 + num2;
    }
}
