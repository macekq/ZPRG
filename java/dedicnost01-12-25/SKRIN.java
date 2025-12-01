public class SKRIN extends NABYTEK{
    private int vyska, sirka, hloubka;
    private int cena;//KC
    public SKRIN(){
        this.vyska = 150;
        this.sirka = 100;
        this.hloubka = 40;
        this.cena = 1000;
    }
    public SKRIN(int vyska, int sirka, int hloubka, int cena) {
        this.vyska = vyska;
        this.sirka = sirka;
        this.hloubka = hloubka;
        this.cena = cena;
    }
    public void vypis(){
        System.out.println("Vyska: " + this.vyska);
        System.out.println("Sirka: " + this.sirka);
        System.out.println("Hloubka: " + this.hloubka);
        System.out.println("Cena: " + this.cena);
        System.out.println("hmotnost: " + getHmotnost());
    }
    public float getObjem(){return this.hloubka * this.vyska * this.sirka;}
}
