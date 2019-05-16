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

const intl mod = 1e9+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    intl cur = 1, b, f = 1, g = 0;
    intl mx = 1LL<<61;
    for( int i = 0; i < n; i++ )
    {
        cin >> b;
        cur <<= 1;
        if( cur >= mx )
        {
            g = 1;
        }
        if( (g == 0 && cur < b) || f == 0 )
        {
            f = 0;
            continue;
        }
        if( g )
        {
            cur -= b;
            cur %= mod;
        }
        else
        {
            cur -= b;
        }

    }
    if(f)
    {
        cout << (cur%mod+mod)%mod << endl;
    }
    else
        cout << "error" << endl;
    return 0;
}
