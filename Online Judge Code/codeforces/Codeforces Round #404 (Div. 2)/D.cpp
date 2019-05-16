#include <bits/stdc++.h>

///#include <ext/pb_ds/assoc_container.hpp>
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
#define double      long double

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

const int mod = 1000000007;

intl tree[8*100005], val[8*100005];

void lazy( int cn, int s, int e )
{
    int l = cn*2, r = cn*2+1;
    tree[cn] = (tree[cn]*val[cn])%mod;
    val[l] = (val[l]*val[cn])%mod;
    val[r] = (val[r]*val[cn])%mod;
    val[cn] = 1;
}

void init( int cn, int s, int e )
{
    if( s == e ){
        tree[cn] = 1;
        return;
    }
    int m = (s+e)/2;
    init( cn*2, s, m );
    init( cn*2+1, m+1, e );
    tree[cn] = tree[cn*2] + tree[cn*2+1];
}

void update( int cn, int s, int e, int x, int y )
{
    lazy(cn, s, e);
    if( e < x || s > y ) return;
    if( s >= x && e <= y )
    {
        val[cn] = ( val[cn]*2 )%mod;
        lazy( cn, s, e );
        return;
    }
    int m = (s+e)/2;
    update( cn*2, s, m, x, y );
    update( cn*2+1, m+1, e ,x,y );
    tree[cn] = (tree[cn*2] + tree[cn*2+1])%mod;
    //cout << "cn " << cn << " tree[cn ] "<< tree[cn] << endl;
}

intl query( int cn, int s, int e, int x, int y  )
{
    lazy(cn, s, e);
    if( e < x || s > y ) return 0;
    if( s >= x && e <= y )
    {
        lazy( cn, s, e );
        return tree[cn];
    }
    int m = (s+e)/2;
    intl l = query( cn*2, s, m, x, y );
    intl r = query( cn*2+1, m+1, e ,x,y );
    return (l+r)%mod;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    for( int i = 0; i <= 8*100000; i++ )
    {
        val[i] = 1;
        tree[i] = 1;
    }
    string s;
    cin >> s;
    int n = 0, num = 0;
    intl ans = 0;
    for( int i = 0; i < s.length(); i++ )
    {
        if( s[i] == '(' )
            num++;
    }
    if( num == 0 )
    {
        cout << 0 << endl;
        return 0;
    }
    init( 1, 1, num );
    for( int i = 0; i < s.length(); i++ )
    {
        if( s[i] == '(' )
            n++;
        else
        {
            intl d = query( 1, 1, num, 1, n );
            what_is(d);
            ans = (ans + d)%mod;
            update( 1, 1, num, 2, n );
        }
    }
    cout << ans << endl;
    return 0;
}




