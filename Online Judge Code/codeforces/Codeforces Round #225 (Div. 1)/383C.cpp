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

///1D BIT O(logn)
struct BIT1D
{
    int mx;
    vector<int>bit;
    void init( int n = 1002 )
    {
        mx = (n+2);
        bit.resize(mx,0);
    }
    void update( int x, int val ) //add val to index x
    {
        while( x <= mx )
        {
            bit[x] += val;
            x += (x&(-x));
        }
    }

    int query( int x ) //sum from 1 to x (inclusive)
    {
        int sum = 0;
        while( x > 0 )
        {
            sum += bit[x];
            x -= (x&(-x));
        }
        return sum;
    }
};

int st0[M], en0[M], st1[M], en1[M], sst0[M], sst1[M], een0[M], een1[M];
int szero, sone, val[M], level[M];
BIT1D bit0, bit1;
vector<int>edge[M];

void dfs( int u, int p, int l )
{
    level[u] = l;
    if( l%2 )
    {
        st1[u] = ++sone;
        sst1[u] = szero+1;
        //bit1.update( sone, val[u] );
    }
    else
    {
        st0[u] = ++szero;
        sst0[u] = sone+1;
        //bit0.update(szero, val[u]);
    }
    for( int v: edge[u] )
    {
        if( v == p ) continue;
        dfs(v, u, l+1);
    }
    if( l%2 )
    {
        en1[u] = sone;
        een1[u] = szero;
    }
    else
    {
        en0[u] = szero;
        een0[u] = sone;
    }


}

void print( int n)
{
    cout << "print all" << endl;
    for( int u = 1; u <= n; u++ )
    {
        if( level[u] % 2 )
        {
            cout << bit1.query( st1[u] ) << endl; //- bit1.query( st1[u]-1 ) << endl;
        }
        else
        {
            cout << bit0.query( st0[u] ) << endl;//- bit0.query( st0[u]-1 ) << endl;
        }
    }
    cout << "end print" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n,m, a, b;
    cin >> n >> m;
    bit0.init(n);
    bit1.init(n);
    for( int i = 1; i <= n; i++ )
        cin >> val[i];
    for( int i = 1; i < n; i++ )
    {
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    dfs(1,-1, 0);
    /*debug;
    for( int i = 1; i <= n; i++ )
    {
        cout << i << " " << level[i] << " ";
        if( level[i]%2 )
        {
            cout << st1[i] << " " << en1[i] << " " << sst1[i] << " " << een1[i] << endl;
        }
        else
        {
            cout << st0[i] << " " << en0[i] << " " << sst0[i] << " " << een0[i] << endl;
        }
    }
    print(n);*/
    while(m--)
    {
        int x, u, v;
        cin >> x;
        if( x == 1 )
        {
            cin >> u >> v;
            if( level[u]%2 )
            {
                bit1.update( st1[u], v );
                bit1.update( en1[u] +1 , -v );
                bit0.update( sst1[u], -v );
                bit0.update( een1[u]+1, v  );
            }
            else
            {
                bit0.update( st0[u], v );
                bit0.update( en0[u] + 1, -v );
                bit1.update( sst0[u], -v );
                bit1.update( een0[u]+1, v );
            }
            //print(n);
        }
        else
        {
            cin >> u;
            if( level[u] % 2 )
            {
                cout << val[u] + bit1.query( st1[u] ) << endl;
            }
            else
            {
                cout << val[u] + bit0.query( st0[u] ) << endl;
            }
        }
    }
    return 0;
}
