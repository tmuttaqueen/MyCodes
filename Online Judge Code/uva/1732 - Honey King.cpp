#include<bits/stdc++.h>

using namespace std;

#define intl long long

struct pt
{
    int x, y;
    pt(){}
    pt( int &a, int &b )
    {
        x = a;
        y = b;
    }
};

pt ara[123456];
pt a;
int n;

int dist( pt &a, pt &b )
{
    pt p;
    p.x = a.x-b.x;
    p.y = a.y-b.y;
    if( p.x*p.y >= 0 )
        return abs(p.x) + abs(p.y);
    else
        return max( abs(p.x), abs(p.y) );
}

int maxdist( pt &p )
{
    int mn = 0;
    for( int i = 0; i < n; i++ )
    {
        mn = max( mn, dist( p, ara[i] ) );
    }
    return mn;
}


int distx( int x )
{
    int uy = 10000, ly = -10000;
    int d = 1000000000, c = 0;
    while( ly <= uy )
    {
        int m1 = ly + (uy-ly)/3, m2 = uy - (uy-ly)/3;
        pt p1(x,m1), p2(x,m2);
        //change here
        int d1 = maxdist( p1), d2 = maxdist(p2);
        //cout << "d is distx " << d << ' ' << ly << ' ' << uy << endl;
        if( d1 <= d2 )
        {
            d = min(d, d1);
            uy = m2-1;
        }
        else
        {
            d = min(d, d2);
            ly = m1+1;
        }
        c++;
        if( c > 20 ) break;
    }
    return d;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, caseno = 1;
    cin >> t;
    while( t-- )
    {
        cin >> n;
        for( int i = 0; i < n; i++ )
        {
            cin >> ara[i].x >> ara[i].y;
        }
        //cin >> a.x >> a.y;

        int ux = 10000, lx = -10000, d = 1000000000, c = 0;
        while( lx <= ux )
        {
            int m1 = lx+ (ux-lx)/3, m2 = ux - (ux-lx)/3;
            int d1 = distx(m1), d2 = distx(m2);
            //cout << "dx is " << d << ' ' << lx << ' ' << ux << endl;
            if( d1 <= d2 )
            {
                d = min(d, d1);
                ux = m2-1;
            }
            else
            {
                d = min(d, d2);
                lx = m1+1;
            }
            if( c > 20 ) break;
        }
        intl ans = d;
        ans = 1 + 3*ans*(ans+1);
        cout << "Case " << caseno++ << ": " <<  ans << endl;
    }

    return 0;
}


