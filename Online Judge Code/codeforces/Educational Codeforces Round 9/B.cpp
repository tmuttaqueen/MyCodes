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
    long long ans = 0;
    int n;
    cin >> n;
    int ara[n];
    string s;
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i];
    }
    //getchar();
    cin >> s;
    //debug;
    int l = s.size();
    for( int i = 0; i < l; i++ )
    {
        if( s[i] == 'B' )
        {
            ans += ara[i];
        }
    }
    long long temp = ans, tt = ans;
    for( int i = 0; i < l; i++ )
    {
        if( s[i] == 'A' )
            tt += ara[i];
        else
            tt -= ara[i];
        temp = max( tt, temp );
        //what_is(temp);
    }
    long long ans1 = max( ans, temp );
    temp = ans;
    tt = ans;
    for( int i = l -1 ; i >= 0; i-- )
    {
        if( s[i] == 'A' )
            tt += ara[i];
        else
            tt -= ara[i];
        temp = max( tt, temp );
        //what_is(temp);
    }
    long long ans2 = max( ans, temp );
    ans = max( ans1, ans2 );
    cout << ans << endl;
    return 0;
}



