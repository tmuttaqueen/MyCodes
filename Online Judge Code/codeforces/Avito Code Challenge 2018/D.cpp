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
const int M = 55;

intl val[M*M], st[M*M], en[M*M];
bool dp[M*M][M];
intl sum[M];



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, k;
    cin >> n >> k;
    for( int i = 1; i <= n; i++ )
    {
        cin >> sum[i];
        sum[i] += sum[i-1];
    }
    int tot = 1;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = i; j <= n; j++ )
        {
            val[tot] = sum[j] - sum[i-1];
            st[tot] = i;
            en[tot++] = j;
        }
    }
    intl ans = 0;

    for( int i = 60; i >= 0; i-- )
    {
        intl w = ans|(1LL<<i);
        vector<int>vec;
        for( int j = 1; j < tot; j++ )
        {
            if( (val[j]&w) == w )
            {
                //cout << w << " " << j << " " << st[j] << " " << en[j] << " " << val[j] << endl;
                vec.pb(j);
            }
        }
        memset( dp, 0, sizeof dp );
        for( int j = 0; j < vec.size(); j++ )
        {
            if( st[ vec[j] ] == 1 ) dp[ vec[j] ][1] = 1;
            for( int l = j+1; l < vec.size(); l++ )
            {
                if( st[ vec[l] ] == en[ vec[j] ] + 1 )
                {
                    for( int p = 0; p <= k; p++ )
                    {
                        if( dp[ vec[j] ][p] == 1 )
                        {
                            dp[ vec[l] ][p+1] = 1;
                        }
                    }

                }
            }
        }
        for( int x: vec )
        {
            if( dp[x][k] && en[x] == n )
                ans = w;
        }

    }

    cout << ans << endl;

    return 0;
}
