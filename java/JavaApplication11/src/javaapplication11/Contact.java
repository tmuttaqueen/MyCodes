package javaapplication11;

import java.net.InetAddress;

public class Contact {

    InetAddress address;
    int port;

    public Contact(InetAddress address, int port) {
        this.address = address;
        this.port = port;
    }

}
