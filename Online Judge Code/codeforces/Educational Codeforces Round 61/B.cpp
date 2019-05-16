#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

intl ara[MAXN], sum = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ )
    {
        cin >> ara[i];
        sum += ara[i];
    }
    sort( ara+1, ara+n+1 );
    reverse( ara+1, ara+n+1 );
    int q;
    cin >> q;
    for( int i = 1; i <= q; i++ )
    {
        int a;
        cin >> a;
        cout << sum - ara[a] << endl;
    }

    return 0;
}
