package Ex07;

/**
 * Airbag do carro (marca e tecido).
 *
 * @author Matheus Teixeira
 */
public class AirBags {
    private String marca;
    private String tecido;

    public AirBags() {
    }

    public AirBags(String marca, String tecido) {
        this.marca = marca;
        this.tecido = tecido;
    }

    public String getMarca() {
        return marca;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }

    public String getTecido() {
        return tecido;
    }

    public void setTecido(String tecido) {
        this.tecido = tecido;
    }
}
