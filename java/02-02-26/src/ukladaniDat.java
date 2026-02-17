import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class ukladaniDat{
    public static ArrayList<Integer> nazvySouboru = new ArrayList<>();
    public static int max = 0;
    public static String path = "C:\\Users\\l.macura.st\\Desktop\\EVILADRESAR";

    public ukladaniDat(){
        Scanner sc = new Scanner(System.in);
        String directoryPath;

        do{
            System.out.println();
            System.out.println("vlozte vas adresar:");
            directoryPath = sc.nextLine();

        }while(directoryPath != "");

        File dir = new File(directoryPath);

        path = directoryPath + "\\DATA";
        File data = new File(path);
        if(data.exists()) data.mkdir();

        cteniAdresare(path);
        setMaxNum();
        String userInput = "";
        boolean ok = false;
        do{
            System.out.println("vlozte pocet souboru pro vytvoireni:");
            try{
                userInput = sc.nextLine();
                System.out.println(userInput + " " + Integer.parseInt(userInput));
                ok = true;
            }catch(Exception e){
                System.out.println(e);
            }
        }while(!ok);
        vytvareniSouboru(Integer.parseInt(userInput));
    }
    public static void vytvareniSouboru(int pocet){
        for(int i = 1; i<=pocet; i++) {
            File soubor = new File(path + "\\" + "data" +  (max+i) + ".txt");
            try {
                if (!soubor.exists()) System.out.println(soubor.createNewFile());
            } catch (Exception chyba) {
                System.out.println(chyba);
            }
        }
    }
    public static int posledniIndex(String nazev){
        for(int i = nazev.length()-1; i>=0; i--){
            if(nazev.charAt(i) == '.') return i;
        }
        return -1;
    }
    public static void setMaxNum(){
        for(int i = 0; i < nazvySouboru.size(); i++){
            if(nazvySouboru.get(i) > max) max = nazvySouboru.get(i);
        }
    }
    public static void cteniAdresare(String dir){
        File directory = new File(dir);

        if (directory.exists() && directory.isDirectory()){

            String[] files = directory.list();
            for (String fileName : files){

                File soubor = new File(dir + "\\" + fileName);
                if(posledniIndex(fileName) > 0){

                    String toParse = fileName.substring(0, posledniIndex(fileName));
                    try {
                        nazvySouboru.add(Integer.parseInt(toParse));
                        System.out.println(Integer.parseInt(toParse));
                    }catch(Exception e){};
                }
                System.out.print(fileName + " ->" + soubor.length()/1024.0 + "KB\n");
            }

            System.out.println(nazvySouboru.size());
            for(int i = 0; i<nazvySouboru.size(); i++) {
                System.out.println("item-> " + nazvySouboru.get(i));
            }
        }
    }
}
