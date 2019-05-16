#include<bits/stdc++.h>

using namespace std;

#define intl long long

const int mx = 2e5 + 5;

struct edge
{
    intl u, v, w, s;
};

vector<edge>all;
vector<int>g[mx];
intl sum[mx];

int adj( int u, int i )
{
    if( u == all[i].u ) return v;
    else return u;
}

void dfsSUM( int u, int p, int from )
{
    if( from != -1 )
        sum[from] = 0;
    for( int x: g[u] )
    {
        int v = adj(u, x);
        if( v == p ) continue;
        dfsSUM(v, u, x);
        if( from != -1 )
        {
            sum[from] += sum[x];
            sum[from] += all[x].w;
        }
    }
}
int f = 1;
stack<int>komabo;
long long dfsSOLVE( int u, int p, int from )
{
    long long komaisi = 0;
    for( int x: g[u] )
    {
        int v = adj(u, x);
        if( v == p ) continue;
        if( all[x].s < sum[x] )
            komabo.push(x);
        komaisi += dfsSOLVE(v, u, x);
    }
    if( !komabo.empty() )
    {
        long long komanolagbe = sum[komabo.top()] - all[komabo.top()].s;
        if( komanolagbe > komaisi )
        {
            long long d = komanolagbe - komaisi;
            if( min(all[from].w, all[from].s) < d  )
            {

            }
        }

    }

    return komaisi;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for( int i = 0; i < n-1; i++ )
    {
        int u, v, w, s;
        cin >> u >> v >> w >> s;
        all.push_back( {u,v,w,s} );
        g[u].push_back(i);
        g[v].push_back(i);
    }



    return 0;
}
