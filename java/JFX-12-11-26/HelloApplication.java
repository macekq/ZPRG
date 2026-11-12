package com.example.ukol121126;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import org.controlsfx.control.tableview2.filter.filtereditor.SouthFilter;

import java.io.IOException;

public class HelloApplication extends Application {
    private String jmeno = "[jmeno studenta]";
    private String prijmeni = "[prijmeni studenta]";
    private String znamka = "[znamka]";
    private String predmet = "[predmet]";
    private String ZP = "ze zkouseni";
    private Label vysledek = new  Label();

    @Override
    public void start(Stage stage) throws IOException {
        VBox root = new VBox();
        HBox jmena = new HBox();
        root.getChildren().add(this.vysledek);

        //jmeno prijmeni TF
        TextField jmenoTF = new TextField();
        TextField prijmeniTF = new TextField();

        jmenoTF.promptTextProperty().set("jmeno studenta");
        prijmeniTF.promptTextProperty().set("prijmeni studenta");

        jmenoTF.textProperty().addListener(obs -> {
            System.out.println("Text je nyní: " + jmenoTF.getText());
            this.jmeno = jmenoTF.getText();
            updateVysledek();
        });
        prijmeniTF.textProperty().addListener(obs -> {
            System.out.println("Text je nyní: " + prijmeniTF.getText());
            this.prijmeni = prijmeniTF.getText();
            updateVysledek();
        });
        jmena.getChildren().addAll(jmenoTF, prijmeniTF);
        root.getChildren().add(jmena);


        //radio buttons
        VBox znamkyCont =  new VBox();
        ToggleGroup skupinaZnamek = new ToggleGroup();

        RadioButton[] znamky = new  RadioButton[5];
        for(int i = 0; i < 5; i++){
            RadioButton RB = new  RadioButton("#" + (i+1));

            znamky[i] = RB;
            RB.setToggleGroup(skupinaZnamek);
            znamkyCont.getChildren().add(RB);
        }
        skupinaZnamek.selectedToggleProperty().addListener((obs, stary, novy) -> {
            if (novy != null) {
                System.out.println("Vybrána znamka: " + ((RadioButton) novy).getText());
                this.znamka = ((RadioButton) novy).getText();
                this.updateVysledek();
            }
        });

        //predmety
        VBox predmetyCont =  new VBox();
        ToggleGroup skupinaPredmetu = new ToggleGroup();

        String[] nazvyPredmetu = {"matematika", "cesky jazyk", "programovani", "psani vsemi deseti", "pocitacova grafika"};
        RadioButton[] predmety = new  RadioButton[nazvyPredmetu.length];

        for(int j = 0; j < predmety.length; j++){
            RadioButton RB = new  RadioButton(nazvyPredmetu[j]);

            predmety[j] = RB;
            RB.setToggleGroup(skupinaPredmetu);
            predmetyCont.getChildren().add(RB);
        }
        skupinaPredmetu.selectedToggleProperty().addListener((obs, stary, novy) -> {
            if (novy != null) {
                System.out.println("Vybrány predmet: " + ((RadioButton) novy).getText());
                this.predmet = ((RadioButton) novy).getText();
                this.updateVysledek();
            }
        });

        CheckBox zkouseni_pisemka = new  CheckBox("zkouseni/pisemka");
        zkouseni_pisemka.setSelected(false);

        zkouseni_pisemka.setOnAction(e -> {
            System.out.println("zkouseni pisemka: " + zkouseni_pisemka.isSelected());
            this.ZP = zkouseni_pisemka.isSelected() ? "z pisemky" : "ze zkouseni" ;
            this.updateVysledek();
        });

        //styly
        HBox znamky_predmety_ZP = new HBox();
        znamkyCont.setPadding(new Insets(0, 50, 0, 0));
        predmetyCont.setPadding(new Insets(0, 50, 0, 0));
        znamky_predmety_ZP.getChildren().addAll(znamkyCont, predmetyCont,  zkouseni_pisemka);
        root.getChildren().add(znamky_predmety_ZP);

        //scena
        Scene scene = new Scene(root, 800, 500);
        stage.setTitle("ahoj cau");
        stage.setScene(scene);
        stage.show();
    }
    public void updateVysledek(){

        this.vysledek.setText("Student "+ this.jmeno + " " +  this.prijmeni + " má " + this.ZP + " z predmetu " + this.predmet + " znamku " + this.znamka);
    }
    public static void main(String[] args) {
        launch();
    }
}