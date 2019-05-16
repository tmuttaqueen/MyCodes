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
const int M = 145678;

vector<int>edge[M], cost[M], forbid[M], next[M];

int dist[M];

int getNext( int u, int t )
{
    int l = 0, r = forbid[u].size()-1;
    int ind = -1, f = 0;
    while( l <= r )
    {
        int m = (l+r)/2;
        if( forbid[u][m] == t )
        {
            ind = m;
            break;
        }
        else if( forbid[u][m] > t )
        {
            r = m -1;
        }
        else
            l = m + 1;
    }
    if( ind == -1 ) return t;
    else return next[u][ind];
}

void dijktra( int s )
{
    priority_queue< pii >pq;
    memset( dist, 125, sizeof dist );
    dist[s] = 0;
    pq.push( mp( 0,s ) );
    while( !pq.empty() )
    {
        pii x = pq.top();
        pq.pop();
        int u = x.yy, d = -x.xx;
        for( int i = 0; i < edge[u].size(); i++ )
        {
            int w = cost[i][j], v = edge[i][j];
            int dd = d + w;
            dd = getNext(v, dd);
            if( dd < dist[v] )
            {
                dist[v] = dd;
                pq.push( mp( -dd, v ) );
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m, a, b w;
    cin >> n >> m;
    for( int i = 0; i < m; i++ )
    {
        cin >> a >> b >> w;
    }
    for( int i = 1; i <= n; i++ )
    {
        int k;
        cin >> k;
        for( int j = 0; j < k; j++ )
        {
            cin >> a;
            forbid[i].pb(a);
        }
        next[i].resize(k);
        for( int j = k-1; j >=0; j-- )
        {
            if( j == k-1 ) next[i][j] = forbid[i][j] + 1;
            else if( forbid[i][j] == forbid[i][j+1] ) next[i][j] = next[i][j+1];
            else next[i][j] = forbid[i][j] + 1;
        }
    }

    dijktra(1);
    cout << dist[n] << endl;







    return 0;
}
