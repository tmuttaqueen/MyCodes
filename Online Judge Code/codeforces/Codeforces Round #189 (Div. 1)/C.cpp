#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

typedef tree < intl, null_type,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

const int mx = 111111;

intl a[mx], b[mx], dp[mx];
pii hull[mx], x[mx];
int c = 1;

void fix()
{
    //intl d = (hull[c].xx - hull[c-2].xx)*( hull[c-2].yy - hull[c-1].yy ) - (hull[c-1].xx - hull[c-2].xx)*( hull[c-2].yy - hull[c].yy );
    double dd = (double)(hull[c].xx - hull[c-2].xx)/( hull[c-2].yy - hull[c].yy ) - (double)(hull[c-1].xx - hull[c-2].xx)/( hull[c-2].yy - hull[c-1].yy );
    // what_is(d);
    while( c > 1 && dd < 0 )
    {
        c--;
        hull[c] = hull[c+1];
        //d = (hull[c].xx - hull[c-2].xx)*( hull[c-1].yy - hull[c].yy ) - (hull[c].xx - hull[c-1].xx)*( hull[c-2].yy - hull[c].yy );
         dd = (double)(hull[c].xx - hull[c-2].xx)/( hull[c-2].yy - hull[c].yy ) - (double)(hull[c-1].xx - hull[c-2].xx)/( hull[c-2].yy - hull[c-1].yy );
    }


    x[c].xx = (hull[c-1].xx - hull[c].xx)/( hull[c].yy - hull[c-1].yy );
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ ) cin >> a[i];
    for( int i = 0; i < n; i++ ) cin >> b[i];
    dp[0] = 0;
    hull[0].xx = 0; //c
    hull[0].yy = b[0]; //m
    x[0].xx = 0;
    x[0].yy = 0;
    for( int i = 1; i < n; i++ )
    {
        //for( int i = 0; i < c; i++ ) cout << x[i].xx << " " << x[i].yy << endl;
        //debug;
        pii *d = upper_bound( x, x + c, mp(a[i], (intl)mx) );
        d--;
        int ind = d - x;
        ind = x[ind].yy;
        intl ans = dp[ind] + a[i]*b[ind];
        //cout << i << " " << ans << endl;
        dp[i] = ans;
        hull[c].xx = dp[i];
        hull[c].yy = b[i];
        fix();
        x[c].yy = i;
        c++;
        //what_is( c );
    }
    cout << dp[n-1] << endl;
    return 0;
}




