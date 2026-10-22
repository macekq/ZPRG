package com.example.a221026;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.stage.Stage;

import java.io.IOException;

public class HelloApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        //FXMLLoader fxmlLoader = new FXMLLoader(HelloApplication.class.getResource("hello-view.fxml"));
        VBox root = new VBox();

        Label textField = new Label("cau");
        textField.setFont(new Font("Arial bold", 50));

        Button Xadd = new Button("X+");
        Button Xsub = new Button("X-");
        Label Xlabel = new Label("X position control");

        Button Yadd = new Button("Y+");
        Button Ysub = new Button("Y-");
        Label Ylabel = new Label("Y position control");

        root.getChildren().addAll(textField,Xlabel,Xadd,Xsub,Ylabel,Yadd,Ysub);

        Scene scene = new Scene(root, 500, 450);
        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();

        Xadd.setTranslateY(scene.getHeight()-Xadd.getHeight()-Xadd.getLayoutY());
        Xsub.setTranslateY(scene.getHeight()-Xsub.getHeight()-Xsub.getLayoutY()-Xadd.getHeight());

        Yadd.setTranslateY(scene.getHeight()-Yadd.getHeight()-Yadd.getLayoutY());
        Ysub.setTranslateY(scene.getHeight()-Ysub.getHeight()-Ysub.getLayoutY()-Yadd.getHeight());
        Yadd.setTranslateX(Xadd.getWidth());
        Ysub.setTranslateX(Xadd.getWidth());


        Xadd.setOnMouseClicked(e -> {
            if(textField.getTranslateX()+textField.getWidth()+10 <= scene.getWidth()){
                textField.setTranslateX(textField.getTranslateX()+10);
            }
        });
        Xsub.setOnMouseClicked(e -> {
            if(textField.getTranslateX()-10 >= 0){
                textField.setTranslateX(textField.getTranslateX()-10);
            }
        });
        Yadd.setOnMouseClicked(e -> {
            if(textField.getTranslateY()+textField.getHeight()+10 <= scene.getHeight()) {
                textField.setTranslateY(textField.getTranslateY() + 10);
            }
            System.out.println(textField.getTranslateY()+textField.getHeight()+10);
        });
        Ysub.setOnMouseClicked(e -> {
            if(textField.getTranslateY()-10 >= 0){
                textField.setTranslateY(textField.getTranslateY()-10);
            }
            System.out.println(textField.getLayoutY()-10);
        });
    }

    public static void main(String[] args) {
        launch();
    }
}