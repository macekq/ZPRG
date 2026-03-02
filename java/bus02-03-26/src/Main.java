import java.sql.SQLOutput;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        Autobus autobus = new Autobus();
        Cestujici david = new Cestujici();
        Cestujici petr = new Cestujici("petr", "kobliha", 200, 5);
        Cestujici anicka = new Cestujici("anicka", "tkanicka", 800, 12);

        autobus.pribereCestujiciho(david);
        autobus.pribereCestujiciho(petr);
        autobus.pribereCestujiciho(anicka);
    }
}
class Autobus implements busInterface{

    private static final int kapacita = 50;
    private static final int cenaNaZastavku = 5;

    private static int pocetCestujicich = 0;
    private static Cestujici[] cestujiciArr = new Cestujici[kapacita];

    private int findFreeIndex(){
        for(int i = 0; i < cestujiciArr.length; i++){
            if(cestujiciArr[i] == null) return i;
        }
        return -1;
    }
    @Override
    public void pribereCestujiciho(Cestujici cestujici) {
        cestujici.vypis();
        if(pocetCestujicich < kapacita && cestujici.getPenezenka() >= cenaNaZastavku * cestujici.getPocetZastavek()){
            pocetCestujicich++;
            spocitejCenuUctenky(cestujici);
            //System.out.println(findFreeIndex());
            cestujici.setIndex(findFreeIndex());
            cestujiciArr[findFreeIndex()] = cestujici;

        }else System.out.println("smula bus je plny/nemas penize - kdo vi\n");
    }

    @Override
    public void vylozCestujiciho(Cestujici cestujici) {
        pocetCestujicich--;
        cestujiciArr[cestujici.getIndex()] = null;
    }

    @Override
    public void spocitejCenuUctenky(Cestujici cestujici) {
        System.out.println("cena za jizdu: " + cestujici.getPocetZastavek()*cenaNaZastavku);
        cestujici.setPenezenka(cestujici.getPenezenka() - cestujici.getPocetZastavek()*cenaNaZastavku);
        System.out.println("zustatek v penezence: " + cestujici.getPenezenka() + "\n============================\n");
    }
}