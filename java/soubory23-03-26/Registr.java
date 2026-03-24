import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;

public class Registr{

    public static void vypsatAutaMajitele(Majitel majitel){

        System.out.println(majitel.getPath());
        File dir = new File(majitel.getPath());
        //System.out.println(dir.isDirectory() + " | " + dir.exists());
        if(!dir.exists() && !dir.isDirectory()){

            String[] obsah = dir.list();
            for(String item : obsah){
                System.out.println(item);
                vypisSoubor(majitel.getPath() + "\\" + item);
            }
        }
    }
    public static void vypisSoubor(String souborPath){

        Path dir = Path.of(souborPath);
        try {
            String readContent = Files.readString(dir);
            System.out.println(readContent);
        }catch(IOException e){
            System.out.println(e);
        }
    }
}
