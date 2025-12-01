import java.awt.*;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {

        NABYTEK A = new NABYTEK(100, "kov/plast", Color.red);
        A.vypis();

        System.out.println("===============");

        SKRIN B = new SKRIN(200,100,50,10000);
        B.vypis();
        System.out.println("objem skrine: " + B.getObjem());

        System.out.println("===============");

        NABYTEK C = new NABYTEK(200, "plast", Color.cyan);
        C.vypis();

        System.out.println("===============");

        STUL D = new STUL();
        D.vypis();

        NABYTEK[] nabytek = new NABYTEK[]{B, D};
        for(NABYTEK nabytek1 : nabytek){
            System.out.println("<=============>");
            nabytek1.vypis();
        }
    }
}
/*
Vytvořte třídu nábytek:
Atributy: materiál, hmotnost (zvolte vhodné datové typy)..
Metody:
        • implicitní konstruktor - nastaví materiál na „dřevotříska“ a hmotnost na 25 kg.
• inicializační konstruktor – nastaví atributy podle zadaných hodnot
• výpis informací o nábytku
• funkci pro návrat hodnoty atributu hmotnost.

Vytvořte třídu skříň jako potomka třídy nábytek:
Atributy: výška, šířka a hloubka (zvolte vhodné datové typy).
Metody:
        • implicitní konstruktor - nastaví materiál na „dřevo“, 40 kg a rozměry 150 x 100 x 40.
        • inicializační konstruktor – nastaví atributy podle zadaných hodnot
• výpis informací o skříni


Vytvořte třídu stůl jako potomka třídy nábytek:
Atributy: výška, šířka a hloubka (zvolte vhodné datové typy).
Metody:
        • implicitní konstruktor - nastaví materiál na „dřevo“, 40 kg a rozměry 150 x 100 x 40.
        • inicializační konstruktor – nastaví atributy podle zadaných hodnot
• výpis informací o stole

Vytvořte objekty:
        - A třídy NABYTEK s načtenými atributy
- B třídy SKRIN s načtenými atributy
- C třídy NABYTEK s implicitními atributy
- D třídy STUL s implicitními atributy
a vypište informace o těchto objektech.
Upravte třídu skříň abychom mohli evidovat celkový objem všech zavedených skříní.
        */