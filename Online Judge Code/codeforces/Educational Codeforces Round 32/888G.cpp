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

int used[M], ara[M];

namespace TRIE
{
struct node
{
    int cnt;
    int l, r;
};
const int LEN = 3, MAX = 200005;
node ara[(LEN+1)*MAX];
vector<int>ind[(LEN+1)*MAX];
int TOTAL;

void init( int num = MAX )
{
    TOTAL = 1;
    for( int i = 1; i <= LEN*num; i++ )
    {
        ara[i].l = ara[i].r = -1;
        ara[i].cnt = 0;
    }
}
int create()
{
    TOTAL++;
    ara[TOTAL].l = ara[TOTAL].r = -1;
    ara[TOTAL].cnt = 0;
    return TOTAL;
}
void insert( int n, int Index, int cur = 1 )
{
    for( int i = LEN-1; i >= 0; i-- )
    {
        cout << cur << endl;
        ara[cur].cnt++;
        int d = n&(1<<i);
        if(d)
        {
            if( ara[cur].r == -1 ) ara[cur].r = create();
            cur = ara[cur].r;
        }
        else
        {
            if( ara[cur].l == -1 ) ara[cur].l = create();
            cur = ara[cur].l;
        }
    }
    cout << cur << endl;
    ara[cur].cnt++;
    ind[cur].push_back(Index);
}
void update( int n, int Index, int cur = 1 )
{
    for( int i = LEN-1; i >= 0; i-- )
    {
        ara[cur].cnt--;
        int d = n&(1<<i);
        if(d)
        {
            if( ara[cur].r == -1 ) ara[cur].r = create();
            cur = ara[cur].r;
        }
        else
        {
            if( ara[cur].l == -1 ) ara[cur].l = create();
            cur = ara[cur].l;
        }
    }
    ara[cur].cnt--;
    //ind[cur].pop_back();
}
int query( int n, int cur = 1 )
{
    cout <<"n is " << n << endl;
    for( int i = LEN-1; i >= 0; i-- )
    {
        cout << "cur is " << cur << endl;
        int d = n&(1<<i);
        if(d )
        {
            if( ara[cur].r == -1 ) cur = ara[cur].l;
            else if( ara[cur].l == -1 ) cur = ara[cur].r;
            else if( ara[ ara[cur].r ].cnt <= 0 ) cur = ara[cur].l;
            else cur = ara[cur].r;
        }
        else
        {
            if( ara[cur].l == -1 ) cur = ara[cur].r;
            else if( ara[cur].r == -1 ) cur = ara[cur].l;
            else if( ara[ ara[cur].l ].cnt <= 0 ) cur = ara[cur].r;
            else cur = ara[cur].l;
        }
    }
    cout << "cur is " << cur << endl;
    if( ind[cur].size() <= 0 )
    {
        cout << "dfuq" << endl;
    }
    int v = ind[cur][ ind[cur].size()-1 ];
    return v;
}
void clear()
{
    delete[] ara;
}
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    filein;
    int n;
    cin >> n;
    //debug;
    TRIE::init();
    for( int i = 1; i <= n; i++ )
    {
        cin >> ara[i];
        TRIE::insert( ara[i], i );
    }
    for( int i = 1; i <= 12; i++ ) cout << i << " cnt " << TRIE::ara[i].cnt << endl;
    /*int q;
    cin >> q;
    while(q--)
    {
        int a, v, i;
        cin >> a >> v >> i;
        if(  a == 0)
            TRIE::update( v, i );
        else
        {
            cout << TRIE::query( v ) << endl;
        }
    }*/
    priority_queue< pair<int, pair<int,int> > >pq;
    intl ans = 0;
    TRIE::update( ara[1], 1 );
    for( int i = 1; i <= 12; i++ ) cout << i << " cnt " << TRIE::ara[i].cnt << endl;
    int d = TRIE::query( ara[1] );
    pq.push( mp( -(ara[d]^ara[1]), mp( 1, d ) ) );
    for( int i = 1; i < n; i++ )
    {
        pair<int, pair<int,int> > a = pq.top();
        int u = a.yy.xx, v = a.yy.yy, w = -a.xx;
        cout << u << " " << v << " " << w << endl;
        ans += w;
        pq.pop();
        TRIE::update( ara[v], v );
        for( int i = 1; i <= 12; i++ ) cout << i << " cnt " << TRIE::ara[i].cnt << endl;
        debug;
        int d = TRIE::query( ara[u] );
        cout <<u << " -> " << d << " " << ara[d] << endl;
        pq.push( mp( -( ara[u]^ara[d] ), mp( u, d ) ) );
        debug;
        d = TRIE::query( ara[v] );
        cout << v << " -> " << d << " " << ara[d] << endl;
        pq.push( mp( -( ara[v]^ara[d] ), mp( v, d ) ) );
    }
    cout << ans << endl;
    return 0;
}
