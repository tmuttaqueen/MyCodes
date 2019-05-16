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
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

vector<int>edge[1111111];
vector<int>g[1111111];
int col[1111111];
set<pii>deg;
vector<int>visit[1111111];
int done[1111111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m;
    cin >> n >> m;
    for( int i = 1; i <= n; i++ )
    {
        int a, b;
        cin >> a;
        while(a--)
        {
            cin >> b;
            g[i].pb(b);
        }
    }
    for( int i =1; i < n; i++ )
    {
        int a, b;
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    for( int i = 1; i <= n; i++ )
    {
        deg.insert( mp( -g[i].size(), i  ) );
    }
    int ans = 0;
    for( auto it = deg.begin(); it != deg.end(); it++ )
    {
        pii a = *it;
        int u = a.yy;
        //what_is(u);
        set<int>av;
        for( int v: g[u] )
        {
            if( col[v] != 0 )
            {
                av.insert( col[v] );
            }
        }
        int c = 1;
        for( int v: g[u] )
        {
            while( av.find(c) != av.end() )
                c++;
            if( col[v] == 0 )
            {
                col[v] = c;
                c++;
            }
        }
        ans = max(ans, c-1);
    }
    cout << ans << endl;
    for( int i = 1; i <= m; i++ )
    {
        if( col[i] == 0 ) col[i] = 1;
        cout << col[i] << " ";
    }
    cout << endl;

    return 0;
}




