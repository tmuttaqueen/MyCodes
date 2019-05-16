package javaapplication11;

import java.io.IOException;
import java.net.*;
import java.net.UnknownHostException;
import java.util.Hashtable;
import java.util.logging.Level;
import java.util.logging.Logger;
import javafx.application.Platform;

public class ServerProcessingThread extends Server implements Runnable {

    Hashtable<String, Contact> clientContacts = new Hashtable<>();

    DatagramPacket packet;
    DatagramSocket socket;

    String server_name;

    String message;
    InetAddress clientIp;

    ServerProcessingThread(Hashtable contacts, String name, InetAddress ip, String message) {
        this.clientContacts = contacts;
        this.server_name = name;
        this.clientIp = ip;
        this.message = message;

        new Thread(this).start();
    }

    @Override
    public void run() {
        process();
    }

    private void process() {
        try {
            if (message.equals(server_name)) {
                if (clientIp.equals(InetAddress.getLocalHost())) {
                    send(new Contact(clientIp, 8000));
                    return;
                }
            }
        } catch (UnknownHostException ex) {
            Logger.getLogger(ServerProcessingThread.class.getName()).log(Level.SEVERE, null, ex);
        }System.out.println(message);
        String[] lines = message.split("\n");
        String temp, from, port;
        if (lines.length < 4) {
            showWarning(0);
            return;
        }
        temp = linesTest(lines[0], "Via");
        if (temp == null || !temp.equals(server_name)) {
            showWarning(1);
            return;
        }
        temp = linesTest(lines[1], "To");
        if (temp == null) {
            showWarning(0);
        } else if (temp.equals(server_name)) {
            from = linesTest(lines[2], "From");
            port = linesTest(lines[3], "Port");
            if (from == null) {
                showWarning(0);
            } else if (port == null) {
                showWarning(0);
            } else {
                signUp(from, port);
            }
        } else {
            Contact sendTo = clientContacts.get(temp);
            if (sendTo != null) {
                send(sendTo);
                final String mesgInfo = "Sender: " + linesTest(lines[2], "From") + "\nReceiver: " + temp;
                Platform.runLater(() -> setReferMesgInfo(mesgInfo));
                //System.out.println(mesgInfo);
            } else {
                showWarning(2);
            }
        }

    }

    private String linesTest(String line, String test) {
        int cut = line.indexOf(":");
        if (cut != test.length() && line.startsWith(test)) {
            return null;
        } else {
            return (line.substring(cut + 2)).trim();
        }
    }

    private void signUp(String from, String port) {
        if (clientContacts.get(from) == null) {
            clientContacts.put(from, new Contact(clientIp, Integer.parseInt(port)));
        }
        Platform.runLater(() -> setSignInInfo("User Name: " + from + "\nIP Address: " + clientIp + "\nPort: " + port));
    }

    private void send(Contact sendTo) {
        try {
            byte data[];
            data = message.getBytes();
            packet = new DatagramPacket(data, data.length);
            packet.setAddress(sendTo.address);
            packet.setPort(sendTo.port);
            socket = new DatagramSocket();
            packet.setData(data);
            socket.send(packet);
            socket.close();
        } catch (UnknownHostException ex) {
            Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(Server.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private void showWarning(int warningNo) {
        String warningMesg;
        switch (warningNo) {
            case 0:
                warningMesg = "Field misssing.";
                break;
            case 1:
                warningMesg = "Server name mismatch.";
                break;
            case 2:
                warningMesg = "Unknown recipient.";
                break;
            default:
                warningMesg = "";
        }
        final String warningMesg2 = "Warning: " + warningMesg + " Message dropped.";
        //System.out.println(warningMesg);
        Platform.runLater(() -> setWarningInfo(warningMesg2));
    }
}
