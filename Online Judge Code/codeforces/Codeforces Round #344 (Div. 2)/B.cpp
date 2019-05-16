#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<int, pii>


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n = 10, m = 5000, k, x, a, y;
    cin >> n >> m >> k;
    int ara[n+1][m+1];
    for( int i = 0; i <= n; i++ )
    {
        for( int j = 0; j <= m; j++ )
        {
            ara[i][j] = 0;
        }
    }
    vector<piii> vec;
    for( int i = 1; i <= k; i++ )
    {
        //int a = 1, x = 1, y = 1;
        cin >> a >> x >> y;
        vec.pb({a, {x,y}});
    }
    vector<piii> op;
    bool row[n+10], col[m+10];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    for( int i = k-1; i >= 0 ; i-- )
    {
        if( vec[i].xx == 1 )
        {
            if( row[vec[i].yy.xx] == 0 )
            {
                op.pb(vec[i]);
                row[vec[i].yy.xx] = 1;
            }
        }
        else
        {
            if( col[vec[i].yy.xx] == 0 )
            {
                op.pb(vec[i]);
                col[vec[i].yy.xx] = 1;
            }
        }
    }
    for( int i = op.size() - 1; i >= 0; i-- )
    {
        if( op[i].xx == 1 )
        {
            int r = op[i].yy.xx - 1;
            int c = op[i].yy.yy;
            for( int i = 0; i < m; i++ )
            {
                ara[r][i] = c;
            }
        }
        else
        {
            int r = op[i].yy.xx - 1;
            int c = op[i].yy.yy;
            for( int i = 0; i < n; i++ )
            {
                ara[i][r] = c;
            }
        }
    }
    for( int i = 0; i < n; i++ )
    {
        cout << ara[i][0];
        for( int j = 1; j < m; j++ )
        {
            cout << " " << ara[i][j];
        }
        cout <<  "\n";
    }
    return 0;
}



