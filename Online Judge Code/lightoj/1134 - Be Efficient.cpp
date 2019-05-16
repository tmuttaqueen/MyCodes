#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

int dp[100005];
int sum[100005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1, a;
    scanf("%d", &t);
    while(t--)
    {
        memset( dp, 0, sizeof dp );
        int n, m;
        scanf("%d %d", &n, &m);
        sum[0] = 0;
        for( int i = 1; i <= n; i++ )
        {
            scanf("%d", &a);
            sum[i] = (sum[i-1]+a)%m;
        }
        intl ans = 0;
        for( int i = 1;i <=n; i++ )
        {
            if( sum[i] == 0 ) ans++;
            ans += dp[ sum[i] ];
            dp[sum[i]]++;
        }
        printf("Case %d: %lld\n", caseno++, ans);
    }
    return 0;
}




