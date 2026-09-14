package Model;

/**
 * Operação de divisão.
 *
 * @author Matheus Teixeira
 */
public class Divisao implements Calculo{
    @Override
    public double calcula(double num1, double num2) {
        return num1/num2;
    }
}
