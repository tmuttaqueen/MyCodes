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

int ara[1002][1002];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, a, b;
    cin >> n >> a >> b;
    if( (a > 1 && b > 1) || ( n == 2 && a==1 && b == 1 ) || ( n ==3 && a == 1 && b == 1 ) )
    {
        cout << "NO" << endl;
        return 0;
    }
    if( a == 1 && b == 1 )
    {
        for( int i = 1; i < n; i++ )
        {
            ara[i][i+1] = 1;
            ara[i+1][i] = 1;
        }
    }
    else
    {
        int f = 0;
        if( a == 1 )
        {
            f = 1;
            swap(a, b);
        }
        for( int i = 1; i <= n-a+1; i++ )
        {
            for( int j = 1; j <= n - a + 1; j++ )
            {
                if(i!=j)
                    ara[i][j] = 1;
            }
        }
        if( f )
        {
            for( int i = 1; i <= n; i++ )
            {
                for( int j = 1; j <= n; j++ )
                {
                    if(i!=j)
                    {
                        ara[i][j] ^= 1;
                    }
                }
            }
        }
    }


    cout << "YES" << endl;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            if( ara[i][j] != ara[j][i] )
            {
                while(1);
            }
            cout << ara[i][j];
        }
        cout << endl;
    }

    return 0;
}
