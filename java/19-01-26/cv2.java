import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class cv2{
    public cv2(){
        File suda = new File("suda.txt");
        try{
            if(!suda.exists()) System.out.println(suda.createNewFile());
        }catch (Exception chyba){
            System.out.println(chyba);
        }

        try(BufferedReader br = new BufferedReader(new FileReader("cisla.txt"))){

            String line;
            while ((line = br.readLine()) != null) {
                if(Integer.parseInt(line) %2 == 0) {
                    //System.out.println(line);

                    try(FileWriter fw = new FileWriter("suda.txt", true)){
                        fw.write(line +  "\n");
                    }catch (Exception chyba) {
                        System.out.println(chyba);
                    }
                }
            }

        }catch(Exception chyba){
            System.out.println(chyba);
        }
    }
}
