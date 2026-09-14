package Ex05;

/**
 * Animal identificado pelo nome.
 *
 * @author Matheus Teixeira
 */
public class Animal{
    private String nome;

    public Animal(String nome) {
        this.nome = nome;
    }

    void setNome(String nome) {
        this.nome = nome;
    }

    String getNome() {
        return nome;
    }
}
