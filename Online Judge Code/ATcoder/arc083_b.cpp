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

int ara[345][345], dp[345][345];
vector< pair<int, pair<int,int> > > vec;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    intl sum = 0;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            cin >> ara[i][j];
            dp[i][j] = ara[i][j];

            if( j > i )
            {
                sum += ara[i][j];
                vec.pb( mp( ara[i][j], mp(i,j) ) );
            }
        }
    }
    sort( vec.begin(), vec.end() );
    reverse( vec.begin(), vec.end()  );
    for( int i =1; i <= n; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            for( int k = 1; k <= n; k++ )
            {
                if( dp[j][i] + dp[i][k] < dp[j][k] )
                {
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
    }

    for( int i = 0; i < vec.size(); i++ )
    {
        int d = vec[i].xx, x = vec[i].yy.xx, y = vec[i].yy.yy;
        int rem = 0;
        for( int j = 1; j <= n; j++ )
        {
            if( x != j && y != j )
            {
                if( ara[x][j] + ara[j][y] == d )
                {
                    rem = d;
                    break;
                }
            }
        }
        sum -= rem;
    }
    cout << sum << endl;


    return 0;
}
