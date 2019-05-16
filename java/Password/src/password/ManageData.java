/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package password;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Tanveer Muttaqueen
 */
public class ManageData implements Serializable
{
    ArrayList<MyData> accounts = new ArrayList<MyData>();
    private final String file = "./resources/mydata.txt";
    public ManageData()
    {
        try
        {
            FileInputStream fin = new FileInputStream(file);
            ObjectInputStream oin = new ObjectInputStream(fin);
            accounts = (ArrayList<MyData>) oin.readObject();
            oin.close();
            fin.close();
        } catch (FileNotFoundException ex)
        {
            System.out.println(ex);
            ex.printStackTrace();
        } catch (IOException ex)
        {
            System.out.println(ex);
            ex.printStackTrace();
        } catch (ClassNotFoundException ex)
        {
            System.out.println(ex);
            ex.printStackTrace();
        }
        
    }
    public void insert()
    {
        String website, email, username, password, details, at, accountType;
        Scanner jin = new Scanner( System.in );
        System.out.print("website: ");
        website = jin.nextLine();
        System.out.print("email: ");
        email = jin.nextLine();
        System.out.print("username: ");
        username = jin.nextLine();
        System.out.print("password: ");
        password = jin.nextLine();
        System.out.print("details: ");
        details = jin.nextLine();
        System.out.print("is this an Email Account(y/n): ");
        at = jin.nextLine();
        if( at.equals("y") )
            accountType = "email";
        else
            accountType = "user/consumer";
            
        MyData newData = new MyData( website, email, username, password, details, accountType );
        accounts.add(newData);
        return;
    }
    public void accountsUnderThisMail( String mail )
    {
        for( int i = 0; i < accounts.size(); i++ )
        {
            MyData data = accounts.get(i);
            if( data.doesContainEmail(mail) )
                data.Print(i);
        }
        return;
    }
    public void accountInformationGivenWebsite( String website )
    {
        for( int i = 0; i < accounts.size(); i++ )
        {
            MyData data = accounts.get(i);
            if( data.doesContainWebsite(website) )
                data.Print(i);
        }
    }
    public void close()
    {
        try
        {
            FileOutputStream fout = new FileOutputStream(file);
            ObjectOutputStream oout = new ObjectOutputStream(fout);
            oout.writeObject(accounts);
            oout.close();
            fout.close();
        } catch (FileNotFoundException ex)
        {
            System.out.println(ex);
            ex.printStackTrace();
        } catch (IOException ex)
        {
            System.out.println(ex);
            ex.printStackTrace();
        }
    }
    public void updateUserName()
    {
        
    }
    public void updatePassword()
    {
        
    }
    public void showAllData()
    {
        for( int i = 0; i < accounts.size(); i++ )
        {
            MyData data = accounts.get(i);
            data.Print(i);
        }
        return;
    }
    
}
