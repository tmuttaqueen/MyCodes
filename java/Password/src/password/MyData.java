/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package password;

import java.io.Serializable;

/**
 *
 * @author Tanveer Muttaqueen
 */
public class MyData implements Serializable
{
    private String username;
    private String password;
    private String website;
    private String email;
    private String details;
    private String accountType;
    
    public MyData( String website, String email, String username, String password, String details, String accountType )
    {
        this.website = website;
        this.email = email;
        this.username = username;
        this.password = password;
        this.details = details;
        this.accountType = accountType;
    }
    public void Print( int id )
    {
        System.out.println("Index in ArrayList: " + id );
        System.out.println("website    : " + this.website );
        System.out.println("email      : " + this.email );
        System.out.println("username   : " + this.username );
        System.out.println("password   : " + this.password );
        System.out.println("details    : " + this.details );
        System.out.println("accountType: " + this.accountType );
        System.out.println("------");
    }
    public void Print( )
    {
        System.out.println("website    : " + this.website );
        System.out.println("email      : " + this.email );
        System.out.println("username   : " + this.username );
        System.out.println("password   : " + this.password );
        System.out.println("details    : " + this.details );
        System.out.println("accountType: " + this.accountType );
        System.out.println("------");
    }
    public boolean doesContainEmail( String mail )
    {
        return this.email.toLowerCase().contains(mail.toLowerCase());
    }
    public boolean doesContainWebsite( String website )
    {
        return this.website.toLowerCase().contains(website.toLowerCase());
    }
    
}
