#include<bits/stdc++.h>

using namespace std;


namespace ahocorasick
{
    const int MAX = 300005, sigma = 26;
    struct State
    {
        int to[sigma];
        int par;
        int suffLink;
        int cnt;
        int toLet;
        int depth;
    };
    State node[MAX];
    int nodeCount;
    int root;
    vector<int>suffRG[MAX];

    inline int index( char ch )
    {
        return ch - 'a';
    }
    inline void create( int i )
    {
        node[i].cnt = 0;
        for( int j = 0; j < sigma; j++ )
            node[i].to[j] = -1;
    }
    void init( int n = 100000 )
    {
        nodeCount = 0;
        create(++nodeCount);
        root = nodeCount;
        node[root].depth = 0;
        node[root].par = 0;
        for( int i = 0; i <= n; i++ )
            suffRG[i].clear();
    }
    int add( char *str )
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
}

char str[1000005];
char s[505];
int ind[505];

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        ahocorasick::init(505*505);
        int n;
        scanf("%d", &n);
        scanf("%s", str);
        for( int i = 1; i <= n; i++ )
        {
            scanf("%s", s);
            ind[i] = ahocorasick::add(s);
        }
        ahocorasick::suffLink();
        int u = ahocorasick::root;
        for( int i = 0; str[i]; i++ )
        {
            int v = str[i] - 'a';
            while( ahocorasick::node[u].to[v] == -1 && u > 1 )
            {
                u = ahocorasick::node[u].suffLink;
            }
            if( ahocorasick::node[u].to[v] != -1 )
            {
                u = ahocorasick::node[u].to[v];
            }
            ahocorasick::node[u].cnt++;
        }
        ahocorasick::dfs(1,-1);
        printf("Case %d:\n", caseno++);
        for( int i = 1; i <= n; i++ )
        {
            printf("%d\n", ahocorasick::node[ind[i]].cnt);
        }
    }

    return 0;
}










