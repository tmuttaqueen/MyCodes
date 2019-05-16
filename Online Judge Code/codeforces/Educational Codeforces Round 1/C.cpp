#include <bits/stdc++.h>

using namespace std;

const long double pi = 3.141592653589793;

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
#define pii         pair<int, int>
#define piii        pair<pii, int>

vector<piii>vec;

long double angl( piii a)
{
    long double d = atan2( a.xx.yy, a.xx.xx );
    if( d < 0 )
        d = pi*2+d;
    return d*180/pi;
}

bool comp( piii a, piii b )
{
    return  angl(a) < angl(b);
}



long double angle( piii a, piii b )
{
    long double d1 = angl(a), d2 = angl(b);
    return min(abs(d1-d2), 360 - abs(d1-d2));
}

int main()
{
    //filein;
    int n, a, b;
    scanf("%d", &n);
    for( int i = 1; i <= n; i++ )
    {
        scanf("%d %d", &a, &b);
        vec.pb( mp( mp(a,b), i ) );
    }

    sort( vec.begin(), vec.end(), comp );
    //for( int i = 0; i < n; i++ ) cout << vec[i].yy << " ";
    //cout << endl;
    long double ang = angle( vec[0], vec[1] );
    int s = vec[0].yy, e = vec[1].yy;
    //what_is(ang);
    for( int i = 2; i < n; i++ )
    {
        //cout << angle( vec[i], vec[i-1] ) << endl;
        if( ang - angle( vec[i], vec[i-1] ) > 0.000000000000001 )
        {
            ang = angle( vec[i], vec[i-1] );
            s = vec[i].yy;
            e = vec[i-1].yy;
        }
    }
    if( angle( vec[0], vec[n-1] ) < ang )
    {
        s = vec[0].yy;
        e = vec[n-1].yy;
    }
    printf("%d %d\n",s,e );
    return 0;
}



