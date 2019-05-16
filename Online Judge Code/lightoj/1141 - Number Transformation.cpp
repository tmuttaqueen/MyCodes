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

vector<int>edge[1005];
int a, b;
int lv[1005], flag[1005];

int bfs( int s )
{
    queue<int>qq;
    qq.push(s);
    flag[s] = 1;
    while( !qq.empty() )
    {
        int u = qq.front();
        //what_is(u);
        qq.pop();
        //flag[u] = 1;
        for( int i = 0; i < edge[u].size(); i++ )
        {
            int v = edge[u][i];
            if( v <= b && flag[v] == 0 )
            {
                qq.push(v);
                flag[v] = 1;
                lv[v] = 1+lv[u];
                if( v == b )
                    return lv[v];
            }
        }
    }
    return -1;
}

void sieve()
{
    bool flag[1005];
    memset( flag, 0, sizeof(flag));
    flag[2] = 0;
    for( int i = 2; i <= 1000; i++ )
    {
        if( !flag[i] )
            for( int j = i+i; j <= 1000; j+=i )
            {
                flag[j] = 1;
                edge[j].pb(j+i);
            }
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    sieve();
    /*int tt = 69;
    for( int i = 0; i < edge[tt].size(); i++ )
        cout << edge[tt][i] << " ";
    puts("");*/
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {

        scanf("%d %d", &a, &b);
        if( b < a )
        {
            printf("Case %d: -1\n", caseno++);
            continue;
        }
        else if( a == b )
        {
            printf("Case %d: 0\n", caseno++);
            continue;
        }
        memset( lv, 0, sizeof(lv) );
        memset( flag, 0, sizeof(flag) );
        int x = bfs(a);
        printf("Case %d: %d\n", caseno++, x );
    }

    return 0;
}



