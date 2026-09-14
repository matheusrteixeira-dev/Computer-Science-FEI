package Model;

/**
 * Operação de multiplicação.
 *
 * @author Matheus Teixeira
 */
public class Multiplicacao implements Calculo{
    @Override
    public double calcula(double num1, double num2) {
        return num1*num2;
    }
}
