public class Ucebnice extends Kniha{
    private static String predmet;

    public Ucebnice(){
        super("petakova", 200);
        this.predmet = "matematika";
    }
    public Ucebnice(String nazev, int pocetStran, String predmet){
        super(nazev, pocetStran);
        this.predmet = predmet;
    }
    @Override
    public void vypis(){
        System.out.println("predmet je: " + predmet);
        super.vypis();
    }
}
