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

int lca[100005][20];
int val[100005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n, q;
        scanf("%d %d", &n, &q);
        lca[0][0] = -1;
        val[0] = 1;
        for( int i = 1; i < n; i++ )
        {
            scanf("%d %d", &lca[i][0], &val[i] );
        }
        for( int i = 1; i < 20; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                if( lca[j][i-1] == -1 )
                    lca[j][i] = -1;
                else
                    lca[j][i] = lca[ lca[j][i-1] ][i-1];
            }
        }
        /*for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < 4; j++ )
                cout << lca[i][j] << " ";
            cout << endl;
        }*/
        printf("Case %d:\n", caseno++);
        for( int i = 0; i < q; i++ )
        {
            int s, k;
            scanf("%d %d", &s, &k);
            int ans = val[s];
            while( lca[s][0] != -1 && ans >= k )
            {
                //what_is(ans);
                int j = 0;
                while( lca[s][j] != -1 && val[ lca[s][j] ] >=  k )
                    j++;
                j--;
                if( j >= 0 )
                    s = lca[s][j];
                else
                    break;
                ans = val[s];
            }
            //what_is(ans);
            printf("%d\n", s);
        }

    }

    return 0;
}



