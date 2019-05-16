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
#define pii         pair<intl, intl>
#define piii        pair<pii, int>
//#define double      long double
typedef struct touple
{
    int xx,yy,zz;
    touple( int x = 0, int y = 0, int z = 0 ){xx=x; yy=y; zz=z;}
    bool operator<(const touple &a )
    {
        if( xx == a.xx )
		{
            if( yy == a.yy )
                return zz < a.zz;
            return yy < a.yy;
        }
        return xx<a.xx;
    }

} tii;
//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 145678;
intl n, s, a, b, x, d = 0, lft;
pii ara[M];
intl sum;

intl check( intl lim )
{
    if( lim <= 0 ) return 0;
    intl ss = 0;
    //what_is(lim);
    for( int i = 0; i < n; i++ )
    {
        if( ara[i].xx < 0 )
            lim -= lft;
        if( lim <= 0 )
            break;
        if( ara[i].xx >= 0 && ara[i].yy <= lim )
        {
            ss += ara[i].xx*ara[i].yy;
            lim -= ara[i].yy;
        }
        else if( ara[i].xx >= 0 && ara[i].yy > lim )
        {
            ss += ara[i].xx*lim;
            lim = 0;
        }
        else if( ara[i].xx < 0 && ara[i].yy <= lim )
        {
            ss += ara[i].xx*ara[i].yy;
            lim -= ara[i].yy;
        }
        else if( ara[i].xx < 0 && ara[i].yy > lim )
        {
            ss += ara[i].xx*lim;
            lim = 0;
        }
    }
    //what_is(ss);
    return ss;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;

    cin >> n >> s;
    for( int i = 0; i < n; i++ )
    {
        cin >> x >> a >> b;
        d += x;
        sum += x*b;
        ara[i].xx = a-b;
        ara[i].yy = x;
    }
    intl tot = d/s;
    if( d%s )
        tot++;
    lft = tot*s-d;
    intl ans = 0;
    sort( ara, ara+n );
    reverse( ara, ara+n );
    //for( int i = 0; i < n; i++ ) cout << "-- " << ara[i].xx << " " << ara[i].yy <<endl;
    intl l = 0, r = tot;
    //what_is(sum);
    int cnt = 0;
    while(l <= r)
    {
        intl m = (l+r)/2;
        intl s1 = check(m*s), s2 = check( (m+1)*s );
        if( s1 < s2 )
        {
            l = m+1;
            ans = max( ans, s2 );
        }
        else
        {
            r = m;
            ans = max(ans, s1);
        }
        cnt++;
        if(cnt > 100) break;
    }

    /*while(l<=r)
    {
        //cout << l << " " << r << endl;
        //intl m1 = l+(l+r)/3, m2 = r- (l+r)/3;
       //intl s1 = check( m1*s ), s2 = check( m2*s );
        if( s1 < s2 )
        {
            l = m1+1;
            ans = max(ans,s2);
        }
        else if( s1 > s2 )
        {
            r = m2-1;
            ans = max(s1,ans);
        }
        else
        {
            ans = max(s1,ans);
            l = m1+1;
            r = m2-1;
        }
        //cout << m1 << " " << s1 << " -- " << m2 << " " << s2 << endl;
    }*/




    cout << sum+ans << endl;

    return 0;
}
