package Ex04;

/** Aula 06 - Exercício 4: interface IMoveable implementada por ponto e círculo móveis. */
public class Main {
    public static void main(String[] args) {
        MovableCircle c = new MovableCircle(10, 10, 5, 5, 1);
        System.out.println(c);

        c.moveDown();
        System.out.println(c);
        c.moveLeft();
        System.out.println(c);
        c.moveUp();
        System.out.println(c);
        c.moveRight();
        System.out.println(c);
    }
}
