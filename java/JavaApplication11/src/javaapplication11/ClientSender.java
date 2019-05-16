package javaapplication11;

import java.io.IOException;
import java.net.*;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ClientSender extends Client {

    DatagramPacket packet;
    DatagramSocket socket;

    String message;
    String sendTo;
    String senderName;

    public ClientSender() {
        this.senderName = user_name;
        try {
            socket = new DatagramSocket();
        } catch (SocketException ex) {
            Logger.getLogger(ClientSender.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public ClientSender(String senderName) {
        this.senderName = senderName;
        
    }

    void sendMessageLoop() {
        setConnection();
        while (true) {
            scan();
            if (process()) {
                send();
            }
        }
    }

    void setConnection() {
        try {
            socket = new DatagramSocket();
        } catch (SocketException ex) {
            Logger.getLogger(ClientSender.class.getName()).log(Level.SEVERE, null, ex);
        }
        message = "Via: " + server_name + "\n";
        message = message.concat("To: " + server_name + "\n");
        message = message.concat("From: " + senderName + "\n");
        message = message.concat("Port: " + listening_port);
        socket.close();
        send();
    }

    void scan() {
        Scanner scan = new Scanner(System.in);
        message = scan.nextLine();
    }

    boolean process() {
        int cut = message.indexOf("$");
        if (cut == -1) {
            return false;
        }
        sendTo = message.substring(0, cut);
        String messageBody = message.substring(cut + 1);

        message = "Via: " + server_name + "\n";
        message = message.concat("To: " + sendTo + "\n");
        message = message.concat("From: " + senderName + "\n");
        message = message.concat("Body: " + messageBody);
        return true;
    }

    void send() {

        try {
            byte data[];
            InetAddress add = InetAddress.getByName(server_ip);
            data = message.getBytes();
            packet = new DatagramPacket(data, data.length);
            socket = new DatagramSocket();
            packet.setAddress(add);
            packet.setPort(server_port);
            packet.setData(data);
            socket.send(packet);
            socket.close();
            System.out.println(message);
        } catch (UnknownHostException ex) {
            Logger.getLogger(ClientSender.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(ClientSender.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    void setReceiver(String sendTo) {
        this.sendTo = sendTo;
    }

    void sendMessage(String message) {
        this.message = message;
        process();
        send();
    }

}
