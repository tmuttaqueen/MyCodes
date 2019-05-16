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

intl po[100];

intl ara[M];
intl cnt[100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    po[0] = 0;
    for( int i = 1; i <= 33; i++ )
    {
        po[i] = ( po[i-1]+1 )*2 - 1;
    }
    //intl d = 0;
    intl n, d;
    cin >> n >> d;
    intl s=  0;
    for( int i = 33; i >= 1; i-- )
    {
        s += (n/po[i])*i;
        cnt[i] = n/po[i];
        n %= po[i];
    }
    if( s > 10000 )
    {
        cout << -1 << endl;
        return 0;
    }
    cout << s << endl;
    intl cur = 1;
    for( int i = 33; i >= 1; i-- )
    {
        for( int j = 0; j < cnt[i]; j++ )
        {
            for( int k = 0; k < i; k++ )
            {
                cout << cur << " ";
            }
            cur += d;
        }
        //cur += d;
    }
    return 0;
}
