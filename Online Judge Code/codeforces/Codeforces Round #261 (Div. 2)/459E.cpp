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


int dp[M];

vector<pii>vec[M];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m, a, b, c;
    cin >> n >> m;
    for( int i = 0; i < m; i++ )
    {
        cin >> a >> b >> c;
        vec[c].pb( mp(a,b) );
    }
    int ans = 0;
    vector<int>v;
    for( int i = 1; i <= 100000; i++ )
    {
        v.clear();
        for( pii x: vec[i] )
        {
            v.pb( dp[x.xx] + 1 );
        }
        for( int j = 0; j < vec[i].size(); j++ )
        {

            dp[ vec[i][j].yy ] = max( dp[vec[i][j].yy], v[j] );
            //cout << v[j] << endl;
            ans = max(ans, dp[ vec[i][j].yy] );
        }
    }
    cout << ans << endl;

    return 0;
}
