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
const int SZ = 1000005, mod = 1000000007;

struct edge
{
    intl a, b, g, s;
};

int parent[222];
int tree;

void pre_process(int v)  ///make every node their own parent
{
    for( int i = 0; i < v; i++ )
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
    if( px != py ) // chack if the two set is connected by a edge
    {
        tree--;
        parent[px] = py;
    }  // merging the two set and node
    return;
}


edge ara[55555];
intl gg[55555], ss[55555];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m;
    cin >> n >> m;
    intl g, s;
    cin >> g >> s;
    pre_process(n+1);
    intl a,b;
    edge t;
    for( int i = 0; i < m; i++ )
    {
        cin >> t.a >> t.b >> t.g >> t.s;
        if( t.a == t.b )
        {
            i--;
            m--;
            continue;
        }
        t.g *= g;
        t.s *= s;
        ara[i] = t;
        gg[i] = t.g;
        ss[i] = t.s;
    }
    sort( ss, ss + m );
    sort( gg, gg + m );
    intl l1 = 0, r1 = m-1;
    intl ans = 2000000000000000006LL;
    while( l1 <= r1 )
    {
        intl m1 = (l1+r1)/2, f = 0;
        intl g = gg[m1];
        intl l2 = 0, r2 = m-1;
        while( l2 <= r2 )
        {
            intl m2 = (l2+r2)/2;
            intl s = ss[m2];
            tree = n;
            pre_process(n+1);
            for( int i = 0; i <  m; i++ )
            {
                if( ara[i].g <= g && ara[i].s <= s )
                {
                    union_( ara[i].a, ara[i].b );
                }
            }

            if( tree <= 1 )
            {
                if( s+g < ans )
                    f = 1;
                ans = min(ans, s+g );
                r2 = m2 - 1;
            }
            else
            {
                l2 = m2+1;
            }
        }
        if(f)
            r1 = m1 -1;
        else
            l1 = m1+1;

    }
    if( ans == 2000000000000000006LL )
        cout << -1 << endl;
    else
        cout << ans << endl;



    return 0;
}




