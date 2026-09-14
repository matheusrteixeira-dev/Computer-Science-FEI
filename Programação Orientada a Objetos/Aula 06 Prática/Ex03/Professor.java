package Ex03;

/**
 * Professor associado a uma escola.
 *
 * @author Matheus Teixeira
 */
class Professor extends Agente{
    private String escola;

    public Professor(String escola, String nome) {
        this.escola = escola;
        setNome(nome);
    }

    public Professor() {
    }

    void setEscola(String escola) {
        this.escola = escola;
    }

    String getEscola() {
        return escola;
    }

    public void apresentacao() {
        System.out.println("Nome: " + getNome());
        System.out.println("Profissao: " + "Professor");
        System.out.println("Escola: " + getEscola());

        if (getModeOnAgente())
            System.out.println("Modo agente: ativado");
    }

    public void modeAgenteOn() {
        setModeOnAgente(true);
    }
}
