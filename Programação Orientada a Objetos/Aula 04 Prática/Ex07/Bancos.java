package Ex07;

/**
 * Bancos do carro (tecido e cor).
 *
 * @author Matheus Teixeira
 */
public class Bancos {
    private String tecido;
    private String cor;

    public Bancos(String tecido, String cor) {
        this.tecido = tecido;
        this.cor = cor;
    }

    public Bancos() {
    }

    public String getTecido() {
        return tecido;
    }

    public void setTecido(String tecido) {
        this.tecido = tecido;
    }

    public String getCor() {
        return cor;
    }

    public void setCor(String cor) {
        this.cor = cor;
    }
}
