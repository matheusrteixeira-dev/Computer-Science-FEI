package Exercicio03UML;

/**
 * Aula 04 - Exercício 3 (UML): associação entre Aluno, Disciplina e Professor.
 *
 * <p>Agregação: todos os objetos são criados de forma independente no main e apenas
 * relacionados entre si, caracterizando um vínculo mais fraco que a composição.
 *
 * @author Matheus Teixeira
 */
public class Main {
    public static void main(String[] args) {
        Aluno aluno = new Aluno();
        Disciplina disciplina = new Disciplina();
        Professor professor = new Professor();

        // Dados fictícios, usados apenas para demonstração.
        professor.setNome("Professor Exemplo");
        professor.setDepartamento("Computação");

        disciplina.setCodigo("CC0001");
        disciplina.setNome("POO");

        aluno.setNome("Aluno Exemplo");
        aluno.setRA("00.000.000-0");
        aluno.setCurso(disciplina.getNome());

        System.out.printf("Professor: %s (%s)%n", professor.getNome(), professor.getDepartamento());
        System.out.printf("Disciplina: %s - %s%n", disciplina.getCodigo(), disciplina.getNome());
        System.out.printf("Aluno: %s (RA %s), curso: %s%n", aluno.getNome(), aluno.getRA(), aluno.getCurso());
    }
}
