package Ex07;

/**
 * Extintor do carro (marca e capacidade).
 *
 * @author Matheus Teixeira
 */
public class Extintor {
    private String marca;
    private double quantidade;

    public Extintor() {
    }

    public Extintor(String marca, double quantidade) {
        this.marca = marca;
        this.quantidade = quantidade;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public double getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(double quantidade) {
        this.quantidade = quantidade;
    }
}
