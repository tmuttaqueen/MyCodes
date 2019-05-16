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
    int t;
    cin >> t;
    while( t-- )
    {
        int n;
        string s;
        cin >> n;
        cin >> s;
        int r, g, b;
        r = g = b = 0;
        for( int i = 0; i < s.size(); i++ )
        {
            if( s[i] == 'R' ) r++;
            if( s[i] == 'G' ) g++;
            if( s[i] == 'B' ) b++;
        }
        int l = max( r, max(g, b) );
        cout << n - l << endl;
    }

    return 0;
}



