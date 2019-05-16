#include<bits/stdc++.h>

using namespace std;


const int M = 1005;

int x[M], y[M], n;
double sx, sy;

double dist( int a, int b, double p, double q )
{
    return (a-p)*(a-p) + (b-q)*(b-q);
}

double findy( double dx )
{
    double l = -30000, r = 30000, ans = 100000;
    for( int i = 0; i < 200; i++ )
    {
        double y1 = l+(r-l)/3.0, y2 = r - (r-l)/3.0;
        double d1 = 0, d2 = 0;
        for( int j = 0; j < n; j++ )
        {
            d1 = max(d1, dist( x[j], y[j], dx, y1 ) );
            d2 = max(d2, dist( x[j], y[j], dx, y2 ) );
        }
        if( d1 < d2 )
        {
            r = y2;
            ans = d1;
        }
        else
        {
            l = y1;
            ans = d2;
        }
    }
    return ans;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> x[i] >> y[i];
    }
    double l = -30000, r = 30000, ans = 100000;
    for( int i = 0; i < 200; i++ )
    {
        double m1 = l + (r-l)/3.0, m2 = r - (r-l)/3.0;
        double f1 = findy(m1), f2 = findy(m2);
        if( f1 < f2 )
        {
            r = m2;
            ans = f1;
        }
        else
        {
            ans = f2;
            l = m1;
        }

    }
    ans = sqrt(ans);
    //cout << ans*2 << endl;
    //int d = ans*2*1000 + 5;
    //ans = d/10;
    //ans = ans/100;
    cout << setprecision(5) << fixed << ans << endl;

    return 0;
}
