#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

int ara[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int mx = 0;
    for( int i = 1; i <= n; i++ )
    {
        cin >> ara[i];
        mx = max( mx, ara[i] );
    }
    int ans = 1;
    for( int i = 1; i <= n; i++ )
    {
        int v = ara[i], ind = i;
        if( v == mx )
        {
            for( int j = i; j <= n; j++ )
            {
                if( ara[j] != v ) break;
                i = j;
            }
            //cout << ind << " " << i << endl;
            ans = max( ans, i - ind+1 );
        }
    }
    cout << ans << endl;

    return 0;
}
