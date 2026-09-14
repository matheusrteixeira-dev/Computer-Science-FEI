package Ex01;

/**
 * Pessoa com validação de CPF: o construtor lança CpfException se o CPF não tiver 11 dígitos.
 *
 * @author Matheus Teixeira
 */
public class Pessoa {
    private String nome;
    private String sobrenome;
    private int idade;
    private String cpf;

    public Pessoa(String nome, String sobrenome, int idade, String cpf) {
        this.nome = nome;
        this.sobrenome = sobrenome;
        this.idade = idade;
        setCpf(cpf);
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getSobrenome() {
        return sobrenome;
    }

    public void setSobrenome(String sobrenome) {
        this.sobrenome = sobrenome;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        this.idade = idade;
    }

    public String getCpf() {
        return cpf;
    }

    /** Aceita CPF com ou sem pontuação; após removê-la, devem restar exatamente 11 dígitos. */
    public void setCpf(String cpf) {
        String somenteDigitos = cpf.replaceAll("[.\\-\\s]", "");
        if (!somenteDigitos.matches("\\d{11}")) {
            throw new CpfException("CPF deve conter 11 dígitos numéricos");
        }
        this.cpf = somenteDigitos;
    }

    @Override
    public String toString() {
        return nome + " " + sobrenome + ", " + idade + " anos, CPF " + cpf;
    }
}
