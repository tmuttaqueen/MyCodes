#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", "stdout")
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back

vector<int>vec[110];
vector<int>cost[110];
vector<int>flag[110];

int main()
{
    ios::sync_with_stdio(0);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n, sum = 0, ans = 0;
        //getchar();
        cin >> n;
        //what_is(n);
        for( int i = 0; i < n; i++ )
        {
            int a, b, c;
            cin >> a >> b >> c;
            vec[a].pb(b);
            vec[b].pb(a);
            cost[a].pb(c);
            cost[b].pb(c);
            flag[a].pb(1);
            flag[b].pb(0);
            sum += c;
        }
        bool visited[110];
        memset( visited, 0, sizeof(visited) );

        int v = 1, next = vec[v][0];
        //what_is(next);
        if( flag[v][0] == 0 ) ans += cost[v][0];
        v = next;
        //what_is(v);
        visited[v] = 1;

        if( vec[v][0] == 1 ) next = 1;
        else next = 0;
        if( flag[v][next] == 0 ) ans += cost[v][next];
        v = vec[v][next];
        //what_is(ans);

        for( int i = 2; i < n; i++ )
        {
            visited[v] = 1;
            if( visited[vec[v][0]] == 1 ) next = 1;
            else next = 0;
            //what_is(next);
            if( flag[v][next] == 0 ) ans += cost[v][next];
            v = vec[v][next];
            //what_is(ans);
        }
        //what_is(ans);
        ans = min(ans, sum-ans);
        cout << "Case " << caseno++ << ": " << ans << endl;
        for( int i = 0; i < 110; i++ )
        {
            vec[i].clear();
            flag[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}


