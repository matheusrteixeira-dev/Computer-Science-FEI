package Model;

/**
 * Animal atendido pela veterinária.
 *
 * @author Matheus Teixeira
 */
public class Animal extends Mamifero{
    private int ID;
    private int idade;
    private String nome;
    private String tipo;
    private String raça;

    public Animal(int ID, int idade, String nome, String tipo, String raça) {
        this.ID = ID;
        this.idade = idade;
        this.nome = nome;
        this.tipo = tipo;
        this.raça = raça;
    }

    public int getID() {
        return ID;
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getTipo() {
        return tipo;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public String getRaça() {
        return raça;
    }

    public void setRaça(String raça) {
        this.raça = raça;
    }

    @Override
    public String toString() {
        return "ID: " + ID + "\nNome: " + nome + "\nIdade: " + idade + "\nRaça: " + raça + "\n";
    }
}
