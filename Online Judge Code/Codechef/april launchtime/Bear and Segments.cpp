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
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

intl ara[222222], dp[222222];
set<pair<intl, intl>>ss;
map<intl, intl>mm;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t;
    cin >> t;
    while(t--)
    {
        dp[0] = 0;
        intl n, p, ans = 0;
        cin >> n >> p;
        for( int i = 1; i <= n; i++ ) cin >> ara[i];
        for( int i = 1; i <= n; i++ ) dp[i] = (dp[i-1] + ara[i])%p;
        ss.insert( mp(0LL, 0LL) );
        //ss.insert( mp(dp[1],1LL) );
        for( intl i = 1; i <= n; i++ )
        {
            ss.insert( mp( dp[i], i ) );
            auto it = ss.find( mp( dp[i], i ) );
            pair<intl, intl>pp;
            it++;
            if( it != ss.end() )
            {
                pp= *it;
                ans = max( ans, dp[i] - pp.xx + p );
            }
            it = ss.begin();
            pp= *it;
            ans = max( ans, dp[i] - pp.xx );
        }
        mm[0] = 1;
        intl ans2 = 0;
        for( intl i = 1; i <= n; i++ )
        {
            int a = dp[i] - ans, b = dp[i]+p-ans;
            mm[dp[i]]++;
            ans2 += mm[a];
            ans2 += mm[b];
        }
        cout<< ans << " " << ans2 << endl;
        mm.clear();
        ss.clear();
    }
    return 0;
}




