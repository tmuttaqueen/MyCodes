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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int a, b, c = 0;
    scanf("%d:%d", &a, &b);
    int d1 = a/10, d2 = a%10, d3 = b/10, d4 = b%10;
        if( d1 == d4 && d2 == d3 )
        {
            cout << 0 << endl;
            return 0;
        }
    for( int i = 0; i < 2000; i++ )
    {
        c++;
        b++;
        if( b == 60 )
        {
            a++;
            b = 0;
        }
        if( a == 24 )
        {
            a = 0;
        }
        int d1 = a/10, d2 = a%10, d3 = b/10, d4 = b%10;
        if( d1 == d4 && d2 == d3 )
        {
            cout << c << endl;
            return 0;
        }
    }

    return 0;
}



