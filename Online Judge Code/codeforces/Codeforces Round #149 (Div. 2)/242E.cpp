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
const int M = 100005;

int tree[6*M][22], lazy[6*M], lim = 21, ara[M];

void propagate( int cn, int s, int e )
{
    if( s != e )
    {
        lazy[2*cn] ^= lazy[cn];
        lazy[2*cn+1] ^= lazy[cn];
    }
    for( int i = 0; i < lim; i++ )
    {
        if( lazy[cn]&(1<<i) )
        {
            tree[cn][i] = (e-s+1 - tree[cn][i]);
        }
    }
    lazy[cn] = 0;
}

void create( int cn, int s, int e )
{
    if( s == e )
    {
        for( int i = 0; i < lim; i++ )
        {
            tree[cn][i] = ((ara[s]&(1<<i))>0);
        }
        return ;
    }
    int m = (s+e)/2, l = cn*2, r = l+1;
    create( l, s, m);
    create( r, m+1, e );
    for( int i = 0; i < lim; i++ )
    {
        tree[cn][i] = tree[l][i] + tree[r][i];
    }
}

void update( int cn, int s, int e, int x, int y, int val )
{
    if( lazy[cn] )
        propagate(cn, s, e);
    if( s > y || e < x ) return;
    if( s>= x && e <= y )
    {
        lazy[cn] ^= val;
        propagate(cn, s, e);
        return;
    }
    int m = (s+e)/2, l = cn*2, r = l+1;
    update(l, s, m, x, y, val);
    update(r, m+1, e, x, y, val);
    for( int i = 0; i < lim; i++ )
    {
        tree[cn][i] = tree[l][i] + tree[r][i];
    }
}

intl query( int cn, int s, int e, int x, int y )
{
    if( lazy[cn] )
        propagate(cn, s, e);
    if( s > y || e < x ) return 0;
    if( s>= x && e <= y )
    {
        intl p = 1, ss = 0;
        for( int i = 0; i < lim; i++ )
        {
            ss += p*tree[cn][i];
            p *= 2;
        }
        //cout << "ok " << cn << " " << s << " " << e << " " << ss << endl;
        return ss;
    }
    int m = (s+e)/2, l = cn*2, r = l+1;
    intl a = query( l, s, m, x, y );
    intl b = query( r, m+1, e, x, y );
    return a+b;
}

void print( int cn, int s, int e )
{
    if( lazy[cn] )
        propagate(cn, s, e);
    if(s==e)
    {
        cout << "data: " << s << ": ";
        for( int i = 0; i < 5; i++ )
        {
            cout << tree[cn][i] << " ";
        }
        cout << endl;
        return ;
    }
    int m = (s+e)/2, l = cn*2, r = l+1;
    print(l,s,m);
    print(r,m+1, e);

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    for( int i =1; i <= n; i++ )
    {
        cin >> ara[i];
    }
    create(1,1,n);
    int q;
    cin >> q;
    for( int i = 1; i <= q; i++ )
    {
        int a;
        cin >> a;
        if(a==1)
        {
            int l, r;
            cin >> l >> r;
            cout << query(1,1,n,l,r) << endl;
        }
        else
        {
            int l, r, x;
            cin >> l >> r >> x;
            update(1,1,n,l,r, x);
        }
        //print(1,1,n);
    }

    return 0;
}
