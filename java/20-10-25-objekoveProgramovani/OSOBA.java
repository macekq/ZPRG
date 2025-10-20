public class OSOBA{
    private String jmeno;
    private int vek;

    public OSOBA(){}

    public void setJmeno(String jmeno){
        this.jmeno = jmeno;
    }
    public void setVek(int vek){
        this.vek = vek;
    }
    public void vypis(){
        System.out.println(this.jmeno);
        System.out.println(this.vek);

        System.out.printf("jmeno je: %s\nvek je: %d\n",this.jmeno,this.vek);
    }
}//TI
// P To <b>Run</b> code, press <shortcut actionId="Run"/> or
