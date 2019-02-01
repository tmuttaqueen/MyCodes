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

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i];
    }
    sort( ara, ara+n );
    intl ans = 0;
    for( int i = 0; i < n/2; i++ )
    {
        ans += ( ara[i]+ara[n-i-1] )*( ara[i]+ara[n-i-1] );
    }
    cout << ans << endl;
    return 0;
}
