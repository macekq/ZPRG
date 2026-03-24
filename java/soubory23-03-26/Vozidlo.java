import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardCopyOption;
import java.nio.file.StandardOpenOption;
import java.time.LocalDateTime;

public class Vozidlo{

    private final String path = "C:\\Users\\l.macura.st\\Desktop\\EVILADRESAR\\ukol23-03-26\\";
    Majitel majitel;
    private String[] infoOAutu = new String[4];

    public Vozidlo(Majitel majitel, String SPZ, String znacka, String model, String rokVyroby){

        this.majitel = majitel;
        infoOAutu[0] = SPZ;
        infoOAutu[1] = znacka;
        infoOAutu[2] = model;
        infoOAutu[3] = rokVyroby;

        zapisAuto();
    }
    public void zapisAuto(){
        File soubor = new File(majitel.getPath() + "\\" + infoOAutu[0] + ".txt");
        try (BufferedWriter bw = new BufferedWriter(new FileWriter("large_file.txt", true))) {

            if (!soubor.exists()){
                System.out.println(soubor.createNewFile());

                Path cesta = Path.of(majitel.getPath() + "\\" + infoOAutu[0] + ".txt");
                for(String info : infoOAutu){
                    Files.writeString(cesta, info + "|", StandardOpenOption.APPEND);
                }
                LocalDateTime now = LocalDateTime.now();
                Files.writeString(cesta, now +"\n", StandardOpenOption.APPEND);
            }
        } catch (IOException e) {
            System.out.println(e);;
        }
    }
    public void smazatZapis() throws IOException {
        Path cesta = Path.of(majitel.getPath() + "\\" + infoOAutu[0] + ".txt");
        Files.delete(cesta);
    }
    public void zmenitMajitele(Majitel majitel2){
        Path ZE = Path.of(this.majitel.getPath() + "\\" + infoOAutu[0] + ".txt");
        Path DO = Path.of(majitel2.getPath() + "\\" + infoOAutu[0] + ".txt");
        try{
            Files.move(ZE, DO, StandardCopyOption.REPLACE_EXISTING);
        }catch (IOException e){
            System.out.println(e);
        }
    }
}
