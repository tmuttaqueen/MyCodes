#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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


typedef tree < intl, null_type,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

long double ara[105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ ) cin >> ara[i];
    for( int i = 0; i < n; i++ )
    {
        if( 1.0 - ara[i] < 0.00000000001 )
        {
            cout << setprecision(12) << fixed << ara[i] << endl;
            return 0;
        }
    }
    sort( ara, ara + n );
    //for( int i = 0; i < n; i++ ) cout << ara[i] << " ";
    //cout << endl;
    long double mx = 0, ans = 0;
    for( int i = 0; i < n; i++ )
    {
        long double kn = 0, inv = 1;
        int temp = i;
        while( i < n )
        {
            kn = kn + 1.0/( 1- ara[i] ) - 1;
            inv *= (1-ara[i]);
            if( kn - 1.0 > 0.000000000000001 )
                break;

            i++;
        }
        //what_is(i);
        if( i == n ) i--;
        mx = 0;
        //cout << temp << " " << i << " " << inv << endl;
        for( int j = temp; j <= i; j++ )
        {
            mx += inv/(1-ara[j])*ara[j];
            //what_is(mx);
        }
        //what_is(mx);
        for( int i = 0; i < n; i++ )
        {
            ans = max( mx, ans );
        }
        i = temp;
    }

    cout << setprecision(12) << fixed << ans << endl;
    return 0;
}




