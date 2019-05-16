package main;

import java.net.DatagramPacket;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;


public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        String s;
        //s = sc.nextLine();
        byte[] r = new byte[1024];
        r = "hellloo".getBytes();
        r = "hi".getBytes();
        
        //System.out.println(r[7]);
        String g = new String(r);
        
        System.out.println(g);
    }

}
