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

const int mx = 100005;
vector<int>an[mx];

void init()
{
    for( int i = 1; i < 20; i++ )
    {
        for( int j = 1; j <= 100000; j++ )
        {
            an[j].pb( an[an[j][i-1]][i-1] );
            //cout << " i " << i << " j " << j << endl;
        }
    }
}

void add( int u, int v )
{
    an[v].clear();
    an[v].pb(u);
    for( int i = 1; i < 20; i++ )
    {
        an[v].pb( an[an[v][i-1]][i-1] );
    }
}

int query( int x, int k )
{
    if( k == 0 )
        return x;
    if( k == 1 )
        return an[x][0];
    int a = 1<<19, p = 19;
    while( a > k )
    {
        a/=2;
        p--;
    }
    k = k-a;
    //what_is(k);
    return query( an[x][p], k );
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int p;
        scanf("%d", &p);
        for( int i = 0; i < 20; i++ ) an[0].pb(0);
        for( int i = 1; i < mx; i++ ) an[i].pb(0);
        for( int i = 0; i < p; i++ )
        {
            int a, b;
            scanf("%d %d", &a, &b);
            an[a][0] = b;
        }
        init();
        int q;
        scanf("%d", &q);
        for( int i = 0; i < q; i++ )
        {
            int a, b, c;
            scanf("%d", &a);
            if( a == 0 )
            {
                scanf("%d %d", &a, &b);
                add(a, b);
            }
            else if( a == 1 )
            {
                scanf("%d", &b);
                an[b].clear();
            }
            else
            {
                int ans;
                scanf("%d %d", &a, &b);
                if( an[a].size() == 0 )
                    ans = 0;
                else
                    ans = query( a, b );
                printf("%d\n", ans);
            }
        }
        for( int i = 0; i <mx; i++ ) an[i].clear();
    }

    return 0;
}



