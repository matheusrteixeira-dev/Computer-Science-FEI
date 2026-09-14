package javaapplication2;

/**
 * Conta comum com número e situação.
 *
 * @author Matheus Teixeira
 */
public class ContaComum {
    int numero = 1234567;
    int situacao = 1;

    public ContaComum() {
        System.out.println();
    }

    public int getNumero() {
        return numero;
    }

    public int getSituacao() {
        return situacao;
    }

    public void setNumero(int numero) {
        this.numero = numero;
    }

    public void setSituacao(int situacao) {
        this.situacao = situacao;
    }
}
