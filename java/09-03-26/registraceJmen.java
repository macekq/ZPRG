import java.util.ArrayList;
import java.util.Collections;
import java.util.Objects;
import java.util.Scanner;

public class registraceJmen{

    public static ArrayList<String> jmena = new ArrayList<String>();
    Scanner sc = new Scanner(System.in);

    public registraceJmen(){
        System.out.println("zacnene vkladat jmena:\n=======================");
        while(registrace());
        vypis();
    }
    public boolean registrace(){

        String jmeno = sc.nextLine();
        //System.out.println(jmeno + " " + Objects.equals(jmeno, "konec"));
        if(!Objects.equals(jmeno, "konec")) jmena.add(jmeno);
        else return false;

        return true;
    }
    public void vypis(){
        String nejdelsi = "";

        Collections.sort(jmena);
        System.out.println("sorted:\n=======================");
        for(int i = 0; i < jmena.size(); i++){
            if(jmena.get(i).length() > nejdelsi.length()) nejdelsi = jmena.get(i);

            System.out.println(i+1 + ": " + jmena.get(i));
        }
        System.out.println("nejdelsi: " + nejdelsi + "  len:" + nejdelsi.length());
    }
}
