#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>

const int mx = 50005;

vector<int>edge[mx], cost[mx];
vector<int>ans(mx);

class comp
{
public:
    bool operator()( pii &a, pii &b )
    {
        return a.yy > b.yy;
    }
};

void dijktra( int u )
{
    for( int i = 0; i < mx; i++ ) ans[i] = 1e9;
    priority_queue<pii, vector<pii>, comp>pq;
    ans[u] = 0;
    pq.push( {u, 0} );
    while( !pq.empty() )
    {
        pii v = pq.top();
        pq.pop();
        int l = edge[v.xx].size();
        for( int i = 0; i < l; i++ )
        {
            int cn = edge[v.xx][i], cc = max( v.yy, cost[v.xx][i] );
            if( cc < ans[cn] )
            {
                ans[cn] = cc;
                pq.push({cn, cc});
            }
        }
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int t = 1;
    //scanf("%d", &t);
    while(t--)
    {
        int n, e;
        scanf("%d %d", &n, &e);
        for( int i = 0; i < e; i++ )
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            edge[a].pb(b);
            cost[a].pb(c);
            edge[b].pb(a);
            cost[b].pb(c);
        }
        dijktra(1);
        if( ans[n] == 1e9 ) printf("NO PATH EXISTS\n");
        else printf("%d\n",ans[n] );
    }

    return 0;
}



