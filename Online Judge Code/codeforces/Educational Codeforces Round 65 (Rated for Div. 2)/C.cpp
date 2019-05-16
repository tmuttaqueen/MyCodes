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

int sz[MAXN], par[MAXN];

int find_par( int p )
{
    if( par[p] == p  ) return p;
    return par[p] = find_par( par[p] );
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for( int i = 1; i <= n; i++ ) par[i] = i, sz[i] = 1;

    for( int i = 0; i < m; i++ )
    {
        int k;
        cin >> k;
        vector<int>vec;
        for( int j = 0; j < k; j++ )
        {
            int a;
            cin >> a;
            vec.push_back(a);
        }
        for( int i = 1; i < k; i++ )
        {
            int u = vec[i-1], v = vec[i];
            int p = find_par(u), q = find_par(v);
            if( p != q )
            {
                if( sz[p] < sz[q] )
                {
                    par[p] = q;
                    sz[q] += sz[p];
                }
                else
                {
                    par[q] = p;
                    sz[p] += sz[q];
                }

            }
        }

    }
    for( int i = 1; i <= n; i++ )
    {
        int p = find_par(i);
        cout << sz[p] << " ";
    }
    cout << endl;

    return 0;
}
