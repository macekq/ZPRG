package com.example.idk;

import javafx.fxml.FXML;
import javafx.scene.control.CheckBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;

import java.net.URL;
import java.text.Collator;
import java.util.Locale;
import java.util.ResourceBundle;

public class HelloController {
    private boolean zobrazPrumer = false;
    private boolean zobrazStarsi = false;
    private boolean zobrazDelsi = false;
    private boolean zobrazAbecedne = false;

    @FXML
    private TextField jmeno1;
    @FXML
    private TextField vek1;
    @FXML
    private TextField jmeno2;
    @FXML
    private TextField vek2;

    @FXML
    private Label vysledek1;
    @FXML
    private Label vysledek2;
    @FXML
    private Label vysledek3;
    @FXML
    private Label vysledek4;

    @FXML
    private CheckBox StrarsiOsobaCHB;
    @FXML
    private CheckBox delsiJmenoCHB;
    @FXML
    private CheckBox prumernyVekCHB;
    @FXML
    private CheckBox prvniAbecedneCHB;

    @FXML
    void clickAbecedne(MouseEvent event) {
        if(prvniAbecedneCHB.isSelected()) this.zobrazAbecedne = true;
        else this.zobrazAbecedne = false;

        updateOutput();
    }
    @FXML
    void clickDelsi(MouseEvent event) {
        if(delsiJmenoCHB.isSelected()) this.zobrazDelsi = true;
        else this.zobrazDelsi = false;

        updateOutput();
    }
    @FXML
    void clickPrumer(MouseEvent event) {
        if(prumernyVekCHB.isSelected()) this.zobrazPrumer = true;
        else this.zobrazPrumer = false;

        updateOutput();
    }
    @FXML
    void clickStarsi(MouseEvent event) {
        if(StrarsiOsobaCHB.isSelected()) this.zobrazStarsi = true;
        else this.zobrazStarsi = false;

        updateOutput();
    }

    @FXML
    public void onHelloButtonClick() {
        updateOutput();
    }

    private void updateOutput(){
        vysledek1.setText("");
        vysledek2.setText("");
        vysledek3.setText("");
        vysledek4.setText("");

        String j1 = jmeno1.getText().trim();
        String j2 = jmeno2.getText().trim();

        if (j1.isEmpty() || j2.isEmpty()) {
            zobrazChybu("Zadej obě jména");
            return;
        }

        int v1;
        int v2;
        try {
            v1 = Integer.parseInt(vek1.getText().trim());
            v2 = Integer.parseInt(vek2.getText().trim());
        } catch (NumberFormatException e) {
            zobrazChybu("Věk musí být celé číslo");
            return;
        }

        if (v1 < 0 || v2 < 0) {
            zobrazChybu("Věk nesmí být záporný");
            return;
        }

        //prumer
        if(this.zobrazPrumer){

            double prumer = (v1 + v2) / 2.0;
            vysledek1.setText("Průměrný věk osob je " + prumer + " let");
        }
        if(this.zobrazStarsi) {
            if (v1 > v2) {
                vysledek2.setText(j1 + " je starší než " + j2);
            } else if (v1 < v2) {
                vysledek2.setText(j1 + " je mladší než " + j2);
            } else {
                vysledek2.setText(j1 + " je stejně starý jako " + j2);
            }
        }

        //delsi jmeno
        if(this.zobrazDelsi) {

            if (j1.length() > j2.length()) {
                vysledek3.setText(j1 + " má delší jméno než " + j2);
            } else if (j1.length() < j2.length()) {
                vysledek3.setText(j1 + " má kratší jméno než " + j2);
            } else {
                vysledek3.setText(j1 + " má stejně dlouhé jméno jako " + j2);
            }
        }

        if(this.zobrazAbecedne){

            Collator collator = Collator.getInstance(Locale.forLanguageTag("cs-CZ"));
            int poradi = collator.compare(j1, j2);
            if (poradi < 0) {
                vysledek4.setText(j1 + " je v abecedě před " + j2);
            } else if (poradi > 0) {
                vysledek4.setText(j1 + " je v abecedě za " + j2);
            } else {
                vysledek4.setText("Obě osoby mají stejné jméno");
            }
        }
    }

    private void zobrazChybu(String zprava) {
        vysledek1.setText(zprava);
        vysledek2.setText("");
        vysledek3.setText("");
        vysledek4.setText("");
    }
}
