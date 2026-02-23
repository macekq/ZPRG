import java.util.Random;

public class Main {
    public static void main(String[] args) {

        Zvirata[] zoo = new Zvirata[6];

        for (int i = 0; i < zoo.length; i++) {
            int nahodnaVolba = (int)Math.floor(Math.random()*3);

            double nahodnaVelikost = Math.floor(Math.random()*10);

            switch (nahodnaVolba) {
                case 0:
                    zoo[i] = new Ptak("stehovavy", nahodnaVelikost);
                    break;
                case 1:
                    zoo[i] = new Slon("indicky", nahodnaVelikost);
                    break;
                case 2:
                    zoo[i] = new Had("dlouhy", nahodnaVelikost);
                    break;
            }
        }
        //Demonstrace polymorfismu
        for (Zvirata zvire : zoo) {
            zvire.vypsatVelikost();
        }
    }
}