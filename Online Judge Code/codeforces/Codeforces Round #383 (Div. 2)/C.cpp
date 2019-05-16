#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

int par, x;
vector<int>edge[105];
int in[105], out[105];
int vis[105];

void dfs( int u )
{
    if( vis[u] == 1 )
        return;
    vis[u] = 1;
    if( x != 0 && u == par )
        return;
    x++;
    for( int v: edge[u])
    {
        //what_is(v);
        dfs(v);
    }
}

intl gcd( intl a, intl b )
{
    if( b == 0) return a;
    else return gcd(b,a%b);
}

intl lcm( intl a, intl b )
{
    return a*b/gcd(a,b);
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n,a;
    cin >> n;
    for( int i = 1; i <= n; i++ )
    {
        cin >> a;
        edge[i].pb(a);
        out[i]++;
        in[a]++;
    }
    //debug;
    intl ans = 1;
    for( int i = 1; i <= n; i++ )
    {
        if( in[i] != 1 || out[i] != 1 )
        {
            cout << -1 << endl;
            return 0;
        }
    }
    //debug;
    for( int i = 1; i <= n ; i++ )
    {
        par = i;
        x = 0;
        if( vis[i] == 0 )
        {
            dfs(i);
            //what_is(i);
            if(x%2 == 0)
                x/=2;
            ans = lcm(ans,x);
        }

    }
    cout << ans << endl;
    return 0;
}




