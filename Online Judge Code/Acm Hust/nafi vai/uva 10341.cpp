#include<bits/stdc++.h>

using namespace std;

double p, q, r, s, t, u, e = 2.7182818284590;

double value( double x )
{
    return p*pow(e,-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    while( cin >> p >> q >> r >> s >> t >> u )
    {
        double lo = 0, hi = 1, vl = value(lo), vh = value(hi);
        int f = 1;
        for( int i = 0; i < 50; i++ )
        {
            double m = (lo+hi)/2;
            double vm = value(m);
            if( vl*vm <= 0 )
            {
                hi = m;
                vh = vm;
            }
            else if( vh*vm <= 0 )
            {
                lo = m;
                vl = vm;
            }
            else
            {
                f = 0;
                break;
            }
        }
        if( f == 0 )
        {
            cout << "No solution" << endl;
        }
        else
        {
            cout << setprecision(4) << fixed << (lo+hi)/2.0 << endl;
        }
    }

    return 0;
}

