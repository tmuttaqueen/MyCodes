/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package messenger;

import java.net.UnknownHostException;
import java.util.HashMap;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.application.Application;
import static javafx.application.Application.launch;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;

/**
 *
 * @author Tanveer Muttaqueen
 */
class RunForestRun implements Runnable
{

    Thread t;
    ClientMain cr;
    Client client;

    RunForestRun(ClientMain c, Client client)
    {
        this.client = client;
        cr = c;
        t = new Thread(this);
        t.start();
    }

    public void run()
    {
        while (true)
        {
            if (client.getReceiveFlag())
            {
                String msg = client.getReceive();
                String from = msg.substring(0, msg.indexOf("$"));
                String data = msg.substring(msg.indexOf("$") + 1).trim();
                if (cr.hm.containsKey(from))
                {
                    //Platform.runLater((cr.hm.get(from).setUser(data)));
                    cr.hm.get(from).setUser(data);
                    //System.out.println(from + " to " + data);
                }
                client.negetReceive();
            }
        }
    }
}

public class ClientMain extends Application
{

    Stage window;
    Client ownClient;
    Scene scene1;

    HashMap<String, ClientGui> hm = new HashMap<String, ClientGui>();

    public static void main(String[] args)
    {
        launch(args);
    }

    public void start(Stage primaryStage) throws Exception
    {
        window = primaryStage;
        window.setTitle("My Account");
        ClientMain cm = this;
        GridPane layout1 = new GridPane();
        GridPane layout2 = new GridPane();
        GridPane layout3 = new GridPane();
        GridPane mainlayout = new GridPane();

        layout1.setAlignment(Pos.CENTER);
        layout1.setHgap(10);
        layout1.setVgap(10);
        layout1.setPadding(new Insets(25, 25, 25, 25));

        layout2.setAlignment(Pos.CENTER);
        layout2.setHgap(10);
        layout2.setVgap(10);
        layout2.setPadding(new Insets(25, 25, 25, 25));

        mainlayout.setAlignment(Pos.CENTER);
        mainlayout.setHgap(10);
        mainlayout.setVgap(10);
        mainlayout.setPadding(new Insets(25, 25, 25, 25));

        Text welcome = new Text("Welcome!");
        welcome.setFont(Font.font("Times New Roman", FontWeight.NORMAL, 20));
        layout3.add(welcome, 0, 0, 2, 1);

        Label userName = new Label("User Name:");
        Label serverName = new Label("Server Name:");
        Label userPort = new Label("User Port:");
        Label serverIp = new Label("Server IP:");

        layout1.add(userName, 0, 1);
        layout1.add(serverName, 0, 2);
        layout1.add(userPort, 0, 3);
        layout1.add(serverIp, 0, 4);

        TextField userNameField = new TextField();
        TextField serverNameField = new TextField();
        TextField userPortField = new TextField();
        TextField serverIpField = new TextField();

        layout1.add(userNameField, 1, 1);
        layout1.add(serverNameField, 1, 2);
        layout1.add(userPortField, 1, 3);
        layout1.add(serverIpField, 1, 4);

        Label newChat = new Label("New Chat:");
        TextField newChatField = new TextField();
        Button startChat = new Button("Start Chat");

        layout2.add(newChat, 2, 1);
        layout2.add(newChatField, 2, 2);
        layout2.add(startChat, 2, 3);

        mainlayout.add(layout1, 0, 1);
        mainlayout.add(layout2, 1, 1);

        Button login = new Button("Log In");
        layout1.add(login, 1, 6);

        login.setOnAction(new EventHandler<ActionEvent>()
        {
            @Override
            public void handle(ActionEvent event)
            {

                if (userNameField.getText() == null || userNameField.getText().trim().isEmpty()
                        || serverNameField.getText() == null || serverNameField.getText().trim().isEmpty()
                        || userPortField.getText() == null || userPortField.getText().trim().isEmpty()
                        || serverIpField.getText() == null || serverIpField.getText().trim().isEmpty())
                {
                    Text action10 = new Text();
                    action10.setFill(Color.BLUE);
                    action10.setText("Login Unsuccessful");
                    layout1.add(action10, 0, 7);
                    Text action20 = new Text();
                    action20.setFill(Color.BLUE);
                    action20.setText("Try again");
                    layout1.add(action20, 0, 8);
                    userNameField.clear();
                    serverNameField.clear();
                    userPortField.clear();
                    serverIpField.clear();
                } else
                {
                    layout1.getChildren().clear();
                    layout3.setVgap(20);
                    layout3.add(new Label("User Name :  " + userNameField.getText()), 0, 2);
                    layout3.add(new Label("Server Name :  " + serverNameField.getText()), 0, 3);
                    layout3.add(new Label("User Port :  " + userPortField.getText()), 0, 4);
                    layout3.add(new Label("Server IP :  " + serverIpField.getText()), 0, 5);
                    mainlayout.add(layout3, 0, 1);
                    window.setTitle(userNameField.getText());
                    try
                    {
                        //here send the data to client program
                        ownClient = new Client(userNameField.getText().trim(), userPortField.getText().trim(),
                                serverIpField.getText().trim(), serverNameField.getText().trim()
                        );
                        new RunForestRun(cm, ownClient);
                    } catch (UnknownHostException ex)
                    {
                        Logger.getLogger(ClientMain.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
            }

        });
        
        newChatField.setOnKeyPressed(new EventHandler<KeyEvent>()
        {
            @Override
            public void handle(KeyEvent keyEvent)
            {
                if (keyEvent.getCode() == KeyCode.ENTER)
                {
                    if (newChatField.getText() == null || newChatField.getText().trim().isEmpty())
                    {
                        newChatField.clear();
                    } else
                    {
                        String newuser = newChatField.getText().trim();
                        //newuser = "chat_box_" + newuser;
                        hm.put(newuser, new ClientGui(newuser, ownClient));
                        newChatField.clear();
                    }

                }
            }
        });
        
        startChat.setOnAction(new EventHandler<ActionEvent>()
        {
            @Override
            public void handle(ActionEvent event)
            {

                if (newChatField.getText() == null || newChatField.getText().trim().isEmpty())
                {
                    newChatField.clear();
                } else
                {
                    String newuser = newChatField.getText().trim();
                    //newuser = "chat_box_" + newuser;
                    hm.put(newuser, new ClientGui(newuser, ownClient));
                    newChatField.clear();
                }
            }

        });

        scene1 = new Scene(mainlayout, 800, 500);
        window.setScene(scene1);

        scene1.getStylesheets().add(ClientMain.class.getResource("myjava.css").toExternalForm());
        window.show();
        //new ClientGui("fasf");

    }
}
