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
const int M = 345678;

vector<int>edge[M], tm[M];
set<int>ss[M], edge[M];
map<pii>mm;
int t[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m, h;
    cin >> n >> m >> h;
    for( int i = 1; i <= n; i++ )
    {
        int a;
        t[i] = a;
        cin >> a;
        tm[a].pb(i);
    }
    for( int i = 1; i <= m; i++ )
    {
        int a, b;
        cin >> a >> b;
        mm[ mp(a,b) ] = 1;
        mm[ mp(b,a) ] = 1;
    }
    for( int i = 1; i <= n; i++ )
    {

        for(  )
    }
    return 0;
}
