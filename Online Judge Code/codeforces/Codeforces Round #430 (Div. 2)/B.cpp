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

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl rr, d;
    cin >> rr >> d;
    intl n;
    cin >> n;
    intl ans = 0;
    intl R = rr-d;
    for( int i = 0; i < n; i++)
    {
        intl x,y,r;
        cin >> x >> y >> r;
        intl r1 = (R+r)*(R+r), r2 = (rr-r)*(rr-r);
        intl d = x*x+y*y;
        if( d >= r1 && d <= r2 )
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
