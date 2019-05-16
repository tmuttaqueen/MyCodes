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
#define piii        pair<pii, int>

vector<int>edge[10005];
int disc[10005], rep[10005], onst[10005], tt = 0, low[10005], in[10005];
stack<int>st;
vector<int>lst;

void dfs( int u )
{
    //what_is(u);
    int l = edge[u].size();
    disc[u] =  low[u] = tt++;
    st.push(u);
    onst[u] = 1;
    for( int i = 0; i < l; i++ )
    {
        int v = edge[u][i];
        if( disc[v] == -1 )
        {
            dfs(v);
            low[u] = min( low[u], low[v] );
        }
        else if( onst[v] == 1 )
        {
            low[u] = min( low[u], disc[v] );
        }
    }

    if( disc[u] == low[u] )
    {
        lst.pb(u);
        int w = st.top();
        while( w != u && !st.empty() )
        {
            onst[w] = 0;
            rep[w] = u;
            st.pop();
            w = st.top();
        }
        onst[u] = 0;
        rep[u] = u;
        st.pop();
        //what_is(u);
    }

}

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        tt = 0;
        memset( disc, -1, sizeof(disc) );
        memset( onst, 0, sizeof(onst) );
        memset( in, 0, sizeof(in) );
        int n, m, a, b;
        scanf("%d %d", &n, &m);
        for( int i = 0; i < m; i++ )
        {
            scanf("%d %d", &a, &b);
            edge[a].pb(b);
        }
        for( int i = 1; i <= n; i++  )
        {
            if( disc[i] == -1 )
            {
                dfs(i);
                //what_is(i);
            }
        }
        int l = lst.size();
        for( int i = 1; i <= n ; i++ )
        {
            for( int j = 0; j < edge[i].size(); j++ )
            {
                int v = edge[i][j];
                if( rep[v] != rep[i] )
                {
                    in[ rep[v] ]++;
                }
            }
            edge[i].clear();
        }

        int ans = 0;
        for( int i = 0; i < l; i++ )
        {
            int u = lst[i];
            if( in[u] == 0 )
                ans++;
        }
        printf("Case %d: %d\n", caseno++, ans);

        lst.clear();
        while(!st.empty())
            st.pop();
    }

    return 0;
}



