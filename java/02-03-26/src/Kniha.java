public class Kniha{
    private static int celkovyPocet = 0;

    private String nazev;
    private int pocetStran;

    public Kniha(){
        this.nazev = "RUR";
        this.pocetStran = 150;

        this.celkovyPocet += 150;
    }
    public Kniha(String nazev, int pocetStran){
        this.nazev = nazev;
        this.pocetStran = pocetStran;

        this.celkovyPocet += pocetStran;
    }
    public void vypis(){
        System.out.println("nazev knihy je: " + nazev);
        System.out.println("pocet stran knihy je: " + pocetStran + "\n");
    }
    public int getPocetStran(){
        return pocetStran;
    }
    public static void printCelkovyPocet(){
        System.out.println(celkovyPocet);
    }
    public static int getCelkovyPocetStran(){
        return celkovyPocet;
    }
}
