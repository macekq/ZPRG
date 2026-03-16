import java.util.ArrayList;

public class Ctenar{

    public String Jmeno, Prijmeni;
    private ArrayList<Kniha> pujceneKnihy = new ArrayList();

    public Ctenar(String Jmeno, String Prijmeni){
        this.Jmeno = Jmeno;
        this.Prijmeni = Prijmeni;
    }
    public void pujcitKnihu(Kniha kniha){
        this.pujceneKnihy.add(kniha);
        kniha.pujcitKnihu(this);
    }
    public void vratitKnihu(Kniha kniha){
        this.pujceneKnihy.remove(kniha);
        kniha.vratitKnihu();
    }
}
