#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;
const intl INF = 1e18;

int dx[MAXN], dy[MAXN];
intl x1, y1, x2, y2, n;

int isPos( intl d, intl curx, intl cury, intl tot )
{
    curx += d*dx[n];
    cury += d*dy[n];
    //cout << "-- " <<  d << " " << curx << " " << cury << endl;
    if( abs(x2-curx)+abs(y2-cury) <= tot )
        return 1;
    return 0;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> x1 >> y1 >> x2 >> y2;

    intl ans = INF;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    for( int i = 1; i <= n; i++ )
    {
        if( s[i] == 'U' )
        {
            dy[i] = 1 + dy[i-1];
            dx[i] = dx[i-1];
        }
        else if( s[i] == 'D' )
        {
            dy[i] = -1 + dy[i-1];
            dx[i] = dx[i-1];
        }
        else if( s[i] == 'R' )
        {
            dy[i] = dy[i-1];
            dx[i] = dx[i-1] + 1;
        }
        else if( s[i] == 'L' )
        {
            dy[i] = dy[i-1];
            dx[i] = dx[i-1] - 1;
        }
        //cout << i << " = " << dx[i] << " " << dy[i] << endl;
    }

    for( int i = 1; i <= n; i++ )
    {
        intl lo = 0, hi = 1e10;
        while( lo <= hi )
        {
            intl m = (lo+hi)/2;
            //cout << m << " " << ans << endl;
            if( isPos(m, x1 + dx[i], y1+dy[i], m*n+i ) )
            {
                ans = min(ans, m*n+i);
                hi = m - 1;
            }
            else
                lo = m+1;
        }
    }

    if( ans == INF )
    {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;




    return 0;
}
