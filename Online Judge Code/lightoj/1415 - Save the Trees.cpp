#include <bits/stdc++.h>

using namespace std;

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
#define pii         pair<intl, intl>
#define piii        pair<pii, int>
#define double      long double

intl num[200005], height[200005], pos[200005], temp[200005];
pii tree[4*200005],  dpt[4*400005];
long long dp[200005];

void update( int cn, int s, int e, intl x, long long val, int a )
{
    if( s > x || e < x ) return;
    if( s == e )
    {
        if( a == 0 )
            tree[cn] = mp( val, x );
        else
        {
            dpt[cn] = mp(val, x);
            //cout << "sgt "  << x << endl;
        }

        return;
    }
    int m = (s+e)/2;
    update( cn*2, s, m, x, val, a );
    update( cn*2+1, m+1, e, x, val, a );
    if( a == 0 )
        tree[cn] = max( tree[2*cn], tree[cn*2+1] );
    else
    {
        dpt[cn] = min( dpt[2*cn], dpt[cn*2+1] );
        //cout << "sgt "  << x << " " << dpt[cn].xx << endl;
    }

    return;
}

pii query( int cn, int s, int e, int i, int j, int a)
{
    if( a == 1 && i == 0 ) return mp(0,0);
    if( i > e || j < s )
    {
        if( a == 0 )
            return mp(-1,0);
        else
            return mp( 1000000000000000LL, 0 );
    }
    if( s >= i && e <= j )
    {
        if( a == 0 )
            return tree[cn];
        else
        {
            //cout << "sgt "  << dpt[cn].xx << endl;
            return dpt[cn];
        }

    }
    int m = (s+e)/2;
    if( a == 0 )
        return max( query(cn*2, s, m, i, j, a), query( cn*2+1, m+1, e, i, j, a ) );
    else
    {
        pii temp = min( query(cn*2, s, m, i, j, a), query( cn*2+1, m+1, e, i, j, a ) );
        //cout << "sgt "  << temp.xx << endl;
        return temp;
    }

}


int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while( t-- )
    {
        int n;
        cin >> n;
        for( int i = 1; i <= n; i++ )
        {
            //cin >> num[i] >> height[i];
            scanf("%lld %lld", &num[i], &height[i]);
            //cout << num[i] << " " << height[i] << endl;;
        }
        //debug;
        memset( temp, 0 ,sizeof temp );
        memset( tree, 0, sizeof tree );
        memset( dpt, 60, sizeof dpt );
        memset( dp, 0, sizeof dp );
        pos[0] = 0;
        for( int i = 1; i <= n; i++  )
        {
            pos[i] = max( pos[i-1], temp[num[i]] );
            temp[num[i]] = i;
        }
        for( int i = 1; i <= n; i++ )
        {
            //cout << pos[i] << ' ';
            //if( i == n ) cout << endl;
        }

        //for( int i = 1; i < 20; i++ ) cout << dpt[i].xx << endl;
        dp[1] = height[1];
        update( 1, 1, n, 1, height[1], 0 );
        //update( 1, 1, n, 0, 0, 1 );
        update( 1, 1, n, 1, dp[1], 1 );
        pii tt = query( 1, 1, n, 1, 1, 1 );
        //cout << "test " << tt.xx << " " << tt.yy << endl;
        for( int i = 2; i<= n; i++ )
        {
            dp[i] = 1000000000000000LL;
            update( 1, 1, n, i, height[i], 0 );
            pii a = query( 1, 1, n, pos[i]+1, i, 0 ), b;
            int ss = pos[i];
            while( a.yy != i )
            {
                b = query( 1, 1, n, ss, a.yy-1 , 1 );
                //cout << " a.xx " << a.xx << " b.xx " << b.xx << endl;
                dp[i] = min( dp[i], (long long)a.xx+b.xx  );
                ss = a.yy;
                a = query( 1, 1, n, ss+1, i, 0 );
                //what_is(dp[i]);
            }
            //cout << ss << " " << a.yy - 1<<endl;
            b = query( 1, 1, n, ss, a.yy-1 , 1 );
            //cout << " a.xx " << a.xx << " b.xx " << b.xx << endl;
            dp[i] = min( dp[i],  (long long)a.xx + b.xx );
            //what_is(dp[i]);
            //debug;
            update( 1, 1, n, i, dp[i], 1 );
        }

        cout << "Case " << caseno++ << ": " << dp[n] << endl;
    }

    return 0;
}




