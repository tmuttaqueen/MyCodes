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

int deg[M];
map<int, int>edge[M];
int par[M];
set<int>ss;
vector<int>ans;

int bfs( int u )
{
    int c = 0;
    queue<int>q;
    c++;
    ss.erase(u);
    q.push(u);
    while( !q.empty() )
    {
        int t = q.front();
        q.pop();
        vector<int>vec;
        for( auto x: ss )
        {
            if( edge[t].find(x) == edge[t].end() )
            {
                q.push(x);
                c++;
                vec.pb(x);
            }
        }
        for( int x: vec )
            ss.erase(x);
    }
    return c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m, a, b;
    cin >> n >> m;
    for( int i = 1; i <= n; i++ )
        ss.insert(i);
    for( int i = 0; i < m; i++ )
    {
        cin >> a >> b;
        deg[a]++;
        deg[b]++;
        edge[a][b] = 1;
        edge[b][a] = 1;
    }
    int c = 0;
    for( int i = 1; i <= n; i++ )
    {
        if( ss.find(i) != ss.end() )
        {
            c++;
            int a = bfs(i);
            ans.pb(a);
        }
    }
    sort( ans.begin(), ans.end() );
    cout << (int)ans.size() << endl;
    for( int x: ans )
        cout << x << " ";
    cout << endl;
    return 0;
}
