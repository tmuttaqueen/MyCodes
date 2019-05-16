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
    int n, k;
    int g, t;
    cin >> n >> k;
    string s;
    cin >> s;
    for( int i = 0; i < n; i++ )
    {
        if( s[i] == 'G' )
            g = i;
        if( s[i] == 'T' )
            t = i;
    }

    if( abs(t-g) % k != 0 )
    {
        cout << "NO\n";
        return 0;
    }

    if( t < g )
    {
        while( t < g )
        {
            t += k;
            if(s[t] == '#')
            {
                cout << "NO\n";
                return 0;
            }
        }
    }
    else
    {
        while( t > g )
        {
            t -= k;
            if(s[t] == '#')
            {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";

    return 0;
}




