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

vector<int>edge[M];
int deg[M], temp[M], v, e, x, l;
int flag[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int a, b;
    cin >>  v >> e >> x >> l;
    for( int i = 0; i < e; i++ )
    {
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
        deg[a]++;
        deg[b]++;
        //temp[a]++;
        //temp[b]++;
    }

    queue<int> q;
    flag[l] = 1;
    q.push(l);
    while( !q.empty() )
    {
        int u = q.front();
        q.pop();
        for( int v: edge[u] )
        {
            if( flag[v] ) continue;
            temp[v]++;
            if( temp[v]*2 >= deg[v] )
            {
                flag[v] = 1;
                q.push(v);
            }
        }
    }
    if( flag[x] ) cout << "leave" << endl;
    else cout << "stay" << endl;

    return 0;
}
