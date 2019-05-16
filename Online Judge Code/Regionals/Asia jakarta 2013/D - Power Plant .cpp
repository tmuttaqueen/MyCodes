#include<bits/stdc++.h>

using namespace std;

const int M = 202;

#define pii pair<int,int>
#define mp make_pair
#define xx first
#define yy second
#define pb push_back


vector<pii>edge[M], cost[M];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t ,caseno = 1;
    cin >> t;
    while(t--)
    {
        int n, m, p, a, b, c;
        cin >> n >> m >> p;
        vector<int>v;
        for( int i = 0; i < p; i++ )
        {
            cin >> a;
            v.pb(a);
        }
        for( int i = 0; i < m; i++ )
        {
            cin >> a >> b >> c;
            edge[a].pb(mp(b,c));
            edge[b].pb( mp(a,c) );
        }
        bool flag[M];
        memset( flag, 0 , sizeof flag );
        priority_queue<pii>pq;
        for( int x: v )
        {
            flag[x] = 1;
            for( pii u: edge[x] )
            {
                pq.push( mp( -u.yy, u.xx ) );
            }
        }
        int tot = p;
        int ans = 0;
        while( tot < n )
        {
            pii t = pq.top();
            pq.pop();
            if( flag[t.yy] ) continue;
            flag[t.yy] = 1;
            //cout << -t.xx << "  " << t.yy << endl;
            tot++;
            ans += (-t.xx);
            for( pii u: edge[t.yy] )
            {
                if( flag[u.xx] == 0)
                {
                    pq.push( mp( -u.yy, u.xx ) );
                }
            }
        }
        cout << "Case #" << caseno++ << ": " << ans << endl;
        for( int i = 1; i <= n; i++ ) edge[i].clear();
    }

    return 0;
}
