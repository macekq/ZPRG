import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Random;

public class cv1{

    public static int soucet = 0;

    public cv1(){

        try {
            File soubor = new File("cisla.txt");
            String path = soubor.getAbsolutePath();
            //System.out.println(path);

            int counter = 0;
            while(soucet < 100){
                pridatCislo(counter);
                counter++;
            }
            if(!soubor.exists()) System.out.println(soubor.createNewFile());
        }catch (Exception chyba) {
                System.out.println(chyba);
        }
    }
    public static void pridatCislo(int couter){
        Random rand = new Random();
        int cislo = rand.nextInt(21)-10;
        soucet += cislo;

        //System.out.println(soucet + " | " + cislo);

        try(FileWriter fw = new FileWriter("cisla.txt", true)){
            fw.write(String.valueOf(cislo) +  "\n");
        }catch (Exception chyba) {
            System.out.println(chyba);
        }

    }
}