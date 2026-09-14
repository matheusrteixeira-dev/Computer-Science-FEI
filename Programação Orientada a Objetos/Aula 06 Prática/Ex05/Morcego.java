package Ex05;

/**
 * Morcego: animal que anda e voa.
 *
 * @author Matheus Teixeira
 */
public class Morcego extends Animal implements IWalkable, IFlyable{
    public Morcego(String nome) {
        super(nome);
    }
}
