import java.util.ArrayList;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        Autor GRRM = new Autor("george", "martin", "01.01.1980", "UK");
        Kniha GOT = new Kniha("game of thrones", GRRM);
        Kniha FFC = new Kniha("feast for crows", GRRM);
        Ctenar Petr = new Ctenar("petr", "kobliha");
        Ctenar patrik = new Ctenar("patrik", "domichal");
        Kniha masinkaTomas = new Kniha("masinka tomas", GRRM);

        GOT.vypisDostupnych();
        Petr.pujcitKnihu(GOT);
        GOT.vypisPujcenych();
        Petr.pujcitKnihu(FFC);

        FFC.vypisPujcenych();

        patrik.pujcitKnihu(masinkaTomas);
        masinkaTomas.vypisPujcenych();
    }
}
