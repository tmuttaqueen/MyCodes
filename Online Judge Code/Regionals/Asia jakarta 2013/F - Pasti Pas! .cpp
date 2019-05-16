#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 56780;

char s1[M], s2[M];

intl mod = 961748941, base = 41, ara[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno = 1;
    cin >> t;
    ara[0] = 1;
    for( int i = 1; i<M; i++ )
    {
        ara[i] = ara[i-1]*base%mod;
    }
    while(t--)
    {
        string s;
        cin >> s;

        int l = s.length();
        for( int i = 0; i < l; i++ )
        {
            s1[i] = s[i];
            s2[l-i-1] = s1[i];
        }
        s2[l] = '\0';
        intl h1 = 0, h2 = 0, prev = 0, ans = 0;
        for( int i = 0; i < l; i++)
        {
            int d1 = s1[i] - 'A' + 1, d2 = s2[i] - 'A' + 1;
            h1 = (h1 + d1*ara[i-prev])%mod;
            h2 = (h2*base + d2)%mod;
            if( h1 == h2 )
            {
                h1 = 0;
                h2 = 0;
                ans++;
                prev = i+1;
            }
        }
        cout << "Case #" << caseno++ << ": " << ans << endl;
    }
    return 0;
}
