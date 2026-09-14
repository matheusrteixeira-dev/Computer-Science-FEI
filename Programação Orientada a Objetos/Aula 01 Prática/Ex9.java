package POO;

/** Exercício 9: triângulos pitagóricos (a² + b² = c²) com lados até 500. */
public class Ex9 {
    private static final int LIMITE = 500;

    public void mostraTriangulosPitagoricos() {
        System.out.println("Triangulos pitagoricos (hipotenusa, cateto, cateto)\n");
        for (int a = 1; a <= LIMITE; a++) {
            for (int b = a + 1; b <= LIMITE; b++) {
                for (int c = b + 1; c <= LIMITE; c++) {
                    if (c * c == a * a + b * b) {
                        System.out.printf("(%d, %d, %d)%n", c, a, b);
                    }
                }
            }
        }
        System.out.println();
    }
}
