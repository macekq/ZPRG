//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        Kniha MOJE = new Kniha("promena", 120);
        Kniha SPOLUZAK = new Ucebnice("jirasek", 200, "matematika");
        Kniha JEHO = new Kniha();
        Kniha JEJI = new Ucebnice();

        MOJE.vypis();
        SPOLUZAK.vypis();
        JEHO.vypis();
        JEJI.vypis();

        MOJE.printCelkovyPocet();
    }
}
