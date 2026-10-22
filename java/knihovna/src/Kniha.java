public class Kniha {
    private String isbn;
    private String nazev;
    private int rokVydani;
    private int cena;

    public Kniha(String isbn, String nazev, int rokVydani, int cena) {
        this.isbn = isbn;
        this.nazev = nazev;
        this.rokVydani = rokVydani;
        this.cena = cena;
    }

    public String getIsbn() {
        return isbn;
    }

    public void setIsbn(String isbn) {
        this.isbn = isbn;
    }

    public String getNazev() {
        return nazev;
    }

    public void setNazev(String nazev) {
        this.nazev = nazev;
    }

    public int getRokVydani() {
        return rokVydani;
    }

    public void setRokVydani(int rokVydani) {
        this.rokVydani = rokVydani;
    }

    public int getCena() {
        return cena;
    }

    public void setCena(int cena) {
        this.cena = cena;
    }

    @Override
    public String toString() {
        return "ISBN: " + isbn + ", Název: " + nazev
                + ", Rok vydání: " + rokVydani + ", Cena: " + cena + " Kč";
    }
}
