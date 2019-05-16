#include<bits/stdc++.h>

using namespace std;

#define ld             long double
#define intl           long long
#define pii            pair<int,int>
#define xx             first
#define yy             second
#define mp             make_pair
#define pb             push_back
#define SZ(x)          (int)(x).size()
#define ALL(x)         begin(x), end(x)
#define REP(i, n)      for (int i = 0; i < n; ++i)
#define FOR(i, a, b)   for (int i = a; i <= b; ++i)
#define RFOR(i, a, b)  for (int i = a; i >= b; --i)

const int MAXN = 300005, inf = 1e9+5;
const intl INF = 1e18+5;
const ld eps = 1e-9;

vector<int> vec[100][100];

int a1[100][100], a2[100][100];

int n,m;

bool valid( int a[100][100] )
{
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 2; j <= m; j++ )
        {
            if( a[i][j] <= a[i][j-1] ) return 0;
        }
    }

    for( int i = 1; i <= m; i++ )
    {
        for( int j = 2; j <= n; j++ )
        {
            if( a[j][i] <= a[j-1][i] ) return 0;
        }
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //int n, m;
    cin >> n >> m;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= m; j++ )
        {
            int a;
            cin >> a;
            vec[i][j].push_back(a);
        }
    }

    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= m; j++ )
        {
            int a;
            cin >> a;
            vec[i][j].push_back(a);
        }
    }

    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= m; j++ )
        {
            if( vec[i][j][0] > vec[i][j][1] ) swap( vec[i][j][0], vec[i][j][1] );
        }
    }

    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= m; j++ )
        {
            a1[i][j] = vec[i][j][0];
            a2[i][j] = vec[i][j][1];
        }
    }

    if( valid( a1 ) && valid(a2))
    {
        cout << "Possible" << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }

    return 0;
}
