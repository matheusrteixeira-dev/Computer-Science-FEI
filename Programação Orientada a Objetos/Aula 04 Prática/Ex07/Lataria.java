package Ex07;

/**
 * Lataria do carro (cor e material).
 *
 * @author Matheus Teixeira
 */
public class Lataria {
    private String cor;
    private String material;

    public Lataria() {
    }

    public Lataria(String cor, String material) {
        this.cor = cor;
        this.material = material;
    }

    public String getCor() {
        return cor;
    }

    public void setCor(String cor) {
        this.cor = cor;
    }

    public String getMaterial() {
        return material;
    }

    public void setMaterial(String material) {
        this.material = material;
    }
}
