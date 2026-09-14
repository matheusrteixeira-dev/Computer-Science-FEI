package Exercicio04;

/**
 * Aula 03 - Exercício 4: operações aritméticas com números racionais.
 *
 * @author Matheus Teixeira
 */
public class Main {
    public static void retorno(String operacao, Racional r) {
        System.out.println("=================================");
        System.out.printf("%s: %s = %.4f%n", operacao, r.retornoString(), r.retornoDouble());
    }

    public static void main(String[] args) {
        Racional r1 = new Racional(1, 2);
        Racional r2 = new Racional(3, 4);
        Racional calculadora = new Racional();

        retorno("Soma", calculadora.somar(r1, r2));
        retorno("Subtracao", calculadora.subtrair(r1, r2));
        retorno("Multiplicacao", calculadora.multiplicar(r1, r2));
        retorno("Divisao", calculadora.dividir(r1, r2));
    }
}
