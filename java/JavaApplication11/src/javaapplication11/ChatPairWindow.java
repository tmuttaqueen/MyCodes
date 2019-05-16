package javaapplication11;

import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.TextArea;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.stage.Stage;

public class ChatPairWindow {

    String friendName;
    ClientSender send;

    VBox messageLoader;
    BorderPane root;
    Scene scene;
    Stage stage;

    public ChatPairWindow(String friendName) {
        this.friendName = friendName;
        this.send = new ClientSender();
        this.root = new BorderPane();

        Label friendNameLabel = new Label(friendName);
        friendNameLabel.setFont(new Font("Cambria", 30));
        friendNameLabel.setTextFill(Color.web("#8E44AD"));
        friendNameLabel.setAlignment(Pos.CENTER_LEFT);
        friendNameLabel.setPadding(new Insets(5, 10, 5, 10));
        friendNameLabel.setMaxHeight(40);
        root.setTop(friendNameLabel);

        this.messageLoader = new VBox();
        this.messageLoader.setFillWidth(true);
        ScrollPane messageScroll = new ScrollPane(messageLoader);
        messageScroll.setFitToWidth(true);
        root.setCenter(messageScroll);

        TextArea sendMessage = new TextArea();
        sendMessage.setPromptText("Enter message here");
        sendMessage.setMaxHeight(50);
        sendMessage.setWrapText(true);

        Image img = new Image("sendButton.PNG");
        ImageView goImg = new ImageView(img);
        goImg.setFitHeight(10);
        goImg.setFitWidth(10);

        Button go = new Button(null, goImg);
        go.setOnAction(e -> {
            String message = sendMessage.getText();
            if (!message.equals("")) {
                setMessage(message, null);
                send.sendMessage(friendName + "$ " + message);
            }
            sendMessage.clear();
        });

        VBox sendMessageArea = new VBox(sendMessage, go);
        sendMessageArea.setFillWidth(true);
        sendMessageArea.setStyle("-fx-background-color: #85C1E9;");

        root.setBottom(sendMessageArea);

        this.scene = new Scene(root, 600, 300);

        this.stage = new Stage();
        stage.setScene(scene);
        stage.setTitle(Client.user_name + " with " + friendName);
        stage.show();
        stage.setMinHeight(400);
        stage.setMinWidth(200);
    }

    void setMessage(String message, String senderName) {
        VBox messageBox = new VBox();
        messageBox.setSpacing(5);
        Label messageInfo = new Label(message.trim());
        messageInfo.setWrapText(true);
        messageInfo.setTextFill(Color.web("#FFFFFF"));
        messageInfo.setFont(new Font("Cambria", 16));
        messageInfo.setPadding(new Insets(5, 10, 5, 10));
        messageBox.prefWidthProperty().lessThan(root.widthProperty());
        messageBox.setPadding(new Insets(5, 10, 5, 10));
        messageLoader.getChildren().add(messageBox);

        if (senderName != null) {
            Label senderLabel = new Label(senderName);
            senderLabel.setWrapText(true);
            senderLabel.setPadding(new Insets(0,10,0,5));
            messageBox.getChildren().addAll(senderLabel, messageInfo);
            messageInfo.setStyle("-fx-background-color: #3498DB;");
            messageBox.setAlignment(Pos.CENTER_LEFT);
            messageBox.setStyle("-fx-background-color: #EBF5FB;");
        } else {
            messageBox.getChildren().addAll(messageInfo);
            messageInfo.setStyle("-fx-background-color: #1ABC9C;");
            messageBox.setAlignment(Pos.CENTER_RIGHT);
            messageBox.setStyle("-fx-background-color: #E8F8F5;");
        }

        if (!stage.isShowing()) {
            stage.show();
        } else {
            stage.toFront();
        }

    }

}
