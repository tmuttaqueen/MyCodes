#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

int one[5005][5005], two[5005][5005], val[5005];
int l[5005], r[5005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for( int i = 1; i <= q; i++ )
    {
        cin >> l[i] >> r[i];
        for( int j = l[i]; j <= r[i]; j++ )
            val[j]++;
    }

    for( int i = 1; i <= n; i++ )
    {
        if( val[i] == 1 ) one[i][i] = 1;
        if( val[i] == 2 ) two[i][i] = 1;
        for( int j = i-1; j >= 1; j-- )
        {
            one[j][i] = one[j][i-1] + one[i][i];
            two[j][i] = two[j][i-1] + two[i][i];
        }
    }
    int ans = 0;

    int nn = n;
    n = 0;
    for( int i = 1; i <= nn; i++ )
    {
        if( val[i] ) n++;
    }

    for( int i = 1; i <= q; i++ )
    {
        for( int j = i + 1; j <= q; j++ )
        {
            int l1 = l[i], l2 = l[j], r1 = r[i], r2 = r[j];
            if( (l2 >= l1 && l2 <= r1) || ( (r2 >= l1 && r2 <= r1) ) )
            {
             int v[4];
             v[0] = l1;
             v[1] = l2;
             v[2] = r1;
             v[3] = r2;
             sort( v, v + 4 );
             ans = max( ans, n - one[ v[0] ][ v[1] - 1 ] - two[ v[1] ][ v[2] ] - one[ v[2] + 1 ][ v[3] ] );
            }
            else
            {
                ans = max( ans, n - one[l1][r1] - one[l2][r2] );
            }
        }
    }


    cout << ans << endl;

    return 0;
}
