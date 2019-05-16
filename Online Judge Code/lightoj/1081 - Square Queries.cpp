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

int rmq[1026][1026][11], ara[505][505];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        memset(rmq,-1,sizeof(rmq));
        int n,q;
        scanf("%d %d", &n, &q);
        for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= n; j++ )
            {
                scanf("%d", &ara[i][j] );
                rmq[i][j][0] = ara[i][j];
            }
        }


        for( int i=1; (1<<i) <= n; i++ )
        {
            //what_is(i);
            int k = 1<<(i-1);
            for( int l = 1; l <= n; l++ )
            {
                for( int r = 1; r <= n; r++ )
                {
                    rmq[l][r][i] = max( rmq[l+k][r][i-1], max( rmq[l+k][r+k][i-1], max( rmq[l][r+k][i-1], rmq[l][r][i-1] ) ) );
                    //cout << l << " " << r << " " << i << " val " << rmq[l][r][i] << endl;
                }
            }
        }
        printf("Case %d:\n", caseno++);
        while(q--)
        {
            int i, j, l;
            scanf("%d %d %d", &i, &j, &l);
            int k = 2, s = 0;
            while(k < l)
            {
                k *= 2;
                s++;
            }
            int x = i+l, y = j+l;
            k = 1<<s;
            //cout << k << " " << s << endl;
            int ans = max( max( rmq[i][j][s], rmq[x-k][j][s] ), max( rmq[x-k][y-k][s], rmq[i][y-k][s] ) );
            printf("%d\n", ans);
        }

    }
    return 0;
}



