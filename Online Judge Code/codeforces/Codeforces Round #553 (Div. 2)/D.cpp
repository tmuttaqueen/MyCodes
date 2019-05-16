#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<intl,intl>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

pii ara[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    intl x = 0, y = 0;
    for( int i = 1; i <= n; i++ )
    {
        intl a, b;
        cin >> a >> b;
        ara[i] = mp( a-b, i );
        x += n*b;
        y += a;
    }
    sort( ara+1, ara+n+1 );
    reverse( ara+1, ara+n+1 );
    intl ans = x-y;
    for( int i = 1; i <= n; i++ )
    {
        ans += ara[i].xx*i;
    }
    cout << ans << endl;
    return 0;
}
