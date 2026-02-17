import java.io.File;
import java.util.Scanner;

public class vypisAdresare{
    public static final String RESET = "\033[0m";
    public static final String CYAN = "\033[0;36m";
    public static int pocetSouboru = 0;

    public vypisAdresare(){

        Scanner sc = new Scanner(System.in);
        String directoryPath;

        do{
            System.out.println();
            System.out.println("vlozte vas adresar:");
            directoryPath = sc.nextLine();

            obsahAdresare(directoryPath, 0);
        }while(directoryPath != "");
    }
    public static void obsahAdresare(String dir, int distance){
        File directory = new File(dir);

        if (directory.exists() && directory.isDirectory()){

            String[] files = directory.list();
            pocetSouboru = 0;
            for (String fileName : files){
                File soubor = new File(dir + "\\" + fileName);

                for(int i = 0; i<distance; i++)System.out.print(" - ");

                if(!soubor.isFile()){
                    System.out.print(CYAN + fileName + " ->" + soubor.length()/1024.0 + "KB\n" + RESET);
                    obsahAdresare(soubor.getAbsolutePath(), distance+1);

                }else {
                    pocetSouboru++;
                    System.out.print(fileName + " ->" + soubor.length() / 1024.0 + "KB\n");
                }
            }

        } else System.out.println("*");
        System.out.println("pocet -> " + pocetSouboru);
    }
}
