import java.util.Objects;
import java.util.Scanner;
public class Retezce{

    private String input;
    private String retezec = "";
    private int delka = 0;

    public Retezce(){
        Scanner sc = new Scanner(System.in);
        do{
            System.out.println("vlozte:");

            input = sc.nextLine();
            System.out.println("vlozeno: " + input);

            retezec += input;
            retezec += "\n";
            delka += input.length()+1;

            if(delka >= 100){
                System.out.println("presazeno 100 znaku");
                break;
            }

        }while(!input.equals("KONEC"));

        for(char i : retezec.toCharArray()){
            System.out.print(i);
        }
    }
}
