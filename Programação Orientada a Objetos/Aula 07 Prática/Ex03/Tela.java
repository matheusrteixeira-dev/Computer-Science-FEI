package Ex03;

/**
 * Saída de texto no console.
 *
 * @author Matheus Teixeira
 */
public class Tela implements Output{
    public Tela() {
    }

    @Override
    public void print(String text) {
        System.out.println(text);
    }
}
