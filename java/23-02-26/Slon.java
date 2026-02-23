public class Slon extends Zvirata {

    private double delkaChobotu;

    public Slon(String druh, double delkaChobotu) {
        super(druh); // <------ Volání konstruktoru mateřské třídy Zvirata
        this.delkaChobotu = delkaChobotu;
    }

    @Override
    public void vypsatVelikost() {
        System.out.println("Slon: " + druh + ", chobot: " + delkaChobotu + "m");
    }
}
