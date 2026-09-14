package Ex03;

/**
 * Fornece uma única instância compartilhada da fábrica de saídas.
 *
 * @author Matheus Teixeira
 */
public class Singleton {
    private static Factory objetoUnico;

    private Singleton() {
    }

    public static Factory getInstance() {
        if (objetoUnico == null)
            objetoUnico = new Factory();
        return objetoUnico;
    }
}
