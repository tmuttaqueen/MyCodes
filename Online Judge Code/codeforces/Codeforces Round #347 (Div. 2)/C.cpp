#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    string s;
    vector<int> vec;
    getline(cin,s);
    int k;
    for( int i = 0; i < s.size(); i++ )
    {
        if( s[i] == '=' )
        {
            k = i + 2;
        }
    }
    string d = s.substr( k, s.size() );
    int n = 0;
    k = 1;
    for( int i = d.size()-1; i >= 0; i-- )
    {
        n = n+k*(d[i]-'0');
        k*=10;
    }
    int p = 1, m = 0;
    for( int i = 0; i < s.size(); i++ )
    {
        if( s[i] == '+' ) p++;
        if( s[i] == '-' ) m++;
    }
    int nn = n+m;
    if( nn < p )
    {
        cout << "Impossible\n";
        return 0;
    }
    if( ceil((double)nn/p) > n )
    {
        cout << "Impossible\n";
        return 0;
    }
    if( nn == p )
    {
        for( int i = 0; i < p; i++ ) vec.pb(1);
    }
    else if( m <= n && (p-1) <= n )
    {
        int i = 1;
        if( m > 0 )
        {
            vec.pb(m);
            i++;
        }
        for( ; i < p; i++ )
        {
            vec.pb(1);
            n--;
        }
        vec.pb(n);
    }
    else if( m <= n && (p-1) > n )
    {
        while( m > 0 )
        {
            vec.pb(1);
            p--;
            m--;
        }
        while( p > 1 )
        {
            vec.pb(1);
            n--;
        }
        vec.pb(n);
    }
    else if( m > n )
    {
        int x = 0;
        while( m > n )
        {
            m-=n;
            x++;
        }
        for( int i = 0; i < x; i++ )
        {
            vec.pb(n);
            p--;
        }
        while( p > 2 )
        {
            vec.pb(1);
            p--;
            n--;
        }
        if( n > 0 )
            vec.pb( n );
        if( m > 0 )
            vec.pb(m);
    }
    k = 0;
    cout << "Possible\n";
    cout << vec[k++];
    for( int i = 1; i < s.size(); i++ )
    {
        if( s[i] == '?' && s[i-2] == '+' )
        {
            cout << vec[k++];
        }
        else if( s[i] == '?' && s[i-2] == '-' )
        {
            cout << 1;
        }
        else
        cout << s[i];
    }
    cout << endl;

    return 0;
}



