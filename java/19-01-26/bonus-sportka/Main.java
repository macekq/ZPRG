import javax.crypto.spec.PSource;
import java.io.File;
import java.io.FileWriter;
import java.util.Random;
import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        //TIP Press <shortcut actionId="ShowIntentionActions"/> with your caret at the highlighted text
        // to see how IntelliJ IDEA suggests fixing it.
        int[] userArr = new int[6];
        int arrIndex = 0;
        Random rand = new Random();
        int[] vyhernaArr = new int[6];


        Scanner sc = new Scanner(System.in);
        System.out.println("vlozte sve jmeno:");
        String jmeno = sc.nextLine();

        //vytvoreni soubouru jmeno.txt
        File soubor = new File(jmeno+".txt");
        try{
            soubor.createNewFile();
        }catch (Exception e){
            System.out.println(e);
        }
        //blbu vzdorne naplnovani userArr
        while(arrIndex < 6){
            try{
                int val;
                do {
                    System.out.println("vase " + (arrIndex + 1) + ". cislo:");
                    String userInput = sc.nextLine();
                    val = Integer.parseInt(userInput);
                }while(doesArrayContain(userArr, val) || val > 49 || val == 0);

                userArr[arrIndex] = val;
                //zapisovani do souboru jmeno.txt
                try(FileWriter fw = new FileWriter(jmeno+".txt", true)){
                    fw.write(String.valueOf(val) +  "\n");
                }catch (Exception chyba) {
                    System.out.println(chyba);
                }
                arrIndex++;
            }catch (NumberFormatException chyba){
                System.out.println(chyba);
            }
        }
        //vytvori soubor vysledek.txt
        File vysledek = new File("vysledek.txt");
        try{
            vysledek.createNewFile();
        }catch (Exception e){
            System.out.println(e);
        }
        //naplni vysledek.txt a vyhernaArr
        for(int i = 0; i < 6; i++){
            int cislo;
            do{
                cislo = rand.nextInt(49)+1;
            }while(doesArrayContain(vyhernaArr, cislo));

            try(FileWriter fw = new FileWriter("vysledek.txt", true)){
                fw.write(String.valueOf(cislo) +  "\n");
            }catch (Exception chyba) {
                System.out.println(chyba);
            }
            vyhernaArr[i] = cislo;
        }
        //vypise vas vysledek
        System.out.println("vyherna cisla:");
        for(int item : vyhernaArr) System.out.print(item + ", ");
        if(compareArrays(userArr, vyhernaArr)) System.out.println("neskutecne\nvyhrali jste");
        else System.out.println("bohuzel nic, prijdte zas");
    }
    public static boolean doesArrayContain(int[] arr, int val){
        for(int item : arr){
            if(item == val) return true;
        }
        return false;
    }
    public static boolean compareArrays(int arr1[], int arr2[]){
        for(int i = 0; i < arr1.length; i++){
            if(arr1[i] != arr2[i]) return false;
        }
        return true;
    }
}