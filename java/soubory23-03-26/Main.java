import java.io.IOException;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) throws IOException {

        Majitel karel = new Majitel("karel", "barel", "ova");
        Vozidlo fabie = new Vozidlo(karel, "1TF-0826", "skoda", "fabia", "1998");
        Vozidlo octavka = new Vozidlo(karel, "123-ABCD", "skoda", "octavia", "2002");

        Majitel petr = new Majitel("petr", "kobliha", "ova");
        fabie.zmenitMajitele(petr);

        Vozidlo masinkaTomas = new Vozidlo(petr, "XYZ-6789", "CD", "rychly", "1920");
        //masinkaTomas.smazatZapis();

        Registr reg = new Registr();
        reg.vypsatAutaMajitele(petr);
    }
}
