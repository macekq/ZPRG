//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        //TIP Press <shortcut actionId="ShowIntentionActions"/> with your caret at the highlighted text
        // to see how IntelliJ IDEA suggests fixing it.
        System.out.printf("Hello and welcome!");

        for (int i = 1; i <= 5; i++) {
            //TIP Press <shortcut actionId="Debug"/> to start debugging your code. We have set one <icon src="AllIcons.Debugger.Db_set_breakpoint"/> breakpoint
            // for you, but you can always add more by pressing <shortcut actionId="ToggleLineBreakpoint"/>.

            System.out.println("i = " + i + " | i^2 = " + i * i);
        }

        cislo1();
        cislo2();
        cislo3();
        cislo4();
        cislo5();
    }

    public static void cislo1() {
        Scanner scanner = new Scanner(System.in);
        int num = 1;
        do {
            System.out.printf("vlozte cislo -> ");
            num = scanner.nextInt();
            System.out.printf("num = %d | num^2 = %d\n\n", num, num * num);
        } while (num != 0);
    }

    public static void cislo2() {
        for (int i = 1; i <= 20; i++) {
            System.out.printf("\n%d", i);
            for (int j = 0; j < i; j++) System.out.printf("*");
        }
    }

    public static void cislo3() {
        Scanner scanner = new Scanner(System.in);
        int num = 1;
        do {
            System.out.printf("\nvlozte cislo -> ");
            num = scanner.nextInt();
            System.out.printf(num > 50 ? "moc velke cislo" : "num = %d | ", num);
            if (num <= 50) for (int j = 0; j < num; j++) System.out.printf("*");
        } while (num != 0);

    }

    public static void cislo4() {
        Scanner scanner = new Scanner(System.in);
        int num = 1;
        int num2;
        System.out.printf("vlozte cislo -> ");
        num2 = scanner.nextInt();
        System.out.printf("vlozte cislo -> ");
        num = scanner.nextInt();

        if (num > num2) {
            for (int i = num2; i <= num; i++) System.out.printf("\n%d", i);
        }else if(num == num2){
            System.out.printf("%d", num);
        }else{
            for (int i = num; i >= num2; i++) System.out.printf("\n%d", i);
        }
    }

    public static void cislo5() {
        int soucet = 0;
        for (int i = 1000; i < 2000; i++) {
            if (i % 2 == 0) soucet += i;
        }
        System.out.printf("\n\nsoucet = %d\n", soucet);
    }
}
