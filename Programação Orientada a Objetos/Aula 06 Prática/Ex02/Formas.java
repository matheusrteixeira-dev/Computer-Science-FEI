package Ex02;

/**
 * Forma geométrica abstrata com perímetro e impressão dos dados.
 *
 * @author Matheus Teixeira
 */
abstract class Formas{
    public String tipo;

    public abstract double perimetro(double x, double y);
    public abstract void print();
}
