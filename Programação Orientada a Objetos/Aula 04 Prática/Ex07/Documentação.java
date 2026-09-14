package Ex07;

/**
 * Documentação do carro (estado de registro e ano).
 *
 * @author Matheus Teixeira
 */
public class Documentação {
    private String estado;
    private int ano;

    public Documentação() {
    }

    public Documentação(String estado, int ano) {
        this.estado = estado;
        this.ano = ano;
    }

    public String getEstado() {
        return estado;
    }

    public void setEstado(String estado) {
        this.estado = estado;
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }
}
