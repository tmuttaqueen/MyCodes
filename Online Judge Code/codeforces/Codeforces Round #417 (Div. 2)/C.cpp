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

intl ara[SZ], temp[SZ];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl n, s;
    cin >> n >> s;
    for( int i = 0; i < n; i++ ) cin >> ara[i];
    int l = 0, r = n;
    intl ans, cost;
    while( l <= r )
    {
        int m = (l+r)/2;
        for( intl i = 0; i < n; i++ )
        {
            temp[i] = ara[i] + (i+1)*m;
        }
        sort( temp, temp+n );
        intl sum = 0;
        for( int i = 0; i < m; i++ ) sum += temp[i];
        if( sum <= s )
        {
            ans = m;
            cost = sum;
            l = m+1;
        }
        else
        {
            r = m-1;
        }

    }

    cout << ans << " " << cost << endl;

    return 0;
}



