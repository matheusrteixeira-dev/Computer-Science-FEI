package Ex02;

import java.util.ArrayList;

/**
 * Aula 04 - Exercício 2: verifica se duas listas contêm os mesmos elementos.
 *
 * @author Matheus Teixeira
 */
public class Main {
    public static void main(String[] args) {
        ArrayList<String> lista1 = new ArrayList<>();
        ArrayList<String> lista2 = new ArrayList<>();

        lista1.add("Blue");
        lista1.add("Red");
        lista1.add("Green");

        lista2.add("Green");
        lista2.add("Blue");
        lista2.add("Yellow");

        int soma = 0;
        for (String i : lista1) {
            for (String j: lista2) {
                if (i.equals(j))
                    soma++;
            }
        }

        if (lista1.size() == soma)
            System.out.println("As listas contêm os mesmos elementos");
        else
            System.out.println("As listas são diferentes");
    }
}
