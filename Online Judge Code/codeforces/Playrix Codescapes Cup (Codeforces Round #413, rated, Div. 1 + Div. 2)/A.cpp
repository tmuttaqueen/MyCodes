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


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, k, t, d, cur = 1,j = -1;
    cin >> n >> t >> k >> d;
    int t1 = ceil( double(n)/k )*t, t2 = 0;
    //what_is(t1);
    for( int i = 1; i <= 10000000; i++ )
    {
        if(n > 0 && i%t == 0)
        {
            t2 = i;
            n -= k;
        }
        if(  n > 0 && cur > 1 && j%t == 0 )
        {
            t2 = i;
            n -= k;
        }
        if( n < 1 )
            break;
        if( i == d )
        {
            j = 0;
            cur++;
        }
        if( cur > 1 ) j++;
    }
    what_is(t2);
    if( t1 > t2 )
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}




