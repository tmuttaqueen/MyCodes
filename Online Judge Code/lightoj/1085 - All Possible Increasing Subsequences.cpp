#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;
long long mod = 1000000007;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<intl, intl>

bool comp( pii a, pii b )
{
    if( a.xx == b.xx ) return a.yy < b.yy;
    return a.xx < b.xx;
}
intl tree[300015];

void update( int cn, int s, int e, int index, int val )
{
    if( index < s || index > e ) return;
    if( s == e )
    {
        tree[cn] = val%mod;
        return;
    }
    int mid = (s+e)/2;
    update( cn*2, s, mid, index, val );
    update( cn*2+1, mid+1, e,index, val );
    tree[cn] = (tree[cn*2] + tree[cn*2+1])%mod;
    return;
}

intl query( int cn, int s, int e, int qs, int qe )
{
    if( e < qs || s > qe ) return 0;
    if( e <= qe && s >= qs ) return tree[cn];
    int mid = (s+e)/2;
    intl s1 = query( cn*2, s, mid, qs, qe );
    intl s2 = query( cn*2+1, mid+1, e, qs, qe );
    return (s1+s2)%mod;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        intl n, a;
        cin >> n;
        vector<pii>vec;
        vec.pb({0,0});
        for( int i = 1; i <= n; i++ )
        {
            cin >> a;
            vec.pb({a,i});
        }
        sort( vec.begin() + 1, vec.end(), comp );
        intl val[n+1];
        memset( val, 0, sizeof(val) );
        memset( tree, 0, sizeof(tree) );
        val[vec[1].yy] = 1;
        update( 1, 1, n, vec[1].yy, 1 );
        map<intl,intl> mm;
        mm[vec[1].xx] = 1;
        for( int i = 2; i <= n; i++ )
        {
            intl sum, k = mm[vec[i].xx];
            sum = query( 1, 1, n, 1, vec[i].yy-1 );
            sum++;
            sum = (sum - k + mod)%mod;
            //if( sum != 1 )
                //debug;
            update( 1, 1, n, vec[i].yy, sum );
            val[vec[i].yy] = sum;
            mm[vec[i].xx] = (k + sum)%mod;
        }
        intl ans = 0;
        for( int i = 1; i <= n; i++ )
        {
            //what_is(val[i]);
            ans = (val[i] + ans)%mod;
        }
        cout << "Case " << caseno++ << ": " << ans << "\n";
    }

    return 0;
}



