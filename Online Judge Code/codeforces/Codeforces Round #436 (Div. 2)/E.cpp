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
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double
typedef struct touple
{
    int xx,yy,zz;
    touple( int x = 0, int y = 0, int z = 0 ){xx=x; yy=y; zz=z;}
    bool operator<(const touple &a )
    {
        if( xx == a.xx )
		{
            if( yy == a.yy )
                return zz < a.zz;
            return yy < a.yy;
        }
        return xx<a.xx;
    }

} tii;
//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

struct item
{
    int t, d, v, ind;
};

bool comp( item &a, item &b )
{
    if( a.d == b.d )
        return a.t < b.t;
    return a.d < b.d;
}

item ara[111];
int dp[4002][402];
int flag[4002][402];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    int mx = 0;
    for( int i  =1; i <= n; i++ )
    {
        cin >> ara[i].t >> ara[i].d >> ara[i].v;
        ara[i].ind = i;
        mx = max( mx, ara[i].d );
    }

    sort( ara+1, ara+n+1, comp );
    for( int i = 1; i <= n; i++ )
    {
        //cout << ara[i].t << " " << ara[i].d << " " << ara[i].v << endl;
    }
    for( int i = mx; i >= 0; i-- )
    {
        for( int j = n; j >= 1; j-- )
        {
            if( ara[j].d - i - ara[j].t <= 0 )
            {
                flag[i][j] = 0;
                dp[i][j] = dp[i][j+1];
                //continue;
            }
            else if( ara[j].v + dp[i+ ara[j].t ][j+1] > dp[i][j+1]  )
            {
                dp[i][j] = ara[j].v + dp[i+ ara[j].t ][j+1];
                flag[i][j] = 1;
            }
            else
            {
                flag[i][j] = 0;
                dp[i][j] = dp[i][j+1];
            }
            //cout << i << " " << j << " -- " << dp[i][j] << endl;
        }
    }
    int st = 0;
    int ans[111], c = 0;
    for( int i = 1; i <= n; i++ )
    {
        if( flag[st][i] )
        {
            ans[c++] = ara[i].ind;
            st += ara[i].t;
        }

    }
    cout << dp[0][1] << endl;
    cout << c << endl;
    for( int i = 0; i < c; i++ )
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
