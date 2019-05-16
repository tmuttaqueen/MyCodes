package javaapplication11;

import java.io.IOException;
import java.net.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.application.Platform;

public class ClientReceiverThread extends Client implements Runnable {

    DatagramPacket packet;
    DatagramSocket socket;
    int data_length;

    String sender;
    String message;

    ClientReceiverThread() {
        data_length = 1000;

        new Thread(this).start();
    }

    @Override
    public void run() {
        try {
            socket = new DatagramSocket(listening_port);
        } catch (SocketException ex) {
            Logger.getLogger(ClientReceiverThread.class.getName()).log(Level.SEVERE, null, ex);
        }
        while (true) {
            receive();
            if (process()) {
                printToUI();
            }
            if (message.equals(user_name + server_port)) {
                break;
            }
        }
    }

    private void receive() {
        byte[] data = new byte[data_length];
        packet = new DatagramPacket(data, data.length);
        try {
            socket.receive(packet);
        } catch (IOException ex) {
            Logger.getLogger(ClientReceiverThread.class.getName()).log(Level.SEVERE, null, ex);
        }
        message = new String(packet.getData());
    }

    private boolean process() {
        String[] lines = message.split("\n");
        String temp;
        if (lines.length < 4) {
            //drop();
            return false;
        }
        temp = linesTest(lines[0], "Via");
        if (temp == null || !temp.equals(server_name)) {
            //drop();
            return false;
        }
        temp = linesTest(lines[1], "To");
        if (temp == null || !temp.equals(user_name)) {
            //drop();
            return false;
        }
        sender = linesTest(lines[2], "From");
        if (sender == null) {
            //drop();
            return false;
        }
        message = linesTest(lines[3], "Body");
        if (message == null) {
            //drop();
            return false;
        }
        for (int i = 4; i < lines.length; i++) {
            message = message.concat("\n" + lines[i]);
        }
        return true;//print();
    }

    private String linesTest(String line, String test) {
        int cut = line.indexOf(":");
        if (cut != test.length() && line.startsWith(test)) {
            return null;
        } else {
            return (line.substring(cut + 2)).trim();
        }
    }

    private void print() {
        if (sender != null && message != null) {
            System.out.println(sender + " says: " + message.trim());
        }
    }

    private void printToUI() {
        Platform.runLater(() -> {
            int cut = sender.indexOf("|");
            System.out.println(sender);
            if (cut == -1) {
                ChatPairWindow chat = ongoingChats.get(sender);
                if (chat == null) {
                    startNewChat(sender, message);
                } else {
                    chat.setMessage(message, sender);
                }
            } else {
                String groupName = sender.substring(0, cut);
                ChatGroupWindow chat = ongoingGroupChats.get(groupName);
                int cut2 = sender.indexOf('|', cut + 1);
                if (chat == null) {
                    startNewGroupChat(groupName, message, sender.substring(cut + 1, cut2), sender.substring(cut + 1));
                } else if (cut2<0) {
                    chat.setMessage(message, sender.substring(cut + 1), null);
                } else {
                    chat.setMessage(message, sender.substring(cut + 1, cut2), sender.substring(cut2));
                }
            }
        });
    }

}
