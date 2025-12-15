import java.util.Scanner;
public class Ctecka{

    private String name;

    public Ctecka(){
        Scanner sc = new Scanner(System.in);
        System.out.println("vlozte vetu:");

        name = sc.nextLine();
        System.out.println("veta: "+ name);
    }
    public void pozpatku(){

        /*for(int i = name.length()-1; i>=0; i--){
            System.out.print(name.charAt(i));
        }*/
        int delka = name.length();
        for(int i = 0; i < delka; i++){
            System.out.println(name.charAt(delka-i-1));
        }
    }
    public void slovoNaRadek(){
        /*for(char i : name.toCharArray()){
            if(i == ' ') System.out.print('\n');
            else System.out.print(i);
        }*/
        String[] slova = name.split(" ");
        for(String s : slova){
            System.out.println(s);
        }
    }
    public void d(){
        /*
        boolean last = true;
        for(char i : name.toCharArray()){
            if(i == ' '){
                System.out.print('\n');
                last = true;
            }
            else if(last){
                System.out.print(Character.toUpperCase(i));
                last = false;
            }else System.out.print(i);
        }
        */
        String[] slova = name.split(" ");
        for(String s : slova){
            System.out.print(Character.toUpperCase(s.charAt(0)));

            for(int i = 1; i < s.length(); i++){
                System.out.print(s.charAt(i));
            }
            System.out.print(' ');
        }
        System.out.println();
    }
    public int pocetZnakuVeVete(String veta, char znak){
        int counter = 0;
        for(char i : veta.toCharArray()){
            if(znak == i) counter++;
        }
        return counter;
    }
}
