package Ex05;

/**
 * Animal capaz de andar.
 *
 * @author Matheus Teixeira
 */
interface IWalkable{
    default void andar() {
        System.out.println("Andando...");
    }
}
