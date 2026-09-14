package Ex05;

/**
 * Animal capaz de voar.
 *
 * @author Matheus Teixeira
 */
interface IFlyable{
    default void voar() {
        System.out.println("Voando...");
    }
}
