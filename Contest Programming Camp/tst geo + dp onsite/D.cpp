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
#define debug       cout << "Yes" << endl;
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
int n;
int ara[111111], dp1[111111], dp2[111111], temp[111111];
int tree[4*11111], c;
map<int,int>mm;

void update( int cn, int s, int e, int x, int v )
{
    if( x < s || x > e )
        return;
    if( s == x && s == e )
    {
        tree[cn] = max( tree[cn], v );
        return;
    }
    int m = (s+e)/2;
    update( cn*2, s, m, x, v );
    update( cn*2+1, m+1, e, x, v );
    tree[cn] = max( tree[cn*2], tree[cn*2+1] );
    return;
}

int query( int cn, int s, int e, int x, int y )
{
    if( x > y ) return -1;
    if( y < s || x > e )
        return -1;
    if( s >= x && e <= y )
    {
        return tree[cn];
    }
    int m = (s+e)/2;
    int a = query( cn*2, s, m, x, y );
    int b = query( cn*2+1, m+1, e, x, y );
    return max(a,b);
}



void solve( int vec[], int ans[] )
{
    memset( tree, -1, sizeof tree);
    ans[0] = 0;
    update( 1, 1, c, vec[1], 0 );
    for( int i = 2; i <= n; i++ )
    {
        int a = query( 1, 1, c, 1, vec[i]-1 );
        ans[i] = a +1;
        update( 1, 1, c, vec[i], a+1 );
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    while(cin >> n)
    {
        mm.clear();
        c = 1;

        for( int i =  1; i <= n; i++ )
        {
            cin >> ara[i];
            temp[i] = ara[i];
        }
        sort( temp+1, temp+n+1 );
        for( int i =  1; i <= n; i++ )
        {
            if( mm[ temp[i] ] == 0 )
            {
                mm[ temp[i] ] = c++;
            }
        }
        for( int i =  1; i <= n ;i++ )
        {
            ara[i] = mm[ ara[i] ];
        }
        solve( ara, dp1 );
        reverse( ara+1, ara + n+1 );
        solve( ara, dp2 );
        int ans = 1;
        for( int i = 1; i <= n; i++ )
        {
            //cout << dp1[i] << " ";
            ans = max( ans, 2*min( dp1[i], dp2[n-i+1] )+1 );
        }
        cout << ans << endl;

    }
    return 0;
}
