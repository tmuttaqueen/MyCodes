/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package myclient;

import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Tanveer Muttaqueen
 */
public class MyClient
{

    
    public static void main(String[] args)
    {
        try
        {
            Scanner cin = new Scanner(System.in);
            Socket mysocket = new Socket("localhost", 10000);
            DataOutputStream dos = new DataOutputStream(mysocket.getOutputStream());
            String s;
            s = cin.nextLine();
            dos.writeUTF(s);
            mysocket.close();
        } catch (IOException ex)
        {
            Logger.getLogger(MyClient.class.getName()).log(Level.SEVERE, null, ex);
        }
        
    }
    
}
