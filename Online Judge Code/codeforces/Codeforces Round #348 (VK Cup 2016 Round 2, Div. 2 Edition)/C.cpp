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
int n, m, q;
pii mat[101][101];
int ans[101][101];

int main()
{
    ios::sync_with_stdio(false);
    //filein;

    cin >> n >> m >> q;

    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= m; j++ )
        {
            mat[i][j] = mp(i, j);
        }
    }

    for( int i = 0; i < q; i++ )
    {
        int t, a, b, x;
        cin >> t;
        if( t == 1 )
        {
            int r;
            cin >> r;
            pii temp = mat[r][1];
            for( int j = 1; j < m; j++ )
            {
                mat[r][j] = mat[r][j+1];
            }
            mat[r][m] = temp;
        }
        else if( t==2 )
        {
            int c;
            cin >> c;
            pii temp = mat[1][c];
            for( int j = 1; j < n; j++ )
            {
                mat[j][c] = mat[j+1][c];
            }
            mat[n][c] = temp;
        }
        else
        {
            cin >> a >> b >> x;
            pii temp = mat[a][b];
            ans[ temp.xx ][temp.yy] = x;
        }
    }

    for( int i = 1; i <= n; i++ )
    {
        cout << ans[i][1];
        for( int j = 2; j <= m; j++ )
        {
            cout << " " << ans[i][j];
        }
        cout << "\n";
    }

    return 0;
}



