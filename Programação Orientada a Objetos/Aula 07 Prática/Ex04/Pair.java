package Ex04;

/**
 * Par genérico de valores de tipos F e S.
 *
 * @author Matheus Teixeira
 */
public class Pair <F, S> {
    private F value1;
    private S value2;

    public Pair() {
    }

    public Pair(F value1, S value2) {
        this.value1 = value1;
        this.value2 = value2;
    }

    public F getValue1() {
        return value1;
    }

    public void setValue1(F value1) {
        this.value1 = value1;
    }

    public S getValue2() {
        return value2;
    }

    public void setValue2(S value2) {
        this.value2 = value2;
    }
}
