package com.example.lukihojfx;

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.stage.Stage;

import java.io.IOException;
import java.util.concurrent.atomic.AtomicBoolean;

public class HelloApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        //FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("hello-view.fxml"));
        VBox root = new VBox();
        root.setPadding(new Insets(20,50,50,20));
        root.setSpacing(20);

        Button button = new Button("kobliha");
        root.getChildren().add(button);
        button.setPadding(new Insets(20,50,50,20));

        Label label = new Label("zmacni koblihu");
        root.getChildren().add(label);

        button.setOnMouseClicked(event -> {
            if(label.getText().equals("zmacni koblihu")) label.setText("ahoj");
            else label.setText("zmacni koblihu");
        });

        Button button2 = new Button("text size");
        root.getChildren().add(button2);

        AtomicBoolean toggle = new AtomicBoolean(true);
        button2.setOnMouseClicked(event -> {
           if(toggle.get()) {
                toggle.set(false);
               label.setFont(new Font("Arial", 100));
           }else{
               label.setFont(new Font("Arial", 20));
               toggle.set(true);
           };
        });
        Button button3 = new Button("+");
        Button button4 = new Button("-");

        Scene scene = new Scene(root, 500, 450);
        stage.setTitle("ahoj - cau");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}