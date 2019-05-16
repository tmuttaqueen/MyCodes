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

intl ara[11111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl mx=0, mn=1000000000, s=  0, n ;
    cin >> n;
    for(  int i = 0; i < n; i++ )
    {
        cin >> ara[i];
        s += ara[i];
        mn = min(mn, ara[i]);
        mx = max(mx, ara[i]);
    }
    for( int i = 0; i < n; i++ )
    {
        if( ara[i] == mn )
        {
            s -= mn;
        }
        if( ara[i] == mx )
            s -= mx;
    }
    cout << s << endl;

    return 0;
}
