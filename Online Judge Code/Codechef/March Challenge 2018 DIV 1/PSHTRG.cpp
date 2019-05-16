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
const int M = 545678;
int lim = 64;
set<pii> tree[M];
int ara[M];

void init( int cn, int l, int r )
{
    if( l == r )
    {
        tree[cn].insert( mp( ara[l], l ) );\
        return;
    }
    int m = (l+r)/2, lft = cn*2;
    init( lft, l, m );
    init( lft+1, m+1, r );
    tree[cn].insert( tree[lft].begin(), tree[lft].end() );
    tree[cn].insert( tree[lft+1].begin(), tree[lft+1].end() );
    return ;
}

pii ov, nv; int ind;
void update( int cn, int l, int r )
{
    tree[cn].erase( ov );
    tree[cn].insert( nv );
    if( l == r ) return;
    int m = (l+r)/2;
    if( ind <= m )
        update( cn*2, l, m );
    else
        update( cn*2+1, m+1, r );
}

vector<intl> vec, v1, v2;

void merge_vec( vector<intl> &v1, vector<intl> &v2)
{
    int s1 = 0, s2 = 0;
    while(1)
    {
        if( vec.size() >= lim ) break;
        else if( s1 >= v1.size() && s2 >= v2.size() )  break;
        else if( s1 >= v1.size() )
        {
            vec.pb( v2[s2++] );
        }
        else if( s2 >= v2.size() )
        {
            vec.pb( v1[s1++] );
        }
        else if( v1[s1] < v2[s2] )
        {
            vec.pb( v2[s2++] );
        }
        else
            vec.pb(v1[s1++]);
    }
}

void query( int cn, int l, int r, int x, int y )
{
    if( r < x || l > y ) return;
    if( l >= x && r <= y )
    {
        v1.clear();
        v2.clear();
        auto it = tree[cn].end();
        int sz = tree[cn].size();
        it--;
        for( int i = 0; i < sz; i++ )
        {
            if( i >= lim ) break;
            v1.pb( (*it).xx );
            it--;
        }
        for( int i = 0; i < vec.size(); i++ )
        {
            v2.pb( vec[i] );
        }
        vec.clear();
        merge_vec(v1, v2);
        return;
    }
    int m = (l+r)/2;
    query( cn*2, l, m, x, y );
    query( cn*2+1, m+1, r, x, y );
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, q;
    cin >> n >> q;
    for( int i = 1; i <= n; i++ )
    {
        cin >> ara[i];
    }
    init( 1, 1, n );
    while(q--)
    {
        int c, x ,y;
        cin >> c >> x >> y;
        if( c == 1 )
        {
            ov = mp( ara[x], x );
            nv = mp( y, x );
            ara[x] = y;
            ind = x;
            update( 1, 1, n );
        }
        else
        {
            vec.clear();
            query( 1, 1, n, x, y );
            intl ans = 0;
            for( int i = 2; i < vec.size(); i++ )
            {
                if( vec[i-2] < vec[i-1] + vec[i] )
                {
                    ans = max( ans, vec[i-2] + vec[i-1] + vec[i] );
                }
            }
            cout << ans << endl;

            /*vector<intl>temp;
            for( int i = x; i <= y; i++ )
            {
                temp.pb( ara[i] );
            }
            sort( temp.begin(), temp.end() );
            reverse( temp.begin(), temp.end() );
            intl a = 0;
            for( int i = 2; i < min(40, (int)temp.size()); i++ )
            {
                if( temp[i-2] < temp[i-1] + temp[i] )
                {
                    a = max( a, temp[i-2] + temp[i-1] + temp[i] );
                }
            }
            cout << a << endl;*/
        }
    }
    return 0;
}
