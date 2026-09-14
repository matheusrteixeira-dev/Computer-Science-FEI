package Ex03;

/**
 * Fábrica que devolve a saída correspondente ao código informado (0 = arquivo, outro = tela).
 *
 * @author Matheus Teixeira
 */
public class Factory {
    public Output getOutput(int num) {
        if (num == 0)
            return new File();
        else
            return new Tela();
    }

    public Factory() {
    }
}
