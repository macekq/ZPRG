public class Letiste{
    private String kodIATA;
    private String mesto;
    private String casovePasmo;

    public Letiste(String kodIATA, String mesto, String casovePasmo) {
        this.kodIATA = kodIATA;
        this.mesto = mesto;
        this.casovePasmo = casovePasmo;
    }

    public String getCasovePasmo() {
        return casovePasmo;
    }
    public String getKodIATA() {
        return kodIATA;
    }
    public String getMesto() {
        return mesto;
    }
}
