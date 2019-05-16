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
const int M = 345678;

intl ara[4321][4321];
intl dp[802][4005], n, k;

intl sum( int x, int y )
{
    return (ara[y][y] - ( ara[x][y-1]+ara[x-1][y] - ara[x-1][y-1] ))/2;
}

void divide( int ind, int l, int r )
{
    if( l == r )
    {
        return;
    }
    int m = (l+r)/2;


}

void solve()
{
    for( int i =2; i <= k; i++ )
    {
        divide( i, 2, n);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    cin >> n >> k;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            cin >> ara[i][j];
        }
    }
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            ara[i][j] += ( ara[i][j-1] + ara[i-1][j] - ara[i-1][j-1] );
        }
    }

    for( int i = 1; i <= n; i++ ) dp[1][i] = sum(1,i);
    solve();

    return 0;
}
