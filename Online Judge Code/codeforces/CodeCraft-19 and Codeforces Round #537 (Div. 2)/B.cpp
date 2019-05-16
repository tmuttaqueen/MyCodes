#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

intl ara[MAXN];
intl pre[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    intl n, k, m;
    cin >> n >> k >> m;
    for( int i = 0; i < n; i++ ) cin >> ara[i];
    sort( ara, ara+n );
    pre[0] = ara[0];
    for( int i = 1; i < n; i++ )
        pre[i] = pre[i-1] + ara[i];
    double ans = 1.0*pre[n-1]/n;
    ans = max(ans, 1.0*(pre[n-1] + min( n*k, m ))/n );
    for( int i = 1; i < n; i++ )
    {
        if( i > m )
            break;
        ans = max( ans, 1.0*( pre[n-1] - pre[i-1] + min( (n-i)*k, m-i ) )/(n-i) );
    }

    cout << setprecision(10) << fixed << ans << endl;


    return 0;
}
