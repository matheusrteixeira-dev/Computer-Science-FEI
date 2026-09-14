package Ex03;

/**
 * Empresário associado a uma empresa.
 *
 * @author Matheus Teixeira
 */
class Empresario extends Agente{
    private String empresa;

    public Empresario(String empresa, String nome) {
        this.empresa = empresa;
        setNome(nome);
    }

    public Empresario() {
    }

    void setEmpresa(String empresa) {
        this.empresa = empresa;
    }

    String getEmpresa() {
        return empresa;
    }

    public void apresentacao() {
        System.out.println("Nome: " + getNome());
        System.out.println("Profissao: " + "Empresário");
        System.out.println("Empresa: " + getEmpresa());

        if (getModeOnAgente())
            System.out.println("Modo agente: ativado");
    }

    public void modeAgenteOn() {
        setModeOnAgente(true);
    }
}
