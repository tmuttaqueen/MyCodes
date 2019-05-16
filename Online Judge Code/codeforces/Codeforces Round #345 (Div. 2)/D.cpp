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
    int n, a, b, t, r = 1, f = 1, x = 0, y = 0, ans = 0, tt, temp1, temp2;
    cin >> n >> a >> b >> t;
    ans = 0;
    string s;
    cin >> s;
    int ara1[n], ara2[n];
    tt = t;
    if( s[0] == 'h' )
    {
        ara1[0] = ara2[0] = 1;
        //t += 1;
    }
    else
    {
        ara1[0] = ara2[0] = b + 1;
        //t += 1 + b;
    }
    if( ara1[0] <= tt )
    {
        x = y = 1;
    }
    for( int i = 1; i < n; i++ )
    {
        if( s[i] == 'h' )
        {
            ara1[i] = ara1[i-1] + a + 1;
        }
        else
        {
            ara1[i] = ara1[i-1] + a + b + 1;
        }
        if( ara1[i] <= tt )
        {
            x++;
        }
        if( s[n-i] == 'h' )
        {
            ara2[i] = ara2[i-1] + a + 1;
        }
        else
        {
            ara2[i] = ara2[i-1] + a + b + 1;
        }
        if( ara2[i] <= tt )
        {
            y++;
        }
    }
    /*for( int i = 0; i < n; i++ )
    {
        cout << ara1[i] << " ";
    }
    cout << endl;
    for( int i = 0; i < n; i++ )
    {
        cout << ara2[i] << " ";
    }
    cout << endl;*/
    ans = max(x, y);
    //what_is(ans);
    temp1 = temp2 = 0;
    if( ans != n )
    for( int i = 1; i < n; i++ )
    {
        x = y = 0;
        int t1 = t - ara1[i];
        int t2 = t - ara2[i];
        if( t1 >= 0 )
        {
            t1 = t1-i*a+ara1[0];
            //what_is(t1);
            x = upper_bound(ara2,ara2 + n, t1) - ara2 + i;

        }
        if( t2 >= 0 )
        {
            t2 = t2-i*a+ara1[0];
            //what_is(t2);
            y = upper_bound( ara1, ara1 + n, t2) - ara1 + i;
            //cout << *(upper_bound( ara1, ara1 + n, t2)) << endl;
        }

        //what_is(x);
        //what_is(y);
        ans = max(ans, x);
        ans = max(ans, y);
        //debug;
    }

    cout << ans << endl;

    return 0;
}
