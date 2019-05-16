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

const int mx = 1005;
int n, val[mx], vis[mx], sum;
vector<int>edge[mx];

void dfs( int u )
{
    sum += val[u];
    vis[u]  = 1;
    n++;
    int l = edge[u].size();
    for( int i = 0; i < l; i++ )
    {
        int v = edge[u][i];
        if( vis[v] == 0 )
            dfs(v);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int v, e;
        scanf("%d %d", &v, &e);
        for( int i = 1; i <= v; i++ )
        {
            scanf("%d", &val[i]);
        }
        for( int i = 0; i < e;i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            edge[a].pb(b);
            edge[b].pb(a);
        }
        memset( vis, 0, sizeof(vis) );
        n = sum = 0;
        dfs(1);
        bool ans = 1;
        int cc;
        if( sum % n == 0 )
        {
            cc = sum/n;
        }
        else
            ans = 0;
        for( int i =1; i<= v && ans == 1; i++ )
        {
            if( vis[i] == 0 )
            {
                n = sum = 0;
                dfs(i);
                if( sum % n == 0 )
                {
                    int temp = sum/n;
                    if( temp != cc ) ans = 0;
                }
                else
                    ans = 0;
            }
        }
        //what_is(v);
        if(ans)
            printf("Case %d: Yes\n", caseno++);
        else
            printf("Case %d: No\n", caseno++);
        for( int i = 1; i <= v; i++ )
        {
            edge[i].clear();
        }
    }

    return 0;
}



