package Ex07;

/**
 * Vidro do carro (material e presença de película).
 *
 * @author Matheus Teixeira
 */
public class Vidro {
    private String material;
    private boolean sufilm;

    public Vidro() {
    }

    public Vidro(String material, boolean sufilm) {
        this.material = material;
        this.sufilm = sufilm;
    }

    public String getMaterial() {
        return material;
    }

    public void setMaterial(String material) {
        this.material = material;
    }

    public boolean isSufilm() {
        return sufilm;
    }

    public void setSufilm(boolean sufilm) {
        this.sufilm = sufilm;
    }
}
