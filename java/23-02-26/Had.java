public class Had extends Zvirata {

    private double delkaTela;

    public Had(String druh, double delkaTela) {
        super(druh); // <------ volani materske tridy (zvirata)
        this.delkaTela = delkaTela;
    }

    @Override
    public void vypsatVelikost() {

        System.out.println("Had: " + druh + ", telo: " + delkaTela + "m");
    }
}
