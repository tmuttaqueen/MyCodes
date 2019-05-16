#include<bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define xx first
#define yy second
#define mp make_pair

const int MAXN = 1000005, sigma = 26;

struct AhoCorasick
{
    struct State
    {
        int to[sigma];
        int go[sigma];
        int par;
        int suffLink;
        int cnt;
        int toLet; //via whitch letter did this node came
        int depth;
    };
    vector<State> node;
    //State node[MAX];
    int nodeCount;
    int root;
    vector< vector<int> > suffRG;

    inline int index( char ch )
    {
        return ch - 'A';
    }
    inline void create( int i )
    {
        //suffRG[i].clear();
        node[i].cnt = 0;
        for( int j = 0; j < sigma; j++ )
            node[i].to[j] = node[i].go[j] = -1;
    }
    void init( int n = MAXN )
    {
        node.resize(n+1);
        suffRG.resize(n+1);
        nodeCount = 0;
        create(++nodeCount);
        root = 1;
        node[root].depth = 0;
        node[root].par = 0;
        for( int i = 0; i < n; i++ )
            suffRG[i].clear();
    }
    int add(const char *str ) //returns the node it is added
    {
        int cur = root;//, len = strlen(str);
        for( int i = 0; str[i]; i++ )
        {
            int v = index(str[i]);
            if( node[cur].to[v] == -1 )
            {
                create(++nodeCount);
                node[cur].to[v] = nodeCount;
                node[nodeCount].par = cur;
                node[nodeCount].depth = node[cur].depth+1;
            }

            cur = node[cur].to[v];
            node[cur].toLet = v;

        }
        return cur;
    }
    void suffLink()
    {
        int cur = root;
        queue<int>q;
        q.push(cur);
        while( !q.empty() )
        {
            int u = q.front();
            q.pop();
            int last = node[u].toLet;
            if( node[u].depth <= 1 )
            {
                node[u].suffLink = 1;
            }
            else
            {
                int cur = node[ node[u].par ].suffLink;
                while( cur > 1 && node[cur].to[last] == -1  )
                {
                    cur = node[cur].suffLink;
                }
                if( node[cur].to[last] != -1)
                    cur = node[cur].to[last];
                node[u].suffLink = cur;
            }
            if( u != 1 )
            {
                suffRG[node[u].suffLink].push_back(u);
            }
            for( int i = 0; i < sigma; i++ )
            {
                if( node[u].to[i] != -1 )
                    q.push(node[u].to[i]);
            }

        }
    }

    inline int nextState(int u, int v)
    {
        if( node[u].go[v] != -1 )
            return node[u].go[v];
        if( node[u].to[v] != -1 )
            return node[u].go[v] = node[u].to[v];
        if( u == 1)
            return node[u].go[v] = max( node[u].to[v], 1 );
        return node[u].go[v] = nextState(node[u].suffLink, v);
    }

    void dfs( int u, int p )
    {
        for( int i = 0; i < suffRG[u].size(); i++ )
        {
            int v = suffRG[u][i];
            if( v == p ) continue;
            dfs(v, u);
            node[u].cnt += node[v].cnt;
        }
    }
};

vector<pii> edge[MAXN];
int ans[MAXN], ind[MAXN];
int n, k;
AhoCorasick ac;

void solve(int u, int cur)
{
    queue<pii> q;
    q.push( mp(u, cur) );
    while(!q.empty())
    {
        pii a = q.front();
        int u = a.xx, cur = a.yy;
        ac.node[cur].cnt++;
        q.pop();
        for(pii p: edge[u])
        {
            int nxt = ac.nextState(cur, p.yy);
            q.push(mp(p.xx, nxt));
        }
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >>k;
    ac.init();
    char ch;
    int p;
    for(int i = 1; i <= n; i++ )
    {
        cin.ignore();
        cin >> ch >> p;
        edge[p].push_back(mp(i,ch-'A'));
    }

    for(int i = 1; i <= k ; i++)
    {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        ind[i] = ac.add(s.c_str());
    }
    ac.suffLink();
    solve(0, ac.root);
    ac.dfs(ac.root,-1);

    for(int i = 1; i <= k; i++)
    {
        cout << ac.node[ind[i]].cnt << "\n";
    }


    return 0;
}
