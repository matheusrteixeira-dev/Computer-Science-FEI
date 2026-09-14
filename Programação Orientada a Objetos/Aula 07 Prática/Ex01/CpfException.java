package Ex01;

/**
 * Exceção lançada quando o CPF informado é inválido.
 *
 * @author Matheus Teixeira
 */
public class CpfException extends RuntimeException{
    public CpfException(String string) {
        super(string);
    }
}
