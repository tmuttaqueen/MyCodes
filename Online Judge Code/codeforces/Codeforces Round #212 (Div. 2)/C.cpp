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

int dp[5005][5005];
int ara[5005];
int ans[500005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, inv = 0;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i];
    }

    for( int i = 0; i < n; i++ )
    {
        int x = 0;
        for( int j = 0; j < n; j++ )
        {
            if( ara[j] > ara[i] ) x++;
            dp[i][j] = x;
        }
        inv += dp[i][i-1];
    }
    //what_is(inv);
    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < i; j++ )
        {
            int bi, si, sj, bj, x;
            if( j == 0 )
            {
                bi = dp[i][i-1];
                bj = dp[j][i-1];
            }
            else
            {
                bi = dp[i][i-1] - dp[i][j-1];
                bj = dp[j][i-1] - dp[j][j-1];
            }
            si = i - j - bi;
            sj = i - j - 1 - bj;
            x = bi - si + sj - bj;
            //what_is(j);
            //what_is(i);
            //what_is(x);
            if( x >= 0 )
                ans[x]++;
        }
    }
    for( int i = 500004; i >= 0; i-- )
    {
        if( ans[i])
        {
            cout << inv - i << " " << ans[i] << endl;
            return 0;
        }
    }
    cout << inv << " " << 0 << endl;
    return 0;
}




