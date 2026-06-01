import java.time.Duration;
import java.time.LocalDateTime;
import java.time.ZonedDateTime;

public abstract class Let {

    private String cisloLetu;
    private Letiste letisteOdletu;
    private Letiste letistePriletu;
    private LocalDateTime planovanyOdlet;
    private Duration dobaLetu;

    public Let(String cisloLetu, Letiste letisteOdletu, Letiste letistePriletu, LocalDateTime planovanyOdlet, Duration dobaLetu) {
        this.cisloLetu = cisloLetu;
        this.letisteOdletu = letisteOdletu;
        this.letistePriletu = letistePriletu;
        this.planovanyOdlet = planovanyOdlet;
        this.dobaLetu = dobaLetu;
    }
    public String getCisloLetu() {
        return this.cisloLetu;
    }
    public Letiste getLetisteOdletu() {
        return this.letisteOdletu;
    }
    public Letiste getLetistePriletu() {
        return this.letistePriletu;
    }
    public Duration getDobaLetu() {
        return this.dobaLetu;
    }

    public abstract ZonedDateTime getMistniCasOdletu(){return this.planovanyOdlet;}
}
