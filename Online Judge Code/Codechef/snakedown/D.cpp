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

/// 0 _ based index
int n, m;
int parent[100005];
int deg[100005];
vector<pii>add[100005];
pii ara[200005];
int ans[100005];
int comp;

void pre_process(int v)  ///make every node their own parent
{
    for( int i = 0; i <= v; i++ )
        parent[i] = i;
}

int find_parent( int x ) ///find the parent of a node
{
    if( x == parent[x] )  // base_case: the node is a parent to itself
        return x;
    return parent[x] = find_parent( parent[x] ); // go to the top of parent tree make the tree level smaller
}

void union_( int x, int y )  ///merge two set via an edge between x and y
{
    int px = find_parent( x ); // returns 2
    int py = find_parent( y ); // returns 8
    if( px != py )  // chack if the two set is connected by a edge
    {
        parent[px] = py;  // merging the two set and node
        comp--;
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t;
    cin >> t;
    while(t--)
    {
        memset( deg, 0, sizeof deg );
        cin >> n >> m;
        for( int i = 0; i < m; i++ )
        {
            cin >> ara[i].xx >> ara[i].yy;
            deg[ ara[i].xx ]++;
            deg[ ara[i].yy ]++;
        }
        for( int i =0; i < m; i++ )
        {
            int r = min( deg[ ara[i].xx ], deg[ ara[i].yy ] );
            add[r].pb( ara[i] );
        }
        pre_process(n+1);
        comp = n;
        for( int i = n-1; i >= 0; i-- )
        {
            ans[i] = comp - 1;
            for( pii x: add[i] )
            {
                union_( x.xx, x.yy );
            }
        }
        for( int i = 0; i < n; i++ )
        {
            cout << ans[i] << " ";
            add[i].clear();
        }
        cout << endl;
    }

    return 0;
}

