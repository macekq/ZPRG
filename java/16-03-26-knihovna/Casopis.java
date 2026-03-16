import java.util.ArrayList;

public class Casopis implements Knihovna{
    public String[] mujCasopis = new String[2];
    private Autor autorInfo;
    private Ctenar ctenarInfo;
    public static ArrayList<String[]> dostupneCasopisy = new ArrayList<>();
    public static ArrayList<String[]> vsechnyKnihy = new ArrayList<>();

    public Casopis(String Nazev, Autor autor) {

        this.mujCasopis[0] = Nazev;
        this.mujCasopis[1] = autor.info[1];

        dostupneCasopisy.add(this.mujCasopis);
        vsechnyKnihy.add(this.mujCasopis);
        autorInfo = autor;
    }
    public boolean dostupneCasopisyObsahuje(String[] info){
        for(String[] item : dostupneCasopisy){
            if(info[0].equals(item[0]) && info[1].equals(item[1])) return true;
        }
        return false;
    }
    public void vypisPujcenych(){
        System.out.println("Pujcene knihy:\n===================");
        for(String[] item : vsechnyKnihy){
            if(!dostupneCasopisyObsahuje(item)){
                System.out.println("nazev knihy: " + item[0] + " | Autor knihy" + item[1] + " -> " + ctenarInfo.Jmeno + " " + ctenarInfo.Prijmeni);
            }
        }
    }
    public boolean pujcitKnihu(Ctenar ctenar){
        int index = 0;
        for(String[] item : dostupneCasopisy){
            if(mujCasopis[0].equals(item[0]) && mujCasopis[1].equals(item[1])){

                dostupneCasopisy.remove(index);
                ctenarInfo = ctenar;
                return true;
            }
            index++;
        }
        return false;
    }
    public void vratitKnihu(){
        dostupneCasopisy.add(mujCasopis);
        ctenarInfo = null;
    }
    public boolean odepsatKnihu(ArrayList<Kniha> list){
        int index = 0;
        for(String[] item : dostupneCasopisy){
            if(mujCasopis[0].equals(item[0]) && mujCasopis[1].equals(item[1])){

                dostupneCasopisy.remove(index);
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
        for(String[] item : dostupneCasopisy){
            System.out.println("Nazev knihy: " + item[0] + " | Autor knihy: " + item[1]);
        }
    }
}
