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
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

pii edge[111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t;
    int deg[111];
    int flag[111];
    cin >> t;
    while(t--)
    {
        int n, m, c = 0, a, b;
        memset( deg, 0, sizeof deg );
        cin >> n >> m;
        for( int i = 0; i < m; i++ )
        {
            cin >> a >> b;
            deg[a]++;
            deg[b]++;
            flag[i] = 1;
            edge[i] = mp(a,b);
        }

    }
    return 0;
}
