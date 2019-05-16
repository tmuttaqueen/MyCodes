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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, k;
    cin >> n >> k;
    if( k > n*n )
    {
        cout << -1 << endl;
        return 0;
    }
    if( k > 0 )
        ara[1][1] = 1;
    k--;
    int r = 1, c = 2;
    for( int i = 1; r <= n ; i++ )
    {
        while( c <= n && k > 1)
        {
            ara[r][c] = 1;
            ara[c][r] = 1;
            c++;
            k-=2;
        }
        if( c > n )
        {
            r++;
            if( k > 0 )
            {
                ara[r][r] = 1;
                k--;
            }
            c = r+1;
        }
        else
        {
            break;
        }
    }
    r++;
    while( k > 0 )
    {
        ara[r][r] = 1;
        k--;
    }

    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            cout << ara[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}




