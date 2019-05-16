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
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 100*100*100+5;

set<pii>ts;
int prv;
int c;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int k, a;
    cin >> k;
    for( int i = 0; i < k; i++ )
    {
        cin >> a;
        ts.insert(mp(a, 0));
        c++;
    }
    cin >> k;
    for( int i = 0; i < k; i++ )
    {
        cin >> a;
        if( ts.find( mp(a, 0) ) != ts.end() )
        {
            ts.erase( mp(a,0) );
            ts.insert( mp(a,2) );
        }
        else
        {
            ts.insert( mp(a , 1) );
            c++;
        }
    }
    int ans = 0;
    prv = -1;
    for( auto it = ts.begin(); it != ts.end(); it++ )
    {
        pii p = (*it);
        if( p.yy == prv ) continue;
        ans++;
        if( p.yy == 2 ) prv = -1;
        else prv = p.yy;
    }
    cout << ans << endl;
    return 0;
}
