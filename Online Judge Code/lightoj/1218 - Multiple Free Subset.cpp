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

const int MAX = 100001, NIL = 0, INF = 1<<28;

struct BPM
{
    vector< int > edge[MAX];
    int n, m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// edge = NIL[0] ∪ edge1[edge[1---n]] ∪ edge2[edge[n+1---n+m]]

    bool bfs()
    {
        int u, v, len;
        queue< int > Q;
        for( int i = 1; i <= n; i++)
        {
            if( match[i] == NIL)
            {
                dist[i] = 0;
                Q.push(i);
            }
            else dist[i] = INF;
        }
        dist[NIL] = INF;
        while( !Q.empty() )
        {
            u = Q.front();
            Q.pop();
            if( u != NIL)
            {
                len = edge[u].size();
                for( int i = 0; i < len; i++ )
                {
                    v = edge[u][i];
                    if( dist[match[v]] == INF )
                    {
                        dist[match[v]] = dist[u] + 1;
                        Q.push(match[v]);
                    }
                }
            }
        }
        return dist[NIL] != INF;
    }

    bool dfs(int u)
    {
        int v, len;
        if( u != NIL)
        {
            len = edge[u].size();
            for( int i = 0; i < len; i++)
            {
                v = edge[u][i];
                if( dist[match[v]] == dist[u]+1 )
                {
                    if( dfs(match[v]) )
                    {
                        match[v] = u;
                        match[u] = v;
                        return true;
                    }
                }
            }
            dist[u] = INF;
            return false;
        }
        return true;
    }
    void init( int nn, int mm )
    {
        n = nn;
        m = mm;
        // match[] is assumed NIL for all vertex in edge. Clear it for multiple case.
        for( int i = 0; i <= n+m+2; i++ )
        {
            edge[i].clear();
            match[i] = 0;
            dist[i] = 0;
        }
    }
    //from set A to set B
    void addEdge( int u, int v )
    {
        //u := [1, n] ... v := [n+1,n+m]
        edge[u].push_back(v);
    }
    int hopcroft_karp()
    {
        int matching = 0, i;
        while( bfs() )
        {
            for( int i = 1; i <= n; i++)
                if( match[i] == NIL && dfs(i) )
                    matching++;
        }
        return matching;
    }

};

vector<int>vec;
set<int>ss;

int main()
{
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    BPM bpm;
    while(t--)
    {
        ss.clear();
        int a,n;
        scanf("%d", &n);
        for( int i = 0; i < n; i++ )
        {
            scanf("%d", &a);
            ss.insert(a);
        }
        vec.clear();
        for( set<int>::iterator it = ss.begin(); it != ss.end(); it++ )
        {
            vec.pb(*it);
        }
        n = vec.size();
        bpm.init(n,n);
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                if( vec[j]%vec[i] == 0 && i != j )
                {
                    bpm.addEdge(i+1, j+1+n);
                }
            }
        }
        int mt = n - bpm.hopcroft_karp();
        //what_is(mt);
        vector<int>ans, temp;
        for( int i = 0; i < n; i++ )
        {

            int f = 0;
            for( int j = 0; j < ans.size(); j++ )
            {
                if( vec[i]%ans[j] == 0 || ans[j]%vec[i] == 0 )
                    f = 1;
            }
            if(f) continue;
            if( ans.size() == mt ) break;
            temp.clear();
            for( int j = 0; j < n; j++ )
            {
                if( vec[j]%vec[i] != 0 && vec[i]%vec[j] != 0 )
                {
                    temp.pb(vec[j]);
                }
            }
            int nn = temp.size();
            if( nn == 0 )
            {
                if( mt == 1 ) ans.pb(vec[i]);
                continue;
            }
            bpm.init( nn, nn );
            f = 0;
            for( int j = 0; j < nn; j++ )
            {
                for( int k = 0; k < nn; k++ )
                {
                    if( temp[k]%temp[j] == 0 && j != k )
                    {
                        bpm.addEdge( j+1, k+1+nn );
                        f = 1;
                    }
                }
            }
            int d;
            if(f == 0)
                d = 0;
            else
                d = bpm.hopcroft_karp();
            if( nn - d == mt-1 )
                ans.pb( vec[i] );
        }
        printf("Case %d:", caseno++);
        for( int i = 0; i < ans.size(); i++ )
        {
            printf(" %d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
