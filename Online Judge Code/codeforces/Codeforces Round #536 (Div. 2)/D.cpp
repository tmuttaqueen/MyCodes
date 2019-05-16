#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

vector<int>edge[MAXN];
int vis[MAXN];




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for( int i = 0; i < m; i++ )
    {
        int a, b;
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    //for( int i = 1; i <= n; i++ ) sort( edge[i].begin(), edge[i].end() );

    priority_queue<int>pq;
    pq.push(-1);
    int cnt = 0;
    while( !pq.empty() )
    {
        int u = -pq.top();
        pq.pop();
        if( vis[u] == 1 ) continue;
        vis[u] = 1;
        cout << u << " ";
        cnt++;
        if( cnt == n ) break;
        for( int v: edge[u] )
        {
            if( vis[v] == 0 ) pq.push(-v);
        }
    }

    return 0;
}
