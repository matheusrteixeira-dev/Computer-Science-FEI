package main;

import prefeito.Prefeito;
import vereador.Vereador;

/**
 * Aula 05 - Exercício 3: herança entre político, prefeito e vereador (enunciado em ../../../../images/lab05_03.png).
 *
 * @author Matheus Teixeira
 */
public class Main {
    public static void main(String[] args) {
        Vereador vere = new Vereador("Carlos Lima", "Partido A", "Santo André", "São Paulo");
        vere.apresentacao();

        Prefeito pref = new Prefeito("Ana Souza", "Partido A", "Santo André", "São Paulo");
        pref.apresentacao();
    }
}
