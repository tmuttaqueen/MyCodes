#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

vector<int>to[5005];
intl mx;
int n, m;
intl lo[5005];

intl solve( int start )
{
    intl res = 0;
    for( int i = 1; i <= n; i++ )
    {
        if( to[i].size() == 0 ) continue;
        if( i < start )
        {
            res = max( res, i+n-start + lo[i] );
        }
        else
            res = max( res, i - start + lo[i] );
    }

    return res;
}

intl findLow( int cur )
{
    if( to[cur].size() == 0 ) return 0;
    intl t = n*( to[cur].size()-1 );
    if( to[cur].back() < cur )
    {
        int x = to[cur][0];
        return x + n - cur + t;
    }
    else
    {
        int x = 1e9;
        for( int j = 0; j < to[cur].size(); j++ )
        {
            if( to[cur][j] < cur ) continue;
            x = min( x, to[cur][j] );
        }
        return t+(x-cur);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for( int i = 1; i <= m; i++ )
    {
        int a, b;
        cin >> a >> b;
        to[a].push_back(b);
    }
    for( int i = 1; i <= n; i++ )
    {
        sort( to[i].begin(), to[i].end() );
        mx = max( mx, (intl)to[i].size() );
    }
    for( int i = 1; i <= n; i++ )
    {
        lo[i] = findLow(i);
        //cout << i << " " << lo[i] << endl;
    }

    for( int i = 1; i <= n; i++ )
    {
        cout << solve(i) << " ";
    }

    cout << endl;

    return 0;
}

