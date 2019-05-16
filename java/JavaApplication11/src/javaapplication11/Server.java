package javaapplication11;

import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import javafx.scene.layout.TilePane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class Server extends Application {

    Scene scene1, scene2;
    static VBox signIn, referMessage, warning;
    static ServerThread read;
    static String serverName;
    static int serverPort;

    public static void main(String[] args) {
        try {
            System.out.println(InetAddress.getLocalHost());
        } catch (UnknownHostException ex) {
            Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
        }
        if (args.length >= 1) {
            new ServerThread(args[0], 8000);
        } else {
            launch(args);
        }
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        signIn = new VBox();
        signIn.setFillWidth(true);
        signIn.setSpacing(10);
        signIn.setMinWidth(200);
        signIn.setStyle("-fx-background-color: #2E86C1;");
        referMessage = new VBox();
        referMessage.setFillWidth(true);
        referMessage.setSpacing(10);
        referMessage.setMinWidth(200);
        referMessage.setStyle("-fx-background-color: #138D75;");
        warning = new VBox();
        warning.setFillWidth(true);
        warning.setSpacing(10);
        warning.setMinWidth(200);
        warning.setStyle("-fx-background-color: #A93226;");

        GridPane starter = new GridPane();
        starter.setAlignment(Pos.CENTER);
        starter.setVgap(5);
        starter.setHgap(5);

        Label nameLabel = new Label("Server Name:");
        starter.add(nameLabel, 0, 0);

        TextField nameInput = new TextField();
        nameInput.setPromptText("Enter server name");
        starter.add(nameInput, 1, 0);

        Label portLabel = new Label("Server Port:");
        starter.add(portLabel, 0, 1);

        TextField portInput = new TextField();
        portInput.setPromptText("Enter server port");
        starter.add(portInput, 1, 1);

        Image img = new Image("sendButton.PNG");
        ImageView send = new ImageView(img);
        send.setFitHeight(10);
        send.setFitWidth(10);

        Button logIn = new Button(null, send);
        VBox logInBox = new VBox();
        logInBox.getChildren().add(logIn);
        logInBox.setAlignment(Pos.CENTER_RIGHT);
        starter.add(logInBox, 1, 2);
        logIn.setDefaultButton(true);
        logIn.setOnAction(e -> {
            serverName = nameInput.getText();
            if (serverName.equals("")) {
                nameInput.requestFocus();
            } else if (portInput.getText().equals("")) {
                portInput.requestFocus();
            } else {
                serverPort = Integer.parseInt(portInput.getText());
                read = new ServerThread(serverName.trim(), serverPort);
                primaryStage.setScene(scene2);
                primaryStage.setTitle("Server: " + serverName + ", Port: " + serverPort);
            }
        });

        scene1 = new Scene(starter, 400, 100);

        HBox root = new HBox();
        root.setFillHeight(true);

        ScrollPane signInScroll = new ScrollPane(signIn);
        signInScroll.setFitToWidth(true);
        root.getChildren().add(signInScroll);
        setSignInInfo("   Sign In Information");
        ScrollPane referMessageScroll = new ScrollPane(referMessage);
        referMessageScroll.setFitToWidth(true);
        root.getChildren().add(referMessageScroll);
        setReferMesgInfo("   Messaging Information");
        ScrollPane warningScroll = new ScrollPane(warning);
        warningScroll.setFitToWidth(true);
        root.getChildren().add(warningScroll);
        setWarningInfo("   Warning Information");

        HBox.setHgrow(signInScroll, Priority.SOMETIMES);
        HBox.setHgrow(referMessageScroll, Priority.SOMETIMES);
        HBox.setHgrow(warningScroll, Priority.SOMETIMES);

        scene2 = new Scene(root, 600, 400);
        primaryStage.setScene(scene1);
        primaryStage.setTitle("Server: Log In");
        primaryStage.centerOnScreen();
        primaryStage.setMinHeight(100);
        primaryStage.setMinWidth(150);
        primaryStage.show();
    }

    void setSignInInfo(String info) {
        Label infoBar = new Label(info);
        infoBar.setTextFill(Color.web("#FFFFFF"));
        infoBar.setPadding(new Insets(5, 10, 5, 10));
        signIn.getChildren().add(infoBar);
    }

    void setReferMesgInfo(String info) {
        Label infoBar = new Label(info);
        infoBar.setTextFill(Color.web("#FFFFFF"));
        infoBar.setPadding(new Insets(5, 10, 5, 10));
        referMessage.getChildren().add(infoBar);
    }

    void setWarningInfo(String info) {
        Label infoBar = new Label(info);
        infoBar.setTextFill(Color.web("#FFFFFF"));
        infoBar.setPadding(new Insets(5, 10, 5, 10));
        warning.getChildren().add(infoBar);
    }

    @Override
    public void stop() {
        if (read != null) {
            read.isRunning = false;
            try {
                new ServerProcessingThread(null, serverName, InetAddress.getLocalHost(), serverName);
            } catch (UnknownHostException ex) {
                Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }

}
