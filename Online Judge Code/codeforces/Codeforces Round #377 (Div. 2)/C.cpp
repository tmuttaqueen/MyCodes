#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl b,l, s;
    cin >> b >>l >> s;
    if( b >= l && b >= s )
    {
        intl ans = 0;
        if( b > l && b > s )
            ans += (b-l-1) + (b-s-1);
        else if( b > l && b == s )
            ans += (b-l-1);
        else if( b == l && b > s )
            ans += (b-s-1);
        cout << ans << endl;

    }
    else if( l >= b && l >= s )
    {
        intl ans = 0;
        if( l > b && l > s )
        {
            ans += ( l -b -1) + (l-s-1);
        }
        else if( l > b && l == s )
        {
            ans += ( l -b -1);
        }
        else if( l == b && l > s )
        {
            ans += (l-s-1);
        }
        cout << ans << endl;
    }
    else if( s >= l && s >= b )
    {
        intl ans = 0;
        if( s > l && s > b )
        {
            ans += ( s -b -1) + (s-l-1);
        }
        else if( s == l && s > b )
        {
            ans += ( s -b -1);
        }
        else if( s == b && s > l )
        {
            ans += (s-l-1);
        }
        cout << ans << endl;
    }

    return 0;
}



