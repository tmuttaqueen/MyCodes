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

int a[1000], b[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, k;
    cin >> n >> k;
    for( int i = 0; i < n; i++ ) cin >> a[i];
    for( int i = 0; i < k; i++ ) cin >> b[i];
    if( k > 1 )
    {
        cout << "Yes\n";
    }
    else
    {
        for( int i = 0; i < n; i++ )
            if( a[i] == 0 )
        {
            a[i] = b[0];
            break;
        }
        int f = 0;
        for( int i = 1; i < n; i++ )
        {
            if( a[i] - a[i-1] < 0  )
                f = 1;
        }
        if(f)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}




