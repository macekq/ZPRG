package com.example.calc;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Background;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.Random;

public class HelloApplication extends Application {

    @Override
    public void start(Stage stage) throws IOException {

        VBox root = new VBox();

        //textova pole
        HBox textBox = new HBox();

        TextField num1Field = new TextField();
        num1Field.setPrefWidth(160);
        textBox.getChildren().add(num1Field);

        TextField num2Field = new TextField();
        num1Field.setPrefWidth(160);
        textBox.getChildren().add(num2Field);

        //vysledek
        VBox result = new VBox();
        Text resultField = new Text();
        result.getChildren().add(resultField);

        //operace
        HBox operace =  new HBox(10);
        operace.setAlignment(Pos.CENTER);
        operace.setPadding(new Insets(15));

        Button[] buttons = new Button[4];

        Button scitaniBtt = new Button("+");
        buttons[0] = scitaniBtt;

        Button odcitaniBtt = new Button("-");
        buttons[1] = odcitaniBtt;

        Button nasobeniBtt = new Button("*");
        buttons[2] = nasobeniBtt;

        Button deleniBtt = new Button("/");
        buttons[3] = deleniBtt;

        //eventhandler foreach Btt
        for(Button B : buttons) {
            B.setPrefSize(32, 32);
            operace.getChildren().add(B);
            B.addEventHandler(MouseEvent.MOUSE_CLICKED,e -> {

                System.out.println(B.getText());


                boolean maCislo = num1Field.getText().matches(".*\\d.*") && num2Field.getText().matches(".*\\d.*");
                if(maCislo) {

                    float num1 = Float.parseFloat(num1Field.getText());
                    float num2 = Float.parseFloat(num2Field.getText());

                    switch (B.getText()) {
                        case "+":
                            resultField.setText(String.valueOf(num1 + num2));
                            break;
                        case "-":
                            resultField.setText(String.valueOf(num1 - num2));
                            break;
                        case "*":
                            resultField.setText(String.valueOf(num1 * num2));
                            break;
                        case "/":
                            if(num2 == 0) {
                                System.out.println("nemuzes delit nulou 🤐");
                            }else {
                                resultField.setText(String.valueOf(num1 / num2));
                            }
                            break;
                    }
                }else{
                    System.out.println("tady nemuzes pocitat text 😜");
                }
            });
        }
        //pozadi
        VBox zmenaCont =  new VBox();
        Button zmenaBgBtt = new Button("zmena pozadi");

        zmenaBgBtt.addEventHandler(MouseEvent.MOUSE_CLICKED,e -> {

            String styleText = "-fx-background-color: rgb(";
            for(int i = 0; i < 3; i++) {
                styleText += (int)(Math.random()*256);
                if(i != 2)  styleText += ",";
            }
            styleText += ")";
            System.out.println(styleText);
            root.setStyle(styleText);
        });

        zmenaCont.getChildren().add(zmenaBgBtt);

        result.setAlignment(Pos.BASELINE_CENTER);
        result.setStyle("-fx-text-fill: #000000;");
        resultField.setStyle("-fx-font-size: 32px");

        VBox.setMargin(operace,  new Insets(10));

        VBox.setMargin(textBox,  new Insets(10));

        root.getChildren().add(textBox);
        root.getChildren().add(result);
        root.getChildren().add(operace);
        root.getChildren().add(zmenaCont);

        root.setStyle("-fx-background-color: #da12d5;");
        //scena
        Scene scene = new Scene(root, 320, 200);
        stage.setTitle("calc");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}