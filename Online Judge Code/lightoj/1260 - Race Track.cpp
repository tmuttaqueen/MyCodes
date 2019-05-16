#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("fuck\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double
#define eps         0.000000001
#define sq(x)       ((x)*(x))

pii add( pii a, pii b ) //a+b
{
    return mp(a.xx+b.xx, a.yy+b.yy);
}

pii sub( pii a, pii b ) //a-b
{
    return mp(a.xx-b.xx, a.yy-b.yy);
}

double portion( pii a, pii b ) //portion of b on a
{
    double d = sqrt(a.xx*a.xx+a.yy*a.yy);
    return (double)(a.xx*b.xx+a.yy*b.yy)/d;
}

bool is_90( pii a, pii b, pii c )
{
    double d1 = abs( portion(sub(a,b), sub(c,b)) ), d2 = abs( portion(sub(b,a), sub(c,a)) );
    //what_is(d1);
    //what_is(d2);
    pii vab = sub(b,a);
    double ab = sqrt( vab.xx*vab.xx + vab.yy*vab.yy );
    if( d1+d2 <= ab+eps )
        return 1;
    else
        return 0;
}

double dist( pii a, pii b )
{
    return sqrt( sq(a.xx-b.xx)+sq(a.yy-b.yy) );
}

double per_dist( pii a, pii b, pii c ) //min dist from c to ab
{

    if( is_90(a,b,c) )
    {
        //cout << 1 << endl;
        //cout << abs((a.xx*b.yy+b.xx*c.yy+c.xx*a.yy)-(a.yy*b.xx+b.yy*c.xx+c.yy*a.xx)) << endl;
        //cout << dist(a,b) << endl;
        //cout << abs((a.xx*b.yy+b.xx*c.yy+c.xx*a.yy)-(a.yy*b.xx+b.yy*c.xx+c.yy*a.xx))/dist(a,b) << endl;
        return abs((a.xx*b.yy+b.xx*c.yy+c.xx*a.yy)-(a.yy*b.xx+b.yy*c.xx+c.yy*a.xx))/dist(a,b);
    }
    else
    {
        //cout << 0 << endl;
        return min( dist(a,c), dist(b,c) );
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    /*pii a = mp(1,1), b = mp(1,10), c = mp(1,-5);
    double d = per_dist(a,b,c);
    what_is(d);*/
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d", &n);
        pii ara1[n+5];
        for( int i = 0; i < n; i++ )
        {
            scanf("%d %d", &ara1[i].xx, &ara1[i].yy );
        }
        scanf("%d", &m);
        pii ara2[m+5];
        for( int i = 0; i < m; i++ )
        {
            scanf("%d %d", &ara2[i].xx, &ara2[i].yy );
        }
        double ans = 100000000000000000.0;
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < m-1; j++ )
            {
                ans = min( ans, per_dist( ara2[j], ara2[j+1], ara1[i] ) );
            }
            ans = min( ans, per_dist( ara2[m-1], ara2[0], ara1[i] ) );
        }

        for( int i = 0; i < m; i++ )
        {
            for( int j = 0; j < n-1; j++ )
            {
                ans = min( ans, per_dist( ara1[j], ara1[j+1], ara2[i] ) );
            }
            ans = min( ans, per_dist( ara1[n-1], ara1[0], ara2[i] ) );
        }
        cout << "Case " << caseno++ << ": " << fixed << setprecision(10) << ans/2.0 << endl;
    }

    return 0;
}



