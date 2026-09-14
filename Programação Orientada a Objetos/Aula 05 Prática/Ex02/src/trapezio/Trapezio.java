package trapezio;

import quadilatero.Quadrilatero;
import ponto.Ponto;

/**
 * Trapézio: área calculada a partir das bases e da altura obtidas dos vértices.
 *
 * @author Matheus Teixeira
 */
public class Trapezio extends Quadrilatero{
    public Trapezio() {
    }

    public Trapezio(Ponto p1, Ponto p2, Ponto p3, Ponto p4) {
        super(p1, p2, p3, p4);
    }

    public double area(Ponto p1, Ponto p2, Ponto p3, Ponto p4) {
        double b = distancia(p1, p2);
        double B = distancia(p4, p3);
        double h = distancia(p1, p4);
        return (h*(B + b))/2.0;
    }

    public double distancia(Ponto p1, Ponto p2) {
        double dist = Math.sqrt(Math.pow(p1.getX() - p2.getX(), 2) + Math.pow(p1.getY() - p2.getY(), 2));
        return dist;
    }
}
