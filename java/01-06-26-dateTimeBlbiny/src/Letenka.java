import java.sql.SQLOutput;
import java.time.*;
import java.util.ArrayList;


public class Letenka{

    private final String[] printInfo = {"den", "mesic", "rok", "hodina", "minuta"};
    private static ArrayList<int[]> letenky = new ArrayList<>();

    private String dateTime;
    private String destinace;
    private int[] parseDateTimeArr = new int[5];

    public Letenka(String dateTime, String destinace){

        this.dateTime = dateTime;
        this.destinace = destinace;

        this.parseDateTime();

        if(this.validate()){
            System.out.println("\n!!!\nNelze rezervovat let do minulosti!!!!!!!!!\n!!!");
        }
    }
    public void formateAnswer(){

        LocalDate datum = LocalDate.of(this.parseDateTimeArr[2], this.parseDateTimeArr[1], this.parseDateTimeArr[0]);

        System.out.println("vas let odlita v " + datum.getDayOfWeek().name() + " " + this.parseDateTimeArr[0] + "." + this.parseDateTimeArr[1] + ". v " + this.parseDateTimeArr[3] + ":" + this.parseDateTimeArr[4]);
    }
    public void calculateFlightTime(int cas_h, int cas_m){

        LocalDateTime dateTimeOdletu = LocalDateTime.of(this.parseDateTimeArr[2], this.parseDateTimeArr[1], this.parseDateTimeArr[0], this.parseDateTimeArr[3], this.parseDateTimeArr[4], 0);

        dateTimeOdletu.plusMinutes(cas_m);
        dateTimeOdletu.plusHours(cas_h);

        System.out.println("cas priletu naseho casu bude -> " + dateTimeOdletu);

        ZonedDateTime casPriletuMistnihoCasu = dateTimeOdletu.atZone(ZoneId.of("America/New_York"));
        System.out.println("cas priletu v Americe -> " + casPriletuMistnihoCasu.toString());
    }
    public boolean validate(){

        LocalDateTime now = LocalDateTime.now();
        LocalDateTime dateTimeOdletu = LocalDateTime.of(this.parseDateTimeArr[2], this.parseDateTimeArr[1], this.parseDateTimeArr[0], this.parseDateTimeArr[3], this.parseDateTimeArr[4], 0);
        if(now.isAfter(dateTimeOdletu)){
            return true;
        }
        return false;
    }
    public void calculateLeaveTime(){

        LocalDateTime dateTimeNow = LocalDateTime.now();
        LocalDateTime dateTimeOdletu = LocalDateTime.of(this.parseDateTimeArr[2], this.parseDateTimeArr[1], this.parseDateTimeArr[0], this.parseDateTimeArr[3], this.parseDateTimeArr[4], 0);

        Duration duration = Duration.between(dateTimeNow, dateTimeOdletu);

        System.out.println("\nodlet z Prahy v: " + dateTimeOdletu);

        System.out.println("DO ODLETU ZBÝVÁ:\n============================================");
        System.out.println(duration.toDays() + " dni");
        long hodin = duration.toHours() - duration.toDays()*24;
        System.out.println(hodin + " hodin");
        long minut = duration.toMinutes() - duration.toDays()*24*60 - hodin*60;
        System.out.println(minut + " minut");
    }
    public void parseDateTime(){

        int startIndex = 0;
        int index = 0;

        for(int i = 0; i<5; i++){

            while(this.dateTime.charAt(index) != '.' && this.dateTime.charAt(index) != ' ' && this.dateTime.charAt(index) != ':' && index<this.dateTime.length()-2){
                index++;
            }
            if(i == 4){
                this.parseDateTimeArr[i] = Integer.parseInt(this.dateTime.substring(startIndex, this.dateTime.length()));
            }else{
                this.parseDateTimeArr[i] = Integer.parseInt(this.dateTime.substring(startIndex, index));
            }

            index++;
            startIndex = index;

            System.out.println(this.printInfo[i] + "-> " + parseDateTimeArr[i]);
        }
    }
}
