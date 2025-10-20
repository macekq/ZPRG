public class Main {
    public static void main(String[] args) {
        //TIP Press <shortcut actionId="ShowIntentionActions"/> with your caret at the highlighted text
        // to see how IntelliJ IDEA suggests fixing it.
        OSOBA osoba = new OSOBA();
        osoba.setJmeno("petr");
        osoba.setVek(8);

        osoba.vypis();

        BOD bod = new BOD();
        bod.setX(0);
        bod.setY(0);

        System.out.println(bod.kvadrant());

        System.out.println(bod.vzdalenostOdBodu(-4,3));
    }
}