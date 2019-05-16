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
int temp[101][101];
int n;
bool isvalid()
{
    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < n; j++ )
        {
            for( int k = 0; k < n; k++ )
            {
                if( k != j )
                {
                    if( temp[i][j] == temp[i][k] ) return 0;
                }
            }

            for( int k = 0; k < n; k++ )
            {
                if( k != i )
                {
                    if( temp[i][j] == temp[k][j] ) return 0;
                }
            }
        }
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {

        cin >> n;
        int ara[n][n];
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                cin >> ara[i][j];
            }
        }
        int ans = 1000000;
        int mask = (1<<(n*n));
        for( int i = 0; i < mask; i++ )
        {
            for( int i = 0; i < n; i++ )
            {
                for( int j = 0; j < n; j++ )
                {
                    temp[i][j] = ara[i][j];
                }
            }
            int d =0, x = 1000;
            for( int j = 0; j < n*n; j++ )
            {
                if( i&(1<<j) )
                {
                    d++;
                    int r = j/n, c = j%n;
                    temp[r][c]= x++;
                }
            }
            if( isvalid() )
            {
                ans = min(ans, d);
            }
        }
        cout << "Case #" << caseno++ << ": " << ans << endl;
    }
    return 0;
}
