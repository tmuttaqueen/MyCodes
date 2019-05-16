package javaapplication11;

import java.io.IOException;
import java.net.*;
import java.util.Hashtable;
import java.util.logging.Level;
import java.util.logging.Logger;

public class ServerThread extends Server implements Runnable {

    Hashtable<String, Contact> clientContacts = new Hashtable<>();

    DatagramPacket packet;
    DatagramSocket socket;
    int data_length;

    String server_name;
    private final int server_port;

    boolean isRunning;

    String message;

    ServerThread(String server_name, int serverPort) {
        this.server_name = server_name;
        this.server_port = serverPort;

        data_length = 1000;

        this.isRunning = true;

        new Thread(this).start();
    }

    @Override
    public void run() {
        try {
            socket = new DatagramSocket(server_port);
        } catch (SocketException ex) {
            Logger.getLogger(ServerThread.class.getName()).log(Level.SEVERE, null, ex);
        }
        while (isRunning) {
            recieve();
            if (!isRunning) {
                socket.close();
                break;
            }
            new ServerProcessingThread(clientContacts, server_name, packet.getAddress(), message);
        }
    }

    private void recieve() {
        byte[] data = new byte[data_length];
        packet = new DatagramPacket(data, data.length);
        try {
            socket.receive(packet);
        } catch (IOException ex) {
            Logger.getLogger(ServerThread.class.getName()).log(Level.SEVERE, null, ex);
        }
        message = new String(packet.getData());
    }

}
