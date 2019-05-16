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

int ara[M];
vector<int>edge[M], cost[M];

int ans[M], vis[M];

void dijktra( int u )
{

    priority_queue<pii>q;
    q.push( mp(0, u) );
    int f = 1;
    while(!q.empty())
    {
        pii t = q.top();
        q.pop();
        int u = t.yy, d = -t.xx;
        if( vis[u] == 1 ) continue;
        vis[u] = 1;
        ans[u] = d;
        //cout << u << " " << d << endl;
        for( int i = 0; i < edge[u].size(); i++ )
        {
            int v = edge[u][i];
            //cout << u << ' ' << v << endl;
            if( vis[v] == 0 && ans[v] >= d + cost[u][i] )
            {
                ans[v] = d + cost[u][i];
                //cout << u << " " << v << " "<< ans[v] << endl;

                q.push( mp( -ans[v], v ) );
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, a;
    intl s = 0;
    cin >> n;
    int ind = -1, prev = -1;
    for( int i = 1; i <= n; i++ )
    {
        cin >> a;
        if( a >= prev )
        {
            prev = a;
            ind = i;
        }
        s += a;
        edge[0].pb(i);
        cost[0].pb(0);
        if( i > 1 )
        {
            edge[i].pb(1);
            cost[i].pb(-a);
            edge[i-1].pb(i);
            cost[i-1].pb(1);
        }
    }
    //memset( ans, 60, sizeof ans );
    //ans[ind] = 0;
    dijktra(ind);
    intl sum = 0;
    for( int i = 1; i <= n; i++ )
    {
        cout << ans[i] << endl;
        sum += ans[i];
    }
    intl d = 1 - ans[1];
    sum += n*d;
    sum -= n + s;
    cout << sum << endl;
    return 0;
}
