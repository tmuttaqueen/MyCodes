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
const int SZ = 1000005, mod = 1000000007;

int ara[111][111];
int nr[111];
int nc[111];
int temp[111][111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m, ff = 0;
    cin >> n >> m;

    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= m; j++ )
        {
            cin >> ara[i][j];
        }
    }
    if( n > m )
    {
        ff = 1;
        swap(n,m);
        for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= m; j++ )
            {
                temp[i][j] = ara[j][i];
            }
        }
        for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= m; j++ )
            {
                ara[i][j] = temp[i][j];
            }
        }
    }

    for( int i = 1; i <= n; i++ )
    {
        nr[i] = 1000;
        for( int j = 1; j <= m; j++ )
        {
            //cin >> ara[i][j];
            nr[i] = min( nr[i], ara[i][j] );
            nc[j] = 1000;
        }
    }

    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= m; j++ )
        {
            ara[i][j] -= nr[i];
            nc[j] = min( nc[j], ara[i][j] );
        }
    }
    int row = 0, col = 0;
    for( int i = 1; i <= n; i++ )
    {
        if( nr[i] != 0 )
            row+=nr[i];
    }
    for( int i = 1; i <= m; i++ )
    {
        if( nc[i] != 0 )
            col+=nc[i];
    }
    int f = 1;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= m; j++ )
        {
            ara[i][j] -= nc[j];
            if( ara[i][j] )
                f = 0;
        }
    }
    string s1 = "row ", s2 = "col ";
    if( ff )
    {
        s1 = "col ";
        s2 = "row ";
    }
    if( f )
    {
        cout << row+col << endl;
        for( int i = 1; i <= n; i++ )
        {
            if( nr[i] != 0 )
            {
                while( nr[i] )
                {
                    cout << s1 << i << endl;
                    nr[i]--;
                }
            }
        }
        for( int i = 1; i <= m; i++ )
        {
            if( nc[i] != 0 )
            {
                while( nc[i] )
                {
                    cout << s2 << i << endl;
                    nc[i]--;
                }

            }
        }
    }
    else
        cout << -1 << endl;

    return 0;
}



