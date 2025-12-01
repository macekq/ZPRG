import java.awt.*;

public class NABYTEK{
    private int hmotnost;//KG
    private String material;
    private Color barva;

    public NABYTEK(){
        barva = Color.BLACK;
        hmotnost = 25;
        material = "drevotriska";
    }
    public NABYTEK(int hmotnost, String material, Color barva){
        this.hmotnost = hmotnost;
        this.material = material;
        this.barva = barva;
    }
    public void vypis(){
        System.out.println("hmotnost: " + this.hmotnost);
        System.out.println("material: " + this.material);
        System.out.println("barva: " + this.barva);
    }
    public int getHmotnost(){
        return this.hmotnost;
    }
}
