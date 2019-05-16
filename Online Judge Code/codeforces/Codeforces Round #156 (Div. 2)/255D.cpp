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

intl lx, rx, uy, dy, n;

struct PT
{
    intl x, y;
    PT() {}
    PT(intl x, intl y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &p)  const
    {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p)  const
    {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (intl c)     const
    {
        return PT(x*c,   y*c  );
    }
    PT operator / (intl c)     const
    {
        return PT(x/c,   y/c  );
    }
};

intl ComputeSignedArea(const vector<PT> &p)
{
    intl area = 0;
    for(int i = 0; i < p.size(); i++)
    {
        int j = (i+1) % p.size();
        area += p[i].x*p[j].y - p[j].x*p[i].y;
    }
    return area;
}

intl gcd( intl a, intl b )
{
    return b == 0? a: gcd(b, a%b);
}

intl solve( intl t )
{
    vector<PT>vec;
    if( t <= dy )
    {
        vec.pb( PT(0, -t) );
    }
    else
    {
        vec.pb( PT( -min(lx, (t-dy)), -dy ) );
        vec.pb( PT( min(rx, (t-dy)), -dy ) );
    }
    if( t <= rx )
    {
        vec.pb( PT(t, 0) );
    }
    else
    {
        vec.pb( PT( rx, -min(dy, t-rx) ) );
        vec.pb( PT( rx,  min(uy, t-rx)) );
    }
    if( t <= uy )
    {
        vec.pb( PT(0, t) );
    }
    else
    {
        vec.pb( PT( min(rx, (t-uy)), uy ) );
        vec.pb( PT( -min(lx, (t-uy)), uy ) );
    }
    if( t <= lx )
    {
        vec.pb( PT(-t, 0) );
    }
    else
    {
        vec.pb( PT( -lx,  min(uy, t-lx)) );
        vec.pb( PT( -lx, -min(dy, t-lx) ) );
    }
    /*for( int i = 0; i < vec.size(); i++ )
    {
        cout << vec[i].x << ' ' << vec[i].y << endl;
    }*/
    intl area = ComputeSignedArea(vec);
    //what_is(area);
    intl g = -int(vec.size());
    g += gcd( abs(vec[0].x-vec[ vec.size()-1 ].x), abs( vec[0].y - vec[ vec.size()-1 ].y )  ) + 1;
    for( int i = 1;i < vec.size(); i++ )
    {
        g += gcd(  abs(vec[i].x-vec[ i-1 ].x), abs( vec[i].y - vec[ i-1 ].y ) ) + 1;
    }
    return (area+g+2)/2;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl x, c, y;
    cin >> n >> x >> y >> c;
    if( c == 1 )
    {
        cout << 0 << endl;
        return 0;
    }
    lx = y-1; rx = n-y; uy = x-1; dy = n-x;
    intl ans = 2*n, l = 0, r = 2*n;
    while( l <= r )
    {
        intl m = (l+r)/2;
        intl cnt = solve(m);
        //what_is(m);
        //what_is(cnt);
        if( cnt >= c )
        {
            ans = m;
            r = m -1;
        }
        else
            l = m+1;
    }
    cout << ans << endl;

    return 0;
}
