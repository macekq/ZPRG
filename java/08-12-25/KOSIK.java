public class KOSIK{
    private static int pocetPolozek = 0;
    private static int celkovaCena = 0;
    private static POLOZKA[] obsah = new POLOZKA[20];
    private static int index = 0;

    public static void pridatPolozku(POLOZKA p){
        if(index >= 19){
            System.out.println("chybova hlaska");
            return;
        }

        obsah[pocetPolozek] = p;
        pocetPolozek++;
        p.vypis();
    }
    public static void vypisSouhrn(){
        for(POLOZKA i : obsah){
            System.out.println("id: " + i.getId() + "\nnazev: " + i.getNazev() + "\ncena: " + i.getCenaPolozky());
            celkovaCena += i.getCenaPolozky();
        }
        System.out.println("celkovaCena: " + celkovaCena);
    }
}
