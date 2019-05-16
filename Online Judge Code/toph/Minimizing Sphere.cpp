#include<bits/stdc++.h>

using namespace std;

int x[100], y[100], z[100];

double dist( double a, double b, double c, double d, double e, double f )
{
    return (a-d)*(a-d) + (b-e)*(b-e) + (c-f)*(c-f);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        double sx = 0, sy = 0, sz = 0, jump = 0.1, r;
        for( int i = 0; i < n; i++ )
        {
            cin >> x[i] >> y[i] >> z[i];
            sx += x[i];
            sy += y[i];
            sz += z[i];
        }
        sx /= n;
        sy /= n;
        sz /= n;

        for( int j = 0; j < 30000; j++ )
        {
            r = 0;
            int ind = 0;
            for( int i = 0; i < n; i++ )
            {
                double d = dist( sx, sy, sz, x[i], y[i], z[i] );
                if( d > r )
                {
                    r = d;
                    ind = i;
                }
            }
            double dx = (x[ind] - sx), dy = (y[ind]-sy), dz = (z[ind]-sz);
            sx += dx*jump;
            sy += dy*jump;
            sz += dz*jump;
            jump *= 0.999;
        }
        //cout << r << endl;
        r = sqrt(r);
        double ans = acos(-1.0)*4.0/3;
        ans *= r*r*r;
        cout << setprecision(10) << fixed << ans << endl;
    }

    return 0;
}
