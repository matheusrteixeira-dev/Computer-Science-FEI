package POO;

/** Exercício 3: exibe os números ímpares de 1 a 1000. */
public class Ex3 {
    public void mostraImpares() {
        System.out.println("Numeros impares:\n");
        for (int i = 1; i <= 1000; i += 2) {
            System.out.printf("%5d%n", i);
        }
        System.out.println();
    }
}
