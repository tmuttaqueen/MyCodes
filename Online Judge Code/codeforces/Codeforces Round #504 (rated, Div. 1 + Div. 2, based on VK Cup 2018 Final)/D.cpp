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

int ara[M], fl[M];

int st[M], en[M];

vector<pii>vec;
int tree[5*M], lazy[5*M];

void propagate( int cn, int s, int e )
{
    if( s != e )
    {
        lazy[cn*2] = lazy[cn*2+1] = lazy[cn];
    }
    tree[cn] = lazy[cn];
    lazy[cn] = 0;
}

void update(int cn, int s, int e, int x, int y, int v)
{
    if( lazy[cn] != 0 )
        propagate(cn, s, e);
    if( e < x || s > y ) return ;
    if( s >= x && e <= y )
    {
        lazy[cn] = v;
        propagate(cn, s, e);
        return ;
    }

    int m = (s+e)/2, l = cn*2;
    update(l, s, m, x, y, v);
    update(l+1, m+1, e, x, y, v);
    tree[cn] = min( tree[cn*2], tree[cn*2+1] );
    return;

}

int query( int cn, int s, int e, int x, int y )
{
   // cout << s << " " << e << endl;
    if( lazy[cn] != 0 )
        propagate(cn, s, e);
    if( e < x || s > y ) return 1e9;
    if( s >= x && e <= y )
    {
        return tree[cn];
    }
    int m = (s+e)/2, l = cn*2;
    int a = query(l, s, m, x, y);
    int b = query(l+1, m+1, e, x, y);
    return min(a, b);
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
        fl[ ara[i] ] = 1;
    }
    if( fl[q] == 0 )
    {
        for( int i = 1; i <= n; i++ )
        {
            if( ara[i] == 0 )
            {
                int j ;
                for( j = i; j <= n; j++ )
                {
                    if( ara[j] != 0 ) break;
                }
                for( int k = i; k < j; k++ )
                {
                    ara[k] = q;
                    fl[q] = 1;
                }
                break;
            }
        }
    }

    /*int d = q;
    if( ara[1] == 0 )
    {
        for( int i = q; i>= 1; i-- )
        {
            if( fl[i] == 0 )
            {
                d = i-1;
                int j = 1;
                while( ara[j] == 0 )
                {
                    ara[j] = i;
                    j++;
                }
                break;
            }
        }
    }

    if( ara[n] == 0 )
    {
        for( int i = d; i>= 1; i-- )
        {
            if( fl[i] == 0 )
            {
                int j = n;
                while( ara[j] == 0 )
                {
                    ara[j] = i;
                    j--;
                }
                break;
            }
        }
    }*/

    for( int i = 1; i <= n; i++ )
    {
        if( ara[i] != 0 && st[ ara[i] ] == 0 )
            st[ ara[i] ] = i;
    }
    for( int i = n; i >= 1; i-- )
    {
        if( ara[i] != 0 && en[ ara[i] ] == 0 )
            en[ ara[i] ] = i;
    }

    if( st[q] == 0 && en[q] == 0 )
    {
        cout << "NO" << endl;
        return 0;
    }

    for( int i = 1; i <= n; i++ )
    {
        if( ara[i] != 0 )
            update( 1, 1, n, i, i, ara[i] );
        else
            update( 1, 1, n, i, i, 100000000 );
    }

    for( int i = 1; i <= q; i++ )
    {
        if( st[i] != 0 && en[i] != 0 )
        {
            //cout << i << ' ' << st[i] << " " << en[i] << endl;
            int a = query( 1, 1, n, st[i], en[i] );
            //cout << a << endl;
            if( a < i )
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }


    for( int i = 1; i <= n; i++ )
    {
        if( ara[i] == 0 && ara[i-1] != 0 )
            ara[i] = ara[i-1];
    }

    for( int i = n; i >= 1; i-- )
    {
        if( ara[i] == 0 && ara[i+1] != 0 )
            ara[i] = ara[i+1];
    }
    cout << "YES" << endl;
    for( int i = 1; i <= n; i++ )
        cout << ara[i] << " ";
    cout << endl;
    return 0;
}
