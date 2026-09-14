package Model;

/**
 * Endereço com rua, número, bairro e cidade.
 *
 * @author Matheus Teixeira
 */
public class Endereço {
    private String rua;
    private String cidade;
    private String bairro;
    private int numero;

    public Endereço(String rua, String cidade, String bairro, int numero) {
        this.rua = rua;
        this.cidade = cidade;
        this.bairro = bairro;
        this.numero = numero;
    }

    public Endereço() {
    }

    public String getRua() {
        return rua;
    }

    public void setRua(String rua) {
        this.rua = rua;
    }

    public String getCidade() {
        return cidade;
    }

    public void setCidade(String cidade) {
        this.cidade = cidade;
    }

    public String getBairro() {
        return bairro;
    }

    public void setBairro(String bairro) {
        this.bairro = bairro;
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    @Override
    public String toString() {
        return rua + ", " + numero + " - " + bairro + ", " + cidade;
    }
}
