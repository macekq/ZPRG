import java.time.Duration;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        Letenka pokus = new Letenka("24.6.2026 15:30", "New_York");
        pokus.calculateLeaveTime();
        pokus.formateAnswer();
        pokus.calculateFlightTime(9,50);
    }
}

