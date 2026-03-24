import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;

public class Majitel{
    private String jmeno, prijmeni, adresa;
    private String majitelovoId;
    private String path = "C:\\Users\\l.macura.st\\Desktop\\EVILADRESAR\\ukol23-03-26\\";

    public Majitel(String Jmeno, String Prijmeni, String Adresa){

        this.jmeno = Jmeno;
        this.prijmeni = Prijmeni;
        this.adresa = Adresa;

        majitelovoId = jmeno + "_" + prijmeni + "_" + adresa;

        vytvoritAdresar();
    }
    public void vytvoritAdresar(){
        path = path + majitelovoId;
        Path slozka = Path.of(path);
        try{
            Files.createDirectories(slozka);
        }catch (IOException e){
            System.out.println(e);
        }
    }
    public String getPath(){
        return path;
    }
    public String getMajitelovoId(){
        System.out.println(majitelovoId);
        return majitelovoId;
    }
}
