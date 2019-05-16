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
const int M = 345678;

int ara[511], dp[7][7];
int ans[7];

int check()
{
    for( int i = 1; i <= 6; i++ )
    {
        if( ans[ ans[i] ] != i )
            return 0;
        if( dp[i][ ans[i] ] )
            return 0;
        if( ans[i] == i )
            return 0;
    }
    /*int temp[7][7];
    for( int i = 1; i <= 6; i++ )
    {
        for( int j = 1; j <= 6; j++ )
        {
            temp[i][j] = dp[i][j];
        }
    }
    for( int i = 1; i <= 6; i++ )
    {
        for( int j = 1; j <= 6; j++ )
        {
            if( j == i || j == ans[i] )
                continue;


        }
    }*/
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        memset( dp, 0, sizeof dp );
        for( int i = 0; i < n; i++ )
        {
            cin >> ara[i];
        }
        for( int i = 0; i < n; i++ )
        {
            int l = i-1, r = i+1;
            if( l >= 0 )
            {
                dp[ ara[i] ][ ara[l] ] = 1;
            }
            if( r < n )
            {
                dp[ ara[i] ][ ara[r] ] = 1;
            }
        }
        /*for( int i =1;i <= 6; i++ )
        {
            for( int j =1; j <= 6; j++ )
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }*/
        int f = 1;
        for( int i = 1; i <= 6; i++  )
        {
             ans[i] = i;
            if( dp[i][i] == 1 )
                f = 0;
        }
        if( f == 0 )
        {
            cout << -1 << endl;
            continue;
        }
        f = 0;
        //debug;
        for( int i = 0; i < 720; i++ )
        {
            f = check();
            if(f)
                break;
            next_permutation( ans+1, ans+7 );
        }
        if(f)
        {
            for( int i = 1; i <= 6; i++ )
                cout << ans[i] << " ";
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}
