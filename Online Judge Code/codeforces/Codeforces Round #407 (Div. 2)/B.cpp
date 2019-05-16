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
    intl a, b1, q, l, m;
    cin >> b1 >> q >> l >> m;
    for( int i = 0; i < m; i++ )
    {
        cin >> a;
        mm[a] = 1;
    }
    if( abs(b1) > l )
    {
        cout << 0 << endl;
        return 0;
    }
    if( b1 == 0 )
    {
        if( mm[0] == 1 )
        {
            cout << 0 << endl;
        }
        else
            cout << "inf\n";
        return 0;
    }

    if( q == 0 )
    {

        int ans = 0;
        if( abs(b1) <= l && mm[b1] == 0 ) ans++;
        if( mm[0] == 0 )
        {
            cout << "inf\n";
        }
        else
            cout << ans << endl;
        return 0;
    }

    if( q == 1 )
    {
        int ans = 0;
        if( abs(b1) <= l && mm[b1] == 0 )
        {
            cout << "inf\n";
        }
        else
            cout << 0 << endl;
        //cout << ans << endl;
        return 0;
    }
    if( q == -1 )
    {
        int ans = 2;
        if( abs(b1) > l )
        {
            cout << 0 << endl;
            return 0;
        }
        if( mm[b1] == 0 || mm[-b1] == 0 )
        {
            cout << "inf\n";
            return 0 ;
        }
        if( mm[-b1] == 1 ) ans--;
        if( mm[b1] == 1 ) ans--;
        cout << ans << endl;
        return 0;
    }
    int ans = 0;
    while( abs(b1) <= l )
    {
        if( mm[b1] == 0 )
            ans++;
        b1 *= q;
    }

    cout << ans << endl;

    return 0;
}




