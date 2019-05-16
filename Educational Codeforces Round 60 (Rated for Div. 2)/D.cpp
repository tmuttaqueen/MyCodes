#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

intl C( intl n, intl r )
{
    if( r == 0 || n-r == 0 ) return 1;
    intl ans = 1;
    for( int i = 2; i <= n; i++ ) ans *= i;
    for( int i = 1; i <= r; i++ ) ans/=i;
    for( int i = 1; i <= n-r; i++ ) ans/=i;
    return ans;
}

intl solve( int n, int m )
{
    intl ans = 0;
    intl f = n/m;
    for( int k = 0; k <= f; k++ )
    {
        cout << n - k*m + k << " " <<k << endl;
        ans += C( n - k*m + k, k );
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for( int i = n; i <= n; i++ )
    {
        for( int j = m; j <= m; j++ )
        {
            cout << solve(i, j) << ",";
        }
    }

    return 0;
}
