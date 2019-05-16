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
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

int tree[6666666];
char lazy[6666666];
int ara[2222222];
string s;

void init( int cn, int s, int e )
{
    lazy[cn] = '0';
    if( s == e )
    {
        tree[cn] = ara[s];
        return;
    }
    int m = (s+e)/2;
    init(cn*2, s, m);
    init(cn*2+1, m+1, e);
    tree[cn] = tree[cn*2] + tree[cn*2+1];
    return;
}

char ttt( int cn )
{
    if( lazy[cn] == 'F' )
    {
        return 'E';
    }
    else if( lazy[cn] == 'E' )
    {
        return 'F';
    }
    else if( lazy[cn] == 'I' )
    {
        return '0';
    }
    return 'I';
}

void propagate( int cn, int s, int e )
{
    char t = lazy[cn];
    if( t == 'F' )
    {
        tree[cn] = e-s+1;
    }
    else if( t == 'E' )
    {
        tree[cn] = 0;
    }
    else
    {
        tree[cn] = e-s+1 - tree[cn];
    }
    if( s != e )
    {
        if( t == 'F' || t == 'E' )
            lazy[cn*2] = lazy[cn*2+1] = t;
        else
        {
            lazy[cn*2] = ttt(cn*2);
            lazy[cn*2+1] = ttt(cn*2+1);
        }
    }
    lazy[cn] = '0';
}

void update( int cn, int s, int e, int x, int y, char type )
{
    if( lazy[cn] != '0' )
    {
        propagate( cn, s, e );
    }
    if( e < x || s > y ) return;
    if( s >= x && e <= y )
    {
        lazy[cn] = type;
        propagate(cn,s,e);
        return;
    }
    int m = (s+e)/2;
    update( cn*2, s, m, x, y, type );
    update( cn*2+1, m+1, e, x, y, type );
    tree[cn] = tree[cn*2] + tree[cn*2+1];
}

int query( int cn, int s, int e, int x, int y )
{
    if( lazy[cn] != '0' )
    {
        propagate( cn, s, e );
    }
    if( e < x || s > y ) return 0;
    if( s >= x && e <= y )
    {
        return tree[cn];
    }
    int m = (s+e)/2;
    int a = query( cn*2, s, m, x, y );
    int b = query( cn*2+1, m+1, e, x, y );
    return a+b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int m, c = 1;
        cin >> m;
        ara[0] = 0;
        for( int i = 0; i < m; i++ )
        {
            int z;
            cin >> z;
            cin >> s;
            int l = s.length();
            for( int k = 0; k < z; k++ )
            {
                for( int j = 0; j < l; j++ )
                {
                    ara[c++] = s[j] - '0';
                }
            }
        }
        c--;
        //what_is(c);
        init( 1, 1, c );
        int q, qno = 1, x, y;
        char ch;
        cin >> q;
        cout << "Case " << caseno++ << ":" << endl;

        while(q--)
        {
            //scanf("%c %d %d\n", &ch, &x, &y);
            cin >> ch >> x >> y;
            x++;
            y++;
            if( ch == 'S' )
            {
                int d = query( 1, 1, c, x, y );
                cout << "Q" << qno++ << ": " << d << endl;
            }
            else
            {
                update( 1, 1, c, x, y, ch );
            }
        }
    }
    //debug;
    return 0;
}
