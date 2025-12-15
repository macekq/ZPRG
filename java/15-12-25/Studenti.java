import java.util.Arrays;
import java.util.Scanner;
public class Studenti{
    private String prijmeni = "";
    private String vsichni = "";

    public Studenti(){
        Scanner sc = new Scanner(System.in);

        System.out.println("Prijmeni: ");
        prijmeni = sc.nextLine();

        while(!prijmeni.equals("KONEC")) {
            vsichni += prijmeni + ' ';
            System.out.println("Prijmeni: ");
            prijmeni = sc.nextLine();
        }
        System.out.println("Vsichni: " + vsichni);

        String[] array = vsichni.split(" ");
        for(int j = 0; j < array.length-1; j++)

        for(int i = 0; i < array.length-1; i++){

            if(array[i].compareTo(array[i+1]) > 0){
                String temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }

        System.out.println(Arrays.toString(array));
    }
}
