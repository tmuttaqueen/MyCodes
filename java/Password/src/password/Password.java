/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package password;

import java.io.File;
import java.util.Scanner;

/**
 *
 * @author Tanveer Muttaqueen
 */
public class Password 
{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        // TODO code application logic here
        //File directory = new File("./");
        //System.out.println(directory.getAbsolutePath());
        Login login = new Login();
        boolean couldLogin = login.loginNow();
        if( couldLogin == false ) return;
        ManageData data = new ManageData();
        Scanner jin = new Scanner( System.in );
        while( true )
        {
            System.out.println("1. Insert");
            System.out.println("2. Update Password");
            System.out.println("3. Update Username");
            System.out.println("4. All Accounts Under This Email");
            System.out.println("5. All Accounts In This Website");
            System.out.println("6. Show All Data");
            System.out.println("11. Exit");
            int query;
            query = jin.nextInt();
            jin.nextLine();
            if( query == 1 )
            {
                data.insert();
            }
            else if( query == 2 )
            {
                data.updatePassword();
            }
            else if( query == 3 )
            {
                data.updateUserName();
            }
            else if( query == 4 )
            {
                String mail;
                System.out.print("Enter Email: ");
                mail = jin.nextLine();
                System.out.println("------");
                data.accountsUnderThisMail(mail);
            }
            else if( query == 5 )
            {
                String website;
                System.out.print("Enter Website: ");
                website = jin.nextLine();
                System.out.println("------");
                
                data.accountInformationGivenWebsite(website);
            }
            else if( query == 6 )
            {
                System.out.println("------");
                data.showAllData();
            }
            else if( query == 11 )
            {
                
                break;
            }
        }
        data.close();
        return;
    }
    
}
