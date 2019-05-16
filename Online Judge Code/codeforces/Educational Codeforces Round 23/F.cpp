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
const int SZ = 1200005, mod = 1000000007;
//0 - all o, 1 - all 1, 2 - swap

struct data
{
    int t;
    intl l, r;
};

data ara[111111];
intl temp[311111];
map<intl, intl>mm;
intl rev[SZ];
int tree[SZ];
vector<int>lazy[SZ];

void propagate( int cn, int l, int r )
{
    for( int t: lazy[cn] )
    {
        //int t = lazy[cn].front();
        //lazy[cn].pop();
        if( l != r )
        {
            if( t == 0 || t == 1 )
            {
                lazy[cn*2].clear();
                lazy[cn*2+1].clear();
            }
            lazy[cn*2].pb(t);
            lazy[cn*2+1].pb(t);
        }
        if( t == 0 )
        {
            tree[cn] = 0;
        }
        else if( t == 1 )
        {
            tree[cn] = r-l+1;
        }
        else
        {
            tree[cn] = r - l + 1 - tree[cn];
        }
    }
    lazy[cn].clear();

}

void update( int cn, int l, int r, int x, int y, int type )
{
    if( !lazy[cn].empty() )
    {
        propagate( cn, l, r );
    }
    if( l > y || r < x )
        return;
    if( l >= x && r <= y )
    {
        if( type == 0 || type == 1 )
            lazy[cn].clear();
        lazy[cn].pb( type );
        propagate(cn, l, r);
        return;
    }
    int m = (l+r)/2;
    update( cn*2, l, m, x, y, type );
    update( cn*2+1, m+1, r, x, y, type );
    tree[cn] = tree[cn*2] + tree[cn*2+1];
    return;
}

int query( int cn, int l, int r )
{
    int m = (l+r)/2;
    if( !lazy[cn].empty() )
    {
        propagate( cn, l, r );
    }
    if(l != r && !lazy[2*cn].empty() )
    {
        propagate( 2*cn, l, m );
    }
    if( l != r && !lazy[2*cn+1].empty() )
    {
        propagate( 2*cn+1, m+1, r );
    }
    if( l == r )
    {
        return l;
    }

    if( tree[cn*2] < m -l + 1 )
    {
        return query( cn*2, l, m );
    }
    else
    {
        return query( cn*2+1, m+1, r );
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout << int('T' - 'A') << " " << int('M'-'A');
    //filein;
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i].t >> ara[i].l >> ara[i].r;

        temp[i*3] = ara[i].l;
        temp[i*3+1] = ara[i].r;
        temp[i*3+2] = ara[i].r+1;

        //temp[i*2] = ara[i].l;
        //temp[i*2+1] = ara[i].r;

        if( ara[i].t == 2 )
            ara[i].t = 0;
    }
    temp[3*n] = 1;
    sort( temp, temp + 3*n+1 );
    int c = 1;
    for( int i = 0 ; i <= 3*n; i++ )
    {
        if( mm[ temp[i] ] == 0 )
        {
            mm[ temp[i] ] = c++;
            rev[c-1] = temp[i];
        }
    }
    intl mx = c-1;
    for( int i = 0; i < n; i++ )
    {
        ara[i].l = mm[ ara[i].l ];
        ara[i].r = mm[ ara[i].r ];
    }
    //what_is(mx);
    /*for( int i = 0; i < n; i++ )
    {
        cout << ara[i].t << ' ' << ara[i].l << " " << ara[i].r << endl;
    }*/
    //cout << 1 << endl << 3 << endl << 1 << endl;
    //return 0;

    for( int i = 0; i < n; i++ )
    {
        update( 1, 1, mx, ara[i].l, ara[i].r, ara[i].t );
        intl l = 1, r = mx, ans = query( 1, 1, mx );
        cout << rev[ans] << endl;
    }
    //while(1);
    return 0;
}




