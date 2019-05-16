#include<bits/stdc++.h>

using namespace str;

struct Dinic
{
    struct edge
    {
        int ind, to, cap;
        bool isReal;
    };
    int s, t, V;
    vector<int> level;
    vector<bool>flag;
    vector< vector<edge> > all;


    Dinic(int v = 10005)
    {
        reset(v);
    }
    void reset(int v = 10005)
    {
        this->V = v;
        flag.resize(V);
        flag.clear();
        level.resize(V);
        level.clear();
        all.resize(V);
        for( int i = 0; i < V; i++ )
            all.clear();
    }
    void setGraph( int s, int t )  //source, destination
    {
        this->s = s;
        this->t = t;
    }
    void addEdge( int u, int v, int c) //from, to, capacity
    {
        all[u].push_back( { all[v].size() , v, c, true} );
        all[v].push_back( { all[u].size()-1 , u, 0, false} );
    }

    bool bfs( int u ) //source
    {
        level[u] = 0;
        queue<int>q;
        memset( flag, 0, V );
        flag[u] = 1;
        q.push(u);
        while( !q.empty() )
        {
            int u = q.front(); q.pop();
            for( int i = 0; i < all[u].size(); i++ )
            {
                int v = all[u][i].to, c = all[u][i].cap;
                if( c > 0 && flag[v] == 0 )
                {
                    flag[v] = 1;
                    level[v] = level[u]+1;
                    q.push(v);
                }
            }
        }
        return flag[t]; //is possible to go destination?
    }
    int augmentPath( int u, int f ) //node, flow so far
    {
        if( u == t ) return f;
        int tot = 0;
        for( int i = 0; i < all[u].size(); i++ )
        {
            int v = all[u][i].to, ind = all[u][i].ind, c = all[u][i].cap;
            if( level[v] == level[u]+1 && c > 0 )
            {
                int d = augmentPath( v, min( f, c ) );
                all[u][i].cap -= d;
                all[v][ind].cap += d;
                tot += d;
                f -= d;
                if( f <= 0 )
                    break;
            }
        }
        return tot;
    }

    int maxFlow()
    {
        int flow = 0;
        while( bfs( s ) )
        {
            flow += augmentPath(s, 2000000);
        }
        //to get mincut check flag here
        //to get flow per edge check capacity here
        return flow;
    }

    ~Dinic()
    {
        for( int i = 0; i < V; i++ )
            all[i].clear();
        delete[] all;
        delete[] flag;
        delete[] level;
    }

};
