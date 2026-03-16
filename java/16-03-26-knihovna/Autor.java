import java.util.ArrayList;

public class Autor{
    public String[] info = new String[4];
    public static ArrayList<String[]> vsichniAutori = new ArrayList<>();

    public Autor(String Jmeno, String Prijmeni, String datumNarozeni, String zeme) {
        this.info[0] = Jmeno;
        this.info[1] = Prijmeni;
        this.info[2] = datumNarozeni;
        this.info[3] = zeme;

        vsichniAutori.add(info);
    }
    public void vypisInformaciOAutorovi(){

        System.out.println("AUTOR:\n==============");
        System.out.println("jmeno Autora: " + this.info[0]);
        System.out.println("prijmeni Autora: " + this.info[1]);
        System.out.println("datum narozeni Autora: " + this.info[2]);
        System.out.println("zeme Autora: " + this.info[3]);
    }
    public void vypsatVsechnyAutory(){

        for(String[] item : vsichniAutori){
            System.out.println("jmeno Autora: " + item[0]);
            System.out.println("prijmeni Autora: " + item[1]);
            System.out.println("datum narozeni Autora: " + item[2]);
            System.out.println("zeme Autora: " + item[3] + "\n\n");
        }
    }
}
