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
#define piii        pair<pii, int>


int main()
{
    //ios::sync_with_stdio(false);
    filein;
    int n, m, p;
    cin >> n >> m >> p;
    int ara[n][m];

    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < m; j++ )
        {
            //cin >> ara[i][j];
            scanf("%d", &ara[i][j]);
        }
    }

    vector<pii>vec[p+5];
    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < m; j++ )
        {
            int x = ara[i][j];
            vec[x].pb( mp(i,j) );
        }
    }

    vector<intl>ans[p+5];
    for( int i = 0; i < vec[1].size(); i++ )
        ans[1].pb( vec[1][i].xx+vec[1][i].yy );
    for( int i = 2; i <= p; i++ )
    {
        for( int j = 0; j < vec[i].size(); j++ )
        {
            intl mx = 1e9, a = vec[i][j].xx, b = vec[i][j].yy;
            for( int k = 0; k < vec[i-1].size(); k++ )
            {
                mx = min( ans[i-1][k] + abs(vec[i-1][k].xx - a )+abs( vec[i-1][k].yy - b ), mx );
            }
            ans[i].pb(mx);
        }
    }

    //cout << ans[p][0] << endl;
    printf("%I64d\n", ans[p][0]);
    return 0;
}


