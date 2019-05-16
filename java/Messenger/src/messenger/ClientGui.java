/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package messenger;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.TextArea;
import javafx.scene.control.cell.TextFieldListCell;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

/**
 *
 * @author Tanveer Muttaqueen
 */
public class ClientGui //extends Application
{

    Stage window;
    ListView chatPane;
    VBox chatBox;
    TextArea ownChatArea;
    Button send;
    String username;
    Client client;

    public ClientGui(String s, Client client)
    {
        this.client = client;
        username = s;
        start();
    }


    /*public static void main(String[] args)
    {
        launch(args);
    }*/
    public void setOwn(String s)
    {
        VBox hb = new VBox();
        hb.setAlignment(Pos.TOP_RIGHT);
        Label lb = new Label(s);
        lb.setAlignment(Pos.TOP_RIGHT);
        if (s.length() > 60)
        {
            lb.setMaxWidth(500);
        }
        lb.setWrapText(true);
        lb.setStyle("-fx-background-color:  #ff7575 ; -fx-padding: 3px; -fx-font-size: 14px; -fx-background-radius: 3 15 0 15;  -fx-padding: 5 10 5 10 ;");

        hb.getChildren().add(lb);
        chatPane.getItems().add(hb);
        client.setSend(username + "$ " + s);
        client.negetSend();
    }

    public void setUser(String s)
    {
        VBox hb = new VBox();
        hb.setAlignment(Pos.TOP_LEFT);
        Label lb = new Label(s);
        lb.setWrapText(true);
        if (s.length() > 60)
        {
            lb.setMaxWidth(500);
        }
        lb.setStyle("-fx-background-color:  #66ee90 ; -fx-padding: 3px; -fx-font-size: 14px; -fx-background-radius: 3 15 0 15;  -fx-padding: 5 10 5 10 ;");
        hb.getChildren().add(lb);
        chatPane.getItems().add(hb);
    }

    public void start()
    {

        window = new Stage();
        window.setTitle( "chat_box_for_" + username);
        VBox container = new VBox();
        container.setSpacing(6);
        container.setPadding(new Insets(35, 35, 35, 35));
        HBox hb = new HBox();
        send = new Button("Send");
        chatPane = new ListView();
        ownChatArea = new TextArea();
        ownChatArea.setWrapText(true);
        //hb.getChildren().add();
        //hb.getChildren().add(send);
        
        container.getChildren().add(chatPane);
        container.getChildren().add(ownChatArea);
        send.setAlignment(Pos.CENTER_RIGHT);
        container.setAlignment(Pos.CENTER_RIGHT);
        container.getChildren().add(send);
        ownChatArea.setOnKeyPressed(new EventHandler<KeyEvent>()
        {
            @Override
            public void handle(KeyEvent keyEvent)
            {
                if (keyEvent.getCode() == KeyCode.ENTER)
                {

                    if (ownChatArea.getText().charAt(0) == '\n')
                    {
                        setOwn(ownChatArea.getText().substring(1));
                    } else
                    {
                        setOwn(ownChatArea.getText());
                    }
                    ownChatArea.clear();
                    //ownChatArea.setText("");
                }
            }
        });
        send.setOnAction((event) ->
        {
            if (ownChatArea.getText().charAt(0) == '\n')
            {
                setOwn(ownChatArea.getText().substring(1));
            } else
            {
                setOwn(ownChatArea.getText());
            }
            ownChatArea.clear();
            //setOwn(ownChatArea.getText());
            //ownChatArea.clear();
            //ownChatArea.setText("");
            //send.setText("");
        });

        Scene sc = new Scene(container, 700, 600);
        sc.getStylesheets().add(ClientGui.class.getResource("clientStyle.css").toExternalForm());
        window.setScene(sc);
        window.show();
    }

}
