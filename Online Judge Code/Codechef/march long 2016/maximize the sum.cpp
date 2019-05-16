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
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        long long a[n], b[n];
        for( int i = 0; i < n; i++ ) cin >> a[i];
        for( int i = 0; i < n; i++ ) cin >> b[i];
        int mx = 0;
        for( int i = 0; i < n; i++ )
        {
            if( abs(b[i]) > abs(b[mx]) )
                mx = i;
        }
        if( b[mx] < 0 )
            a[mx] -= k;
        else
            a[mx] += k;
        long long ans = 0;
        for( int i = 0; i < n; i++ )
        {
            ans += a[i]*b[i];
        }
        cout << ans << endl;
    }

    return 0;
}



