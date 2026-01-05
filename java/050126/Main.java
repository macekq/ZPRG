import java.sql.SQLOutput;
import java.util.Scanner;
//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static boolean prvocislo(int cislo){
        int couter = 0;
        for(int i = 1; i<=cislo; i++){
            if(cislo%i==0) couter++;
        }
        return couter == 2 ? true : false;
    }
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int p2, p1 = sc.nextInt();
        switch (p1) {
            case 1:
                System.out.println("parametr 2: ");
                p2 = sc.nextInt();
                for (int i = 1; i < p2; i++) System.out.println(i);
                break;

            case 2:
                System.out.println("parametr 2: ");
                p2 = sc.nextInt();
                if (p2 % 2 == 1) p2--;

                int p3 = sc.nextInt();

                for (int i = p2; i < p3; i++) {
                    if (prvocislo(i)) System.out.println(i);
                }

                break;

            default:
                System.out.println("veta:\n");
                String veta;
                do {
                    veta = sc.nextLine();
                } while (veta.length() >= 60 || veta.length() == 0);
                System.out.println(veta);

                boolean last = false;
                for (int i = veta.length() - 1; i >= 0; i--) {
                    if (last || i == veta.length() - 1) System.out.println(Character.toUpperCase(veta.charAt(i)));
                    else System.out.println(Character.toLowerCase(veta.charAt(i)));

                    last = false;
                    if (veta.charAt(i) == ' ') last = true;
                }
        }
    }
}
