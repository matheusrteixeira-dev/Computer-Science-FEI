package Model;

/**
 * Operação de subtração.
 *
 * @author Matheus Teixeira
 */
public class Subtracao implements Calculo{
    @Override
    public double calcula(double num1, double num2) {
        return num1-num2;
    }
}
