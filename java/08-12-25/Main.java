//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        POLOZKA polozka1 = new POLOZKA("lopata", 1000);
        POLOZKA polozka2 = new POLOZKA("cepice", 500);

        KOSIK kosik = new KOSIK();
        kosik.pridatPolozku(polozka1);
        kosik.pridatPolozku(polozka2);

        kosik.vypisSouhrn();
    }
}
