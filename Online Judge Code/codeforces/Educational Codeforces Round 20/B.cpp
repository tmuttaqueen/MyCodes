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

int ara[SZ], n;
vector<int>z;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i];
        if( ara[i] == 0)
            z.pb(i);
    }
    int s = z.size();
    for( int i = 0; i < n; i++ )
    {
        int d = lower_bound( z.begin(), z.end(), i ) - z.begin();
        //what_is(d);
        if( d == s )
        {
            cout <<  abs( z[d-1] - i ) << " ";
        }
        else
        {
            cout << min( abs( z[d-1] - i ) , abs( z[d] - i ) ) << " ";
        }
    }
    return 0;
}




