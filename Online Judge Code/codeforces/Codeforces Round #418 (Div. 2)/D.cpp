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

intl x[1111], y[1111], r[1111];
int par[1111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> x[i] >> y[i] >> r[i];
    }
    for( int i = 0; i < n; i++ )
    {
        intl rr = r[i]*r[i];
        for( int j = 0; j < n; j++ )
        {
            intl d = ( x[j] - x[i] )*( x[j] - x[i] ) + ( y[j] - y[i] )*( y[j] - y[i] );
            if( d <= rr && rr > r[j]*r[j] && i != j )
            {
                //cout << i << " is par of " << j << endl;
                par[j]++;
            }
        }
    }

    long double ans = 0;
    for( int i = 0; i < n; i++ )
    {
        //cout << i << " " << r[i] << "  " << par[i] << endl;
        if( par[i] ==0 || par[i]%2 == 1 )
        {
            //what_is(i);
            ans += r[i]*r[i];
        }
        else
        {
            ans -= r[i]*r[i];
        }
    }
    ans *= pi;
    cout << setprecision(10) << fixed << ans << endl;
    return 0;
}


