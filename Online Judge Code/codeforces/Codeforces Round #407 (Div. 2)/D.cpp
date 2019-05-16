#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

typedef tree < intl, null_type,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

vector<int>edge[1111111];
int fl[1111111], c = 0;

void dfs( int u )
{
    //what_is(u);
    fl[u] = 1;
    c++;
    //what_is(c);
    for( int v: edge[u] )
    {
        if( !fl[v] )
            dfs(v);
    }
}

intl normal, loop;
unordered_set<int>ss;


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, m;
    cin >> n >> m;
    for( int i = 0 ; i < m; i++ )
    {
        int a, b;
        cin >>a >> b;
        ss.insert(a);
        ss.insert(b);
        if( a != b )
        {
            edge[a].pb(b);
            edge[b].pb(a);
            normal++;
        }
        else
            loop++;
    }
    int ll = ss.size(), p = 0;
    //what_is(ll);
    for( int i = 1; i <= n; i++ )
    {
        if( fl[i] == 0 )
        {
            dfs(i);
            //what_is(c);
            if( c == 1 || c == ll )
            {
                if( c == 1 )
                    p++;
                c = 0;
            }
            else
            {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    if( p == n )
    {
        cout << 0 << endl;
        return 0;
    }

    intl ans = 0;
    for( int i = 1; i <= n; i++ )
    {
        intl d = edge[i].size();
        //cout << i << " " << val[i] << endl;
        ans += d*(d-1)/2;
    }
    ans += loop*(loop-1)/2 + loop*normal;
    cout << ans << endl;

    return 0;
}



