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

int dp[1005][1005][4];
int ara1[1005], ara2[1005], a, b;
int pre1[1005], pre2[1005];
int org1[1005], org2[1005];
int n, p, k;

const int mx = 100002;
int bit[mx][3];
void update( int x, int val, int f ) //add val to index x
{
    while( x <= mx )
    {
        bit[x][f] += val;
        x += (x&(-x));
    }
}

int query( int x, int f ) //sum from 1 to x (inclusive)
{
    int sum = 0;
    while( x > 0 )
    {
        sum += bit[x][f];
        x -= (x&(-x));
    }
    return sum;
}

int sum( int a, int f )
{
    int b = a-k;
    if( b < 0 ) b = 0;
    return query(a, f) - query(b, f);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //filein;
    cin >> n >> p >> k;
    cin >> a;
    for( int i = 0 ;i < a; i++ )
    {
        cin >> ara1[i];
        org1[ara1[i]]++;
        update( ara1[i], 1, 1 );
    }
    cin >> b;
    for( int i = 0; i < b; i++ )
    {
        cin >> ara2[i];
        org2[ara2[i]]++;
        update( ara2[i], 1, 2 );
    }


    for( int i = 1; i <= n; i++ )
    {
        dp[i][1][1] = max( sum(i,1), dp[i-1][1][1] );
        dp[i][1][2] = max( sum(i,2), dp[i-1][1][2] );
    }
    int ans = -1;
    for( int i = 2; i <= p; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            dp[j][i][1] = max(dp[j-1][i][1], dp[j][i-1][1]) ;
            int s = sum(j,1);
            dp[j][i][1] = max( dp[j][i][1], (j-k >= 0? dp[j-k][i-1][1]: 0) + s );
            for( int x = j; x > j-k && x > 0; x-- )
            {
                if( org1[x] == 1 && org2[x] == 1 )
                {
                    update( x, -1, 2 );
                }
            }
            for( int x = j; x >= j-k && x >= 0; x-- )
            {
                int s1 = sum( x, 2 );
                int s2 = max( x-k >= 0? dp[x-k][i-2][1]: 0, x-k>=0? dp[x-k][i-2][2]:0 );
                dp[j][i][1] = max( dp[j][i][1], s1 + s2 + s );
            }
            for( int x = j; x > j-k && x > 0; x-- )
            {
                if( org1[x] == 1 && org2[x] == 1 )
                {
                    update( x, 1, 2 );
                }
            }
            ///*************
            dp[j][i][2] = max(dp[j-1][i][2], dp[j][i-1][2]);
            s = sum(j,2);
            dp[j][i][2] = max( dp[j][i][2], (j-k>=0?dp[j-k][i-1][2]:0) + s );
            for( int x = j; x > j-k && x > 0; x-- )
            {
                if( org1[x] == 1 && org2[x] == 1 )
                {
                    update( x, -1, 1 );
                }
            }
            for( int x = j; x >= j-k && x >= 0; x-- )
            {
                int s1 = sum( x, 1 );
                int s2 = max( x-k >= 0? dp[x-k][i-2][2]: 0, x-k>=0? dp[x-k][i-2][1]:0 );
                dp[j][i][2] = max( dp[j][i][2], s1 + s2 + s );
            }
            for( int x = j; x > j-k && x > 0; x-- )
            {
                if( org1[x] == 1 && org2[x] == 1 )
                {
                    update( x, 1, 1 );
                }
            }
            ans = max( dp[j][i][2], dp[j][i][1] );
            ///********
        }
    }

    cout << ans<< endl;

    return 0;
}




