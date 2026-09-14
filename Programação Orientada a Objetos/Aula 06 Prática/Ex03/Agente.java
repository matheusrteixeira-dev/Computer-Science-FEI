package Ex03;

/**
 * Agente abstrato: toda pessoa cadastrada pode ativar o modo agente.
 *
 * @author Matheus Teixeira
 */
abstract class Agente{
    private String nome;
    private boolean modoOnAgente;
    private String profissao;

    abstract void apresentacao();
    abstract void modeAgenteOn();

    void setNome(String nome) {
        this.nome = nome;
    }

    void setModeOnAgente(boolean modeAgenteOn) {
        this.modoOnAgente = modeAgenteOn;
    }

    void setProfissao(String profissao) {
        this.profissao = profissao;
    }

    String getNome() {
        return nome;
    }

    String getProfissao() {
        return profissao;
    }

    boolean getModeOnAgente() {
        return modoOnAgente;
    }
}
