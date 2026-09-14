package Ex04;

/**
 * Círculo móvel (diagrama UML em ../../images/lab06_04.png): é composto por um MovablePoint
 * que representa seu centro e delega a ele os movimentos.
 */
class MovableCircle implements IMoveable {
    private final int radius;
    private final MovablePoint center;

    public MovableCircle(int x, int y, int xSpeed, int ySpeed, int radius) {
        this.center = new MovablePoint(x, y, xSpeed, ySpeed);
        this.radius = radius;
    }

    @Override
    public void moveUp() {
        center.moveUp();
    }

    @Override
    public void moveDown() {
        center.moveDown();
    }

    @Override
    public void moveLeft() {
        center.moveLeft();
    }

    @Override
    public void moveRight() {
        center.moveRight();
    }

    @Override
    public String toString() {
        return "Círculo de raio " + radius + " com centro em " + center;
    }
}
