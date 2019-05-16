#include<bits/stdc++.h>

using namespace std;

#define intl long long


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double pi = acos(-1.0);
    double n,r;
    intl nn, rr;
    int caseno = 1;
    while(1)
    {
        cin >> rr >> nn;
        if( nn == 0 && rr == 0 ) break;
        n = nn;
        r = rr;

        cout << "Case " << caseno++ << ":\n";
        for( int i = 1; i <= 10; i++ )
        {
            double ans = (acos(1.0*n/(2*pi*r*i)) - n/r)*180/pi;
            cout << setprecision(5) << fixed << ans << "\n";
        }
    }

    return 0;
}
