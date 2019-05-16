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
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n, w, k, l = 0, m = 0;
        intl ans = 0;
        cin >> n >> w;
        intl ara[n];
        for( int i = 0; i < n; i++ ) cin >> ara[i];
        k = n/2;
        vector<intl>v1, v2;
        v1.pb(0);
        l++;
        for( int i = 0; i < k; i++ )
        {
            int tt = l;
            for( int j = 0; j < tt; j++ )
            {
                v1.pb( ara[i] + v1[j] );
                l++;
            }
        }
        v2.pb(0);
        m++;
        for( int i = k; i < n; i++ )
        {
            int tt = m;
            for( int j = 0; j < tt; j++ )
            {
                v2.pb( ara[i] + v2[j] );
                m++;
           }
        }
        sort( v2.begin(), v2.end() );
        for( int i = 0; i < l; i++ )
        {
            intl tt = w - v1[i] + 1;
            vector<intl>::iterator x = lower_bound( v2.begin(), v2.end(), tt );
            int y = x - v2.begin();
            ans += (intl)y;
        }
        cout << "Case " << caseno++ << ": " << ans << "\n";
    }

    return 0;
}



