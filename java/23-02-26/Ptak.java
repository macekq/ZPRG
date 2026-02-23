public class Ptak extends Zvirata {

    private double rozpetiKridel;

    public Ptak(String druh, double rozpetiKridel) {
        super(druh); // <------ Volání konstruktoru mateřské třídy Zvirata
        this.rozpetiKridel = rozpetiKridel;
    }

    @Override
    public void vypsatVelikost() {
        System.out.println("Ptak: " + druh + ", kridla: " + rozpetiKridel + "m");
    }
}
