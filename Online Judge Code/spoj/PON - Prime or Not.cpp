#include<bits/stdc++.h>

using namespace std;



///MULMOD O(logn)
//determone (a*b)%mod taking into account that a*b might overflow ( here b = 2^b1 + 2^b2 + 2^b3 +.... )

unsigned long long mulmod( unsigned long long a, unsigned long long b, unsigned long long mod )
{
    unsigned long long x = 0, y = a%mod;
    while( b > 0 )
    {
        if(b&1)
            x = (x+y)%mod;
        y = (y*2)%mod;
        b /= 2;
    }
    return x%mod;
}

unsigned long long exponentiation( unsigned long long a, unsigned long long b, unsigned long long mod )
{
    unsigned long long ans = 1;
    while( b > 0 )
    {
        if( b&1 )
            ans = mulmod( a, ans, mod );
        a = mulmod( a, a, mod );
        b /= 2;
    }
    return ans;
}

///MILLER-ROBIN O(k*logn)
//determine if a number is prime

int is_prime( unsigned long long n )
{
    if( n == 2 )
        return 1;
    if( n % 2 == 0 )
        return 0;
    unsigned long long d = n-1;
    while(d%2==0)
    {
        d/=2;
    }
    int test[] = {2,3,5,7,11,13,17,19,23,29};
    for( int i = 0; i < 10; i++ )
    {
        unsigned long long x = test[i]%(n-2), temp = d;
        if(x < 2) x += 2;
        unsigned long long a = exponentiation(x,d,n);
        while( temp != n-1 && a != 1 && a != n-1 )
        {
            a = mulmod(a,a,n);
            temp *= 2;
        }
        if( a != n-1 && temp%2==0 )
            return 0;
    }
    return 1;
}

int main()
{
    unsigned long long t, ans = 0 ;
    cin >> t;
    while(t--)
    {
        //if(t==1) break;
        unsigned long long n;
        cin >>  n;
        //cout << t << " ";
        if( is_prime(n) )
        {
            cout << "YES\n";
            //ans ++;
        }
        else
            cout << "NO\n";
        //t--;
    }
    //cout << ans << endl;
    return 0;
}
