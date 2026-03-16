import java.util.ArrayList;

public class Kniha implements Knihovna{
    public String[] mojeKniha = new String[2];
    private Ctenar ctenarInfo;
    //private ArrayList<Ctenar> ctenarList = new ArrayList<>();
    public static ArrayList<String[]> dostupneKnihy = new ArrayList<>();
    public static ArrayList<String[]> vsechnyKnihy = new ArrayList<>();

    public Kniha(String Nazev, Autor autor) {

        this.mojeKniha[0] = Nazev;
        this.mojeKniha[1] = autor.info[1];

        dostupneKnihy.add(this.mojeKniha);
        vsechnyKnihy.add(this.mojeKniha);
    }
    public boolean dostupneKnihyObsahuje(String[] info){
        for(String[] item : dostupneKnihy){
            if(info[0].equals(item[0]) && info[1].equals(item[1])) return true;
        }
        return false;
    }
    public void vypisPujcenych(){
        System.out.println("Pujcene knihy:\n===================");
        for(String[] item : vsechnyKnihy){
            if(!dostupneKnihyObsahuje(item)){
                System.out.println("nazev knihy: " + item[0] + " | Autor knihy" + item[1] + " -> " + ctenarInfo.Jmeno + " " + ctenarInfo.Prijmeni);
            }
        }
    }
    public boolean pujcitKnihu(Ctenar ctenar){
        int index = 0;
        for(String[] item : dostupneKnihy){
            if(mojeKniha[0].equals(item[0]) && mojeKniha[1].equals(item[1])){

                dostupneKnihy.remove(index);
                ctenarInfo = ctenar;
                return true;
            }
            index++;
        }
        return false;
    }
    public void vratitKnihu(){
        dostupneKnihy.add(mojeKniha);
    }
    public boolean odepsatKnihu(ArrayList<Kniha> list){
        int index = 0;
        for(String[] item : dostupneKnihy){
            if(mojeKniha[0].equals(item[0]) && mojeKniha[1].equals(item[1])){

                dostupneKnihy.remove(index);
                vsechnyKnihy.remove(index);
                list.remove(this);
                return true;
            }
            index++;
        }
        return false;
    }
    public void vypisDostupnych(){
        System.out.println("Dostupne knihy:\n==================");
        for(String[] item : dostupneKnihy){
            System.out.println("Nazev knihy: " + item[0] + " | Autor knihy: " + item[1]);
        }
    }
}
