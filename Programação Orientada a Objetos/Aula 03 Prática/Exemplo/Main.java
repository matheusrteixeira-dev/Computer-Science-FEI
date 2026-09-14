package javaapplication2;

/**
 * Aula 03 - Exemplo de agregação: uma pessoa associada a uma conta comum.
 *
 * @author Matheus Teixeira
 */
public class Main {
    public static void main(String[] args) {
        Pessoa p1 =new Pessoa();
        ContaComum c = new ContaComum();
        p1.setConta(c);
    }
}
