import com.sun.security.jgss.GSSUtil;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Scanner;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        cv1 coJaVim = new cv1();
        cv2 idk = new cv2();

        System.out.println("VSECHNA CISLA:\n");
        try(BufferedReader br = new BufferedReader(new FileReader("cisla.txt"))){
            String line;
            int couter = 1;
            while ((line = br.readLine()) != null) {
                int item = Integer.parseInt(line);
                if(couter % 30 == 0) System.out.println(item);
                else System.out.print(item + ", ");
                couter++;
            }
        }catch (Exception chyba){
            System.out.println(chyba);
        }
        System.out.println("\n\n\nVSECHNA SUDA CISLA:\n");
        try(BufferedReader br = new BufferedReader(new FileReader("suda.txt"))){
            String line;
            int couter = 1;
            while ((line = br.readLine()) != null) {
                int item = Integer.parseInt(line);
                if(couter % 30 == 0) System.out.println(item);
                else System.out.print(item + ", ");
                couter++;
            }
        }catch (Exception chyba){
            System.out.println(chyba);
        }

        Scanner sc = new Scanner(System.in);
        System.out.println("\n================================\nsmazat soubory [Y/n]:");
        String userInput = sc.nextLine();
        if(userInput.toLowerCase().contains("y")){

            File cisla = new File("cisla.txt");
            File suda = new File("suda.txt");
            if(!cisla.delete()) System.out.println("soubor cisla.txt se nepodarilo smazat");;
            if(!suda.delete()) System.out.println("soubor suda.txt se nepodarilo");;

        }
    }
}
