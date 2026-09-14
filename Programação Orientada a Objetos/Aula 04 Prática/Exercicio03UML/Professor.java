package Exercicio03UML;

/**
 * Professor com nome e departamento.
 *
 * @author Matheus Teixeira
 */
public class Professor {
    private String nome;
    private String departamento;

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getDepartamento() {
        return departamento;
    }

    public void setDepartamento(String departamento) {
        this.departamento = departamento;
    }

    public Professor() {
    }
}
