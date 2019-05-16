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
#define double      long double

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

intl nP2( intl n )
{
    return n*(n-1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl n,m;
    while(1)
    {
        cin >> n >> m;
        if( n ==0 &&m == 0 )
        {
            return 0;
        }
        if( n > m ) swap(n,m);
        intl d = n-1;
        //if( d < 2 ) d = 0;
        intl ans = n*nP2(m) + m*nP2(n) + 4*( d*(d+1)*(2*d+1)/6 - d*(d+1)/2 ) + 2*(m-n+1)*nP2(n);
        cout << ans << endl;

    }
    return 0;
}
