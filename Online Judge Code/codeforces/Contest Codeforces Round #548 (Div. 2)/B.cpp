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
    for( int i = 1; i <= n; i++ ) cin >> ara[i];
    for( int j = n-1; j > 0; j-- ) ara[j] = min( ara[j], max(ara[j+1] - 1, 0LL) );
    intl ans = 0;
    for( int i =1; i <= n; i++ )
    {
        ans += ara[i];
    }
    cout << ans << endl;

    return 0;
}

