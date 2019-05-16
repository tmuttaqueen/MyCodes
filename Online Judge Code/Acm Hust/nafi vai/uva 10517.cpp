#include<bits/stdc++.h>

using namespace std;

double pi = acos(-1.0);
double n, m;
double eps = 0.00000000001;
double value( double g )
{
    return m*cos( g + n/6378.0 )/(n*cos(g)) - 1.0;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, caseno = 1;
    cin >> t;
    double R = 6378.0;
    while(t--)
    {
        cin >> n >> m;
        if( n <= eps || n >= m || n >= 1001.0 )
        {
            cout << "Case " << caseno++ << ": Invalid or impossible." << endl;
            continue;
        }
        double temp = n/R;
        double d = 1.0/tan(n/R) - n/(m*sin(n/R));
        if( d < 0 || d >= 3 )
        {
            cout << "Case " << caseno++ << ": Invalid or impossible." << endl;
            continue;
        }
        double theta = atan(d)*180.0/pi;
        if( theta >= -eps && theta <= eps )
        {
            theta = 0;
        }
        if( theta < 0 || theta >= 70 + eps )
        {
            cout << "Case " << caseno++ << ": Invalid or impossible." << endl;
        }
        else
        {
            double an = theta;
            int deg = an;
            an = an - deg;
            an = an*60;
            int mn = an;
            an = an - mn;
            an = an*60 + 0.5;
            int sec = an;
            cout << "Case " << caseno++ << ": " << deg << " deg "<< mn << " min " << sec << " sec" << endl;;
        }
    }


    return 0;
}




