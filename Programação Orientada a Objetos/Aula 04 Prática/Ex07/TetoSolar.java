package Ex07;

/**
 * Teto solar do carro (marca e tamanho).
 *
 * @author Matheus Teixeira
 */
public class TetoSolar {
    private String marca;
    private double tamanho;

    public TetoSolar() {
    }

    public TetoSolar(String marca, double tamanho) {
        this.marca = marca;
        this.tamanho = tamanho;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public double getTamanho() {
        return tamanho;
    }

    public void setTamanho(double tamanho) {
        this.tamanho = tamanho;
    }
}
