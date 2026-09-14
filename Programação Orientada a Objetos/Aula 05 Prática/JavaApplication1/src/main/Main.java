package main;

import java.util.Scanner;
import pessoa.Pessoa;
import aluno.Aluno;

/**
 * Aula 05 - Exercício 1: herança entre Pessoa e Aluno (enunciado em ../../../../images/lab05_01.png).
 *
 * @author Matheus Teixeira
 */
public class Main {
    public static Scanner input;
    public static void main(String[] args) {
        input = new Scanner(System.in);

        System.out.printf("\nDigite a idade: ");
        int idade = Integer.parseInt(input.nextLine());
        System.out.printf("\nDigite o nome: ");
        String nome = input.nextLine();
        System.out.printf("\nDigite o sobrenome: ");
        String sobrenome = input.nextLine();
        System.out.printf("\nDigite o curso: ");
        String curso = input.nextLine();

        Aluno p1 = new Aluno();
        p1.print();
        Aluno p2 = new Aluno(nome, sobrenome, idade, curso);
        p2.print();
    }
}
