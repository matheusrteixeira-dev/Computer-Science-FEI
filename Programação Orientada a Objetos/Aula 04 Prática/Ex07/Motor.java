package Ex07;

/**
 * Motor do carro (marca e potência).
 *
 * @author Matheus Teixeira
 */
public class Motor {
    private String marca;
    private double potencia;

    public Motor() {
    }

    public Motor(String marca, double potencia) {
        this.marca = marca;
        this.potencia = potencia;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public double getPotencia() {
        return potencia;
    }

    public void setPotencia(double potencia) {
        this.potencia = potencia;
    }
}
