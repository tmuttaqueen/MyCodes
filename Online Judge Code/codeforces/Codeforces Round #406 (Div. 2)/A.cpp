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
#define double      long double

typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

map<intl, intl>mm;

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl a, b, c,d , f = -1, ans = -1;
    cin >> b >> a;
    cin >> d >> c;
    for( int i = 0; i <  100000; i++ )
        mm[ a+i*b ] = 1;
    for( int i = 0; i < 100000; i++ )
    {
        if( mm[c+i*d] == 1 )
        {
            f = c+i*d;
            break;
        }
    }
    cout << f << endl;
}



