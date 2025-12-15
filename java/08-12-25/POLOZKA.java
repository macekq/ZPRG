public class POLOZKA {
    private static int dalsiId = 0;
    private int id;
    private String nazev;
    private double cenaPolozky;

    public POLOZKA(String nazev, double cenaPolozky) {
        this.id = dalsiId;
        this.nazev = nazev;
        this.cenaPolozky = cenaPolozky;
        dalsiId++;
    }
    public void vypis(){
        System.out.println(
        "nazev: " + this.nazev +
        "\nid: " + this.id +
        "\ncenaPolozky: " + this.cenaPolozky
        );
    }
    public int getId() {
        return id;
    }
    public String getNazev() {
        return nazev;
    }
    public double getCenaPolozky() {
        return cenaPolozky;
    }
    public void setId(int id) {
        this.id = id;
    }
    public void setNazev(String nazev) {
        this.nazev = nazev;
    }
    public void setCenaPolozy(double cenaPolozky) {
        this.cenaPolozky = cenaPolozky;
    }
}
