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
#define piii        pair<pii, int>


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, a, b, p;
    cin >> n;
    for( int i = 1; i<= n; i++ )
    {
        cin >> p;
        if( p == 1 ) a = i;
        if( p == n ) b = i;
    }
    int ans = -1;
    ans = max( ans, abs(b-a) );
    ans = max( ans, abs(b-1) );
    ans = max( ans, abs(a-1) );
    ans = max( ans, abs(b-n) );
    ans = max( ans, abs(a-n) );
    cout << ans << endl;
    return 0;
}


