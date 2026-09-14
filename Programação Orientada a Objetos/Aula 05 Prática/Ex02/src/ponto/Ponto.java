package ponto;

/** Ponto no plano cartesiano com coordenadas inteiras.
 * @author Matheus Teixeira
 */
public class Ponto {
    protected int x;
    protected int y;

    /** Método construtor do objeto do tipo ponto**/
    public Ponto(int x, int y) {
        this.x = x;
        this.y = y;
    }

    /** Método construtor vazio do objeto do tipo ponto**/
    public Ponto() {
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public void setX(int x) {
        this.x = x;
    }

    public void setY(int y) {
        this.y = y;
    }
}
