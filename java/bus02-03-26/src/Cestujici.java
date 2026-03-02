public class Cestujici{

    public String jmeno;
    public String prijmeni;
    private int penezenka;
    private int index;
    private int pocetZastavek;

    //muj bonus
    public Cestujici(){
        this.jmeno = "david";
        this.prijmeni = "schizofrenik";
        this.penezenka = 200;
        this.pocetZastavek = 1;
    }
    public Cestujici(String jmeno, String prijmeni, int penezenka, int pocetZastavek){
        this.jmeno = jmeno;
        this.prijmeni = prijmeni;
        this.penezenka = penezenka;
        this.pocetZastavek = pocetZastavek;
    }
    public void vypis(){
        System.out.println("jmeno > " + this.jmeno);
        System.out.println("prijmeni > " + this.prijmeni);
        System.out.println("pocetZastavek > " + this.pocetZastavek);
        System.out.println("penezenka > " + this.penezenka + "\n");
    }

    public void setIndex(int index){ this.index = index; }
    public int getIndex(){ return this.index; }
    public int getPenezenka(){
        return penezenka;
    }
    public void setPenezenka(int penezenka){
        this.penezenka = penezenka;
    }

    public int getPocetZastavek(){ return pocetZastavek; }
}
