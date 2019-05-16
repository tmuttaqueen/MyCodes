#include<bits/stdc++.h>

using namespace std;
const int mx = 404;
int x[mx], y[mx];
int dist[mx][mx], par[mx];
vector<int>edge[mx];
int cnt[mx];


struct data
{
    int w, u, v;

    bool operator<( data &a )
    {
        return this->w < a.w;
    }
};

vector<data>all;

int find_par( int u )
{
    if( par[u] == u ) return u;
    return par[u] = find_par( par[u]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        //ans.clear();
        all.clear();
        int n, a, b;
        cin >> n;
        for( int i = 1; i <= n; i++ )
        {
            cin >> x[i] >> y[i];
            par[i] = i;
        }
        for( int i = 1; i <= n; i++ )
        {
            for( int j = i+1; j <= n; j++ )
            {
                dist[i][j] = ( x[i] - x[j] )*( x[i] - x[j] ) + (y[i]-y[j])*(y[i]-y[j]);
                dist[j][i] = dist[i][j];
                all.push_back( {dist[i][j], i, j}  );
            }
        }
        sort( all.begin(), all.end() );
        int c = 0;
        for( int i = 0; i < all.size(); i++ )
        {
            int w = all[i].w, u = all[i].u, v = all[i].v;
            int pu = find_par(u), pv = find_par(v);
            if( pu != pv )
            {
                par[pu] = pv;
                cout << u << " " << v << "\n";
                //edge[u].push_back(v);
                //edge[v].push_back(u);
                c++;
                if( c == n-1 ) break;
            }
        }
        /*memset( cnt, 0, sizeof cnt );
        for( int i = 1; i <= n; i++ )
        {
            int md = 0;
            for( int j = 0; j < edge[i].size(); j++ )
            {
                int d = dist[i][ edge[i][j] ];
                md = max(d, md);
            }
            for( int j = 1; j <= n; j++ )
            {
                if( dist[i][j] <= md )
                    cnt[j]++;
            }
        }
        int ans = 0;
        for( int i = 1; i <= n; i++ )
            ans = max( ans, cnt[i] );
        cou*/


    }

    return 0;
}
