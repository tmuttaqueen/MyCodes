package javaapplication11;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;
import java.util.HashMap;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.application.Application;
import javafx.application.Platform;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ScrollPane;
import javafx.scene.control.TextField;
import javafx.scene.control.ToggleButton;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Priority;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.TilePane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class Client extends Application {

    static String user_name;
    static int listening_port;
    static String server_ip;
    static String server_name;
    static int server_port;

    static HashMap<String, ChatPairWindow> ongoingChats;
    static HashMap<String, ChatGroupWindow> ongoingGroupChats;

    static VBox chatPairsInfo;
    static VBox chatGroupsInfo;

    public static void main(String[] args) {
        if (args.length >= 4) {
            user_name = args[0];
            listening_port = Integer.parseInt(args[1]);
            server_ip = args[2];
            server_name = args[3];
            server_port = 8000;
            new ClientReceiverThread();
            ClientSender s = new ClientSender();
            s.sendMessageLoop();
        } else {
            launch(args);
        }
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        logIn();

        ongoingChats = new HashMap<>();
        ongoingGroupChats = new HashMap<>();

        new ClientReceiverThread();
        new ClientSender().setConnection();

        BorderPane root = new BorderPane();

        chatPairsInfo = new VBox();
        chatPairsInfo.setPadding(new Insets(5, 25, 5, 25));
        chatPairsInfo.setFillWidth(true);
        chatPairsInfo.setSpacing(5);
        chatPairsInfo.setMinHeight(20);

        chatGroupsInfo = new VBox();
        chatGroupsInfo.setPadding(new Insets(5, 25, 5, 25));
        chatGroupsInfo.setFillWidth(true);
        chatGroupsInfo.setSpacing(5);
        chatGroupsInfo.setMinHeight(20);

        ScrollPane pairsInfoScroll = new ScrollPane(chatPairsInfo);
        pairsInfoScroll.setFitToWidth(true);
        ScrollPane groupsInfoScroll = new ScrollPane(chatGroupsInfo);
        groupsInfoScroll.setFitToWidth(true);

        HBox chatsInfo = new HBox();
        chatsInfo.setFillHeight(true);
        chatsInfo.getChildren().addAll(pairsInfoScroll, groupsInfoScroll);
        HBox.setHgrow(pairsInfoScroll, Priority.SOMETIMES);
        HBox.setHgrow(groupsInfoScroll, Priority.SOMETIMES);
        root.setCenter(chatsInfo);

        Label userNameLabel = new Label("User Name: " + user_name);
        Label listeningPortLabel = new Label("Port: " + new Integer(listening_port).toString());
        Label serverIpLabel = new Label("Server IP: " + server_ip);
        Label serverNameLabel = new Label("Server Name: " + server_name);

        VBox userInfo = new VBox();
        userInfo.setPadding(new Insets(5, 10, 5, 10));
        userInfo.setSpacing(10);
        userInfo.getChildren().addAll(userNameLabel, listeningPortLabel, serverIpLabel, serverNameLabel);

        root.setLeft(userInfo);

        ToggleButton chatPair, chatGroup;
        chatPair = new ToggleButton("New Pairchat");
        chatGroup = new ToggleButton("New Groupchat");

        TextField nameInput = new TextField();

        Image img = new Image("sendButton.PNG");
        ImageView send = new ImageView(img);
        send.setFitHeight(10);
        send.setFitWidth(10);
        Button go = new Button(null, send);
        go.setDefaultButton(true);
        go.setOnAction(e -> {
            String groupName = nameInput.getText();
            if (!groupName.equals("")) {
                nameInput.clear();
                if (chatPair.isSelected()) {
                    ChatPairWindow temp = ongoingChats.get(groupName);
                    if (temp == null) {
                        startNewChat(groupName, null);
                    } else {
                        temp.stage.toFront();
                    }
                } else if (chatGroup.isSelected()) {
                    ChatGroupWindow temp = ongoingGroupChats.get(groupName);
                    if (temp == null) {
                        startNewGroupChat(groupName, null, null, null);
                    } else {
                        temp.stage.toFront();
                    }
                }
            }
        });

        HBox option = new HBox();
        option.setAlignment(Pos.CENTER);
        option.getChildren().addAll(chatPair, chatGroup);

        HBox connectBar = new HBox();
        connectBar.setPadding(new Insets(10, 10, 10, 10));
        connectBar.getChildren().addAll(nameInput, go);
        HBox.setHgrow(nameInput, Priority.ALWAYS);

        VBox topBar = new VBox();
        topBar.getChildren().add(option);

        root.setTop(topBar);

        chatPair.setOnAction(e -> {
            if (chatPair.isSelected()) {
                if (chatGroup.isSelected()) {
                    chatGroup.setSelected(false);
                } else {
                    topBar.getChildren().add(connectBar);
                }
                nameInput.setPromptText("Enter people's name");
                nameInput.requestFocus();
            } else {
                topBar.getChildren().removeAll(connectBar);
            }
        });
        chatGroup.setOnAction(e -> {
            if (chatGroup.isSelected()) {
                if (chatPair.isSelected()) {
                    chatPair.setSelected(false);
                } else {
                    topBar.getChildren().add(connectBar);
                }
                nameInput.setPromptText("Enter Group's name");
                nameInput.requestFocus();
            } else {
                topBar.getChildren().removeAll(connectBar);
            }
        });

        topBar.setStyle("-fx-background-color: #AED6F1;");
        chatPairsInfo.setStyle("-fx-background-color: #D0ECE7;");
        userInfo.setStyle("-fx-background-color: #E8DAEF;");

        Scene scene = new Scene(root, 600, 300);

        primaryStage.setScene(scene);
        primaryStage.setTitle(user_name);
        primaryStage.show();
        primaryStage.setMinHeight(300);
        primaryStage.setMinWidth(600);
    }

    @Override
    public void stop() {
        ongoingChats.forEach((k, v) -> {
            v.stage.close();
        });
        new ClientSender().sendMessage(user_name + "$" + user_name + server_port);
    }

    public void startNewChat(String friendName, String message) {
        ChatPairWindow chat = new ChatPairWindow(friendName);
        if (message != null) {
            chat.setMessage(message, friendName);
        }
        ongoingChats.put(friendName, chat);
        Button chatName = new Button(friendName);
        chatName.setPrefWidth(150);
        chatName.setOnAction(x -> {
            if (chat.stage.isShowing()) {
                chat.stage.toFront();
            } else {
                chat.stage.show();
            }
        });
        chatPairsInfo.getChildren().add(chatName);
    }

    public void startNewGroupChat(String groupName, String message, String senderName, String groupMembers) {
        ChatGroupWindow chat = new ChatGroupWindow(groupName, user_name, groupMembers);
        if (message != null) {
            chat.setMessage(message, senderName, null);
        }
        ongoingGroupChats.put(groupName, chat);
        Button chatName = new Button(groupName);
        chatName.setPrefWidth(150);
        chatName.setOnAction(x -> {
            if (chat.stage.isShowing()) {
                chat.stage.toFront();
            } else {
                chat.stage.show();
            }
        });
        chatGroupsInfo.getChildren().add(chatName);
    }

    void logIn() {
        Stage window = new Stage();
        GridPane signIn = new GridPane();
        signIn.setAlignment(Pos.CENTER);
        signIn.setVgap(5);
        signIn.setHgap(5);

        Image img = new Image("sendButton.PNG");
        ImageView send = new ImageView(img);
        send.setFitHeight(10);
        send.setFitWidth(10);

        Label userName = new Label("User Name:");
        signIn.add(userName, 0, 0);

        TextField nameInput = new TextField();
        nameInput.setPromptText("Enter user name");
        signIn.add(nameInput, 1, 0);

        Label userPort = new Label("User Port:");
        signIn.add(userPort, 0, 1);

        TextField portInput = new TextField();
        portInput.setPromptText("Enter user port");
        signIn.add(portInput, 1, 1);

        Label serverName = new Label("Server Name:");
        signIn.add(serverName, 0, 2);

        TextField servNameInput = new TextField();
        servNameInput.setPromptText("Enter server name");
        signIn.add(servNameInput, 1, 2);

        Label serverIp = new Label("Server Ip:");
        signIn.add(serverIp, 0, 3);

        TextField ipInput = new TextField();
        ipInput.setPromptText("Enter server ip");
        signIn.add(ipInput, 1, 3);

        Label serverPort = new Label("Server Port:");
        signIn.add(serverPort, 0, 4);

        TextField servPortInput = new TextField();
        servPortInput.setPromptText("Enter server port");
        signIn.add(servPortInput, 1, 4);

        VBox buttonSpace = new VBox();
        buttonSpace.setAlignment(Pos.CENTER_RIGHT);

        Button logIn = new Button("Log In", send);
        logIn.setDefaultButton(true);
        logIn.setOnAction(e -> {
            if (nameInput.getText().equals("")) {
                nameInput.requestFocus();
            } else if (portInput.getText().equals("")) {
                portInput.requestFocus();
            } else if (servNameInput.getText().equals("")) {
                servNameInput.requestFocus();
            } else if (ipInput.getText().equals("")) {
                ipInput.requestFocus();
            } else if (servPortInput.getText().equals("")) {
                servPortInput.requestFocus();
            } else {
                user_name = nameInput.getText().trim();
                listening_port = Integer.parseInt(portInput.getText().trim());
                server_ip = ipInput.getText().trim();
                server_name = servNameInput.getText().trim();
                server_port = Integer.parseInt(servPortInput.getText());
                window.close();
            }
        });

        buttonSpace.getChildren().add(logIn);
        signIn.add(buttonSpace, 1, 5);

        Scene scene = new Scene(signIn, 300, 300);
        window.setScene(scene);
        window.setTitle("Client: Log In");
        window.centerOnScreen();
        window.setResizable(false);
        window.showAndWait();
    }

}
