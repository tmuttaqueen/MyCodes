/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package password;

import java.util.Scanner;

/**
 *
 * @author Tanveer Muttaqueen
 */
public class Login
{
    private final String userName = "tmuttaqueen";
    private final String password = "21081996";
    
    public boolean canLogin( String user, String pass  )
    {
        return userName.equals(user) && password.equals(pass);
    }
    
    public boolean loginNow()
    {
        String user, pass;
        Scanner jin = new Scanner( System.in );
        boolean loggedin = false;
        int c = 0;
        while( !loggedin )
        {
            System.out.print("username: ");
            user = jin.nextLine();
            System.out.print("password: ");
            pass = jin.nextLine();
            loggedin = canLogin(user, pass);
            c++;
            if( loggedin == true ) return true;
            if( c > 3 ) break;
        }
        return false;
    }
}
