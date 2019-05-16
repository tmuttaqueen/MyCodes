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

const int mx = 2000005;
int ara[1005];
vector<int>ans;
vector<bool>sieve(mx, 1);

void siieve()
{
    sieve[2] = 1;
    for( int i = 4; i < mx; i+=2 )
        sieve[i] = 0;
    for( int i = 3; i < mx; i+=2 )
    {
        if( sieve[i] == 1 )
        {
            for( int j = i + i; j < mx; j+=i )
                sieve[j] = 0;
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    siieve();
    //filein;
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i];
    }
    int a=0, b=0;
    for( int i = 0; i < n; i++ )
    {
        if( ara[i] == 1 ) a++;
        if( ara[i] == 2 ) b++;
    }
    if( a >= 2 )
    {
        while( a )
        {
            a--;
            ans.pb(1);
        }

        for( int i = 0; i < n; i++ )
        {
            if( sieve[ ara[i] + 1 ] == 1 && ara[i] != 1 )
            {
                ans.pb( ara[i] );
                break;
            }

        }
    }
    else if( a == 1 && b == 1 )
    {
        ans.pb(1);
        ans.pb(2);
    }
    else
    {
        int k = 0;
        for( int i = 0; i < n; i++ )
        {
            for( int j = i+1; j < n; j++ )
            {
                if( sieve[ ara[i] + ara[j] ] )
                {
                    ans.pb(ara[i]);
                    ans.pb( ara[j] );
                    k++;
                    break;
                }
            }
            if(k) break;
        }
        if( k == 0 )
        {
            for( int i = 0; i < n; i++ )
            {
                ans.pb( ara[i] );
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for( int i = 0; i < ans.size(); i++ )
    {
        cout << ans[i] << ' ';

    }
    cout << endl;
    return 0;
}



