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

vector<int>vec[200005];

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, e;
        scanf("%d %d", &n, &e);
        for( int i = 0; i < e; i++ )
        {
            int a, b;
            scanf("%d %d", &a, &b);
            vec[a].pb(b);
            vec[b].pb(a);
        }
        for( int i = 1; i<=n; i++ )
        {
            sort( vec[i].begin(), vec[i].end() );
            vec[i].pb(-1);
        }
        int s;
        scanf("%d", &s);
        int ans[n+1];
        memset( ans, -1, sizeof(ans));
        int c = 1, cn = s;
        ans[cn] = 0;
        queue<int>q;
        q.push(cn);
        while( c < n )
        {
            int k = 0;
            cn = q.front();
            q.pop();
            for( int i = 1; i<=n; i++)
            {
                if( i != vec[cn][k] && i != cn && ans[i] == -1 )
                {
                    ans[i] = ans[cn]+1;
                    q.push(i);
                    c++;
                }
                else if( i == vec[cn][k] ) k++;
            }
        }
        int i = 1;
        if( i != s ) cout << ans[i];
        else
        {
            i++;
            cout << ans[i];
        }
        i++;
        for(; i <= n; i++ )
        {
            if( i != s )
                printf(" %d", ans[i]);
        }
        printf("\n");
        for( i = 1; i <= n; i++ ) vec[i].clear();
    }

    return 0;
}



