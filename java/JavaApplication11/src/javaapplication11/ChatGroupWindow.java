package javaapplication11;

import static java.lang.Thread.sleep;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Vector;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.Border;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class ChatGroupWindow {

    ArrayList<String> friendNames = new ArrayList<>();
    ArrayList<String> xtraNames = new ArrayList<>();
    String groupName;
    String userName;
    String encodedSender;
    String codeDivider;
    String newMembers;

    VBox messageLoader;
    HBox member;
    BorderPane root;
    Scene scene;
    Stage stage;

    public ChatGroupWindow(String groupName, String userName, String groupMembers) {
        this.codeDivider = "|";
        this.groupName = groupName;
        this.userName = userName;
        this.encodedSender = new String();
        this.newMembers = new String();
        this.root = new BorderPane();
        this.member = new HBox(new Text(userName));
        this.member.setPadding(new Insets(5, 5, 5, 5));
        this.member.setSpacing(10);

        if (groupMembers != null) {
            StringTokenizer decoder = new StringTokenizer(groupMembers, codeDivider);
            while (decoder.hasMoreTokens()) {
                String temp = decoder.nextToken();
                if (!temp.equals(userName)) {
                    friendNames.add(temp);
                    encodedSender = encodedSender.concat(codeDivider + temp);
                    member.getChildren().add(new Text(temp));
                }
            }
        }
        Label friendNameLabel = new Label(groupName);
        friendNameLabel.setFont(new Font("Cambria", 30));
        friendNameLabel.setTextFill(Color.web("#8E44AD"));
        friendNameLabel.setAlignment(Pos.CENTER_LEFT);
        friendNameLabel.setPadding(new Insets(5, 10, 5, 10));
        friendNameLabel.setMaxHeight(40);

        TextField nameInput = new TextField();
        nameInput.setPromptText("Include people");

        Image img = new Image("sendButton.PNG");
        ImageView goImg = new ImageView(img);
        goImg.setFitHeight(10);
        goImg.setFitWidth(10);
        Button set = new Button(null, goImg);
        set.setOnAction(e -> {
            String friendName = nameInput.getText();
            if (!friendName.equals("") && !friendName.equals(userName)) {
                xtraNames.add(friendName);
                member.getChildren().add(new Text(friendName));
                newMembers = newMembers.concat(codeDivider + friendName);
            }
            nameInput.clear();
        });

        HBox inputBar = new HBox(nameInput, set);
        inputBar.setAlignment(Pos.CENTER_RIGHT);
        inputBar.setPadding(new Insets(5, 10, 5, 10));
        ScrollPane memberScroll = new ScrollPane(member);
        VBox topBar = new VBox();
        topBar.getChildren().addAll(friendNameLabel, inputBar, memberScroll);

        root.setTop(topBar);

        this.messageLoader = new VBox();
        this.messageLoader.setFillWidth(true);
        ScrollPane messageScroll = new ScrollPane(messageLoader);
        messageScroll.setFitToWidth(true);
        root.setCenter(messageScroll);

        TextArea sendMessage = new TextArea();
        sendMessage.setPromptText("Enter message here");
        sendMessage.setMaxHeight(50);
        sendMessage.setWrapText(true);

        Button go = new Button(null, goImg);
        go.setOnAction(e -> {
            String message = sendMessage.getText();
            if (!message.equals("")) {
                setMessage(message, null, null);
                messageSender(message);
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
        stage.setTitle(Client.user_name + " In " + groupName);
        stage.show();
        stage.setMinHeight(400);
        stage.setMinWidth(200);
    }

    void setMessage(String message, String senderName, String extraMembers) {
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
            senderLabel.setPadding(new Insets(0, 10, 0, 5));
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

        if (extraMembers != null) {
            includeMembers(extraMembers);
        }

        if (!stage.isShowing()) {
            stage.show();
        } else {
            stage.toFront();
        }

    }

    void includeMembers(String members) {
        if (members != null || members.length() != 0) {
            StringTokenizer decoder = new StringTokenizer(members.substring(1), codeDivider);
            while (decoder.hasMoreTokens()) {
                String temp = decoder.nextToken();
                if (!temp.equals(userName)) {
                    friendNames.add(temp);
                    encodedSender = encodedSender.concat(codeDivider + temp);
                    member.getChildren().add(new Text(temp));
                }

            }
        }
    }

    public void messageSender(String message) {

        ClientSender send;

        send = new ClientSender(groupName + codeDivider + userName + newMembers);
        int n = friendNames.size();
        for (int i = 0; i < n; i++) {
            String friendName = friendNames.get(i);
            send.sendMessage(friendName + "$ " + message);
        }
        send = new ClientSender(groupName + codeDivider + userName + encodedSender + newMembers);
        n = xtraNames.size();
        for (int i = 0; i < n; i++) {
            String friendName = xtraNames.get(i);
            send.sendMessage(friendName + "$ " + message);
        }

        if (!newMembers.equals("")) {
            includeMembers(newMembers);
            newMembers = "";
        }
        xtraNames.clear();
    }

}
