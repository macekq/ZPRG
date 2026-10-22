import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Knihovna {
    private final List<Kniha> seznamKnih = new ArrayList<>();

    public void pridejKnihu(Kniha kniha) {
        seznamKnih.add(kniha);
    }

    public List<Kniha> getSeznamKnih() {
        return seznamKnih;
    }

    // Načte zadaný počet knih z konzole a přidá je do knihovny
    public void nactiKnihy(Scanner sc, int pocet) {
        for (int i = 0; i < pocet; i++) {
            System.out.println("\n--- Kniha " + (i + 1) + " ---");

            System.out.print("Zadej ISBN: ");
            String isbn = sc.nextLine();

            System.out.print("Zadej Název: ");
            String nazev = sc.nextLine();

            System.out.print("Zadej rok vydání: ");
            int rok = sc.nextInt();

            System.out.print("Zadej cenu: ");
            int cena = sc.nextInt();
            sc.nextLine(); // Vyčištění bufferu pro další průchod cyklu

            pridejKnihu(new Kniha(isbn, nazev, rok, cena));
        }
    }

    public void vypisKnihy() {
        System.out.println("\n=== Seznam knih ===");
        for (Kniha kniha : seznamKnih) {
            System.out.println(kniha);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Knihovna knihovna = new Knihovna();

        System.out.print("Kolik knih chceš zadat? ");
        int pocet = sc.nextInt();
        sc.nextLine();

        knihovna.nactiKnihy(sc, pocet);
        knihovna.vypisKnihy();

        sc.close();
    }
}
