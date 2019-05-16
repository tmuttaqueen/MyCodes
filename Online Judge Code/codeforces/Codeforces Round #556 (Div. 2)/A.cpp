#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, r;
    cin >> n >> m >> r;
    int x = 1e9, y = 0;
    for( int i = 1; i <= n; i++ )
    {
        int a;
        cin >> a;
        x = min(a,x);
    }
    for( int i = 1; i <= m; i++ )
    {
        int a;
        cin >> a;
        y = max(a,y);
    }

    int d = r/x, l = r%x;
    int ans = max( r, d*y + l );
    cout << ans << endl;

    return 0;
}

