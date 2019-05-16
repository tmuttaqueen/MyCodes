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

const int mx = 1000005;
vector<int> edge[mx];
vector<int>deg(mx, -1);
vector<int>ans;
class comp
{
public:
    bool operator()( int &a, int &b )
    {
        return a > b;
    }
};

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int n;
    scanf("%d", &n);
    for( int i = 0; i < n; i++ )
    {
        int m, temp, a, b;
        scanf("%d", &m);
        scanf("%d", &a);
        if( deg[a] == -1 )
            deg[a] = 0;
        for( int i = 1; i < m; i++ )
        {
            scanf("%d", &b);
            edge[a].pb(b);
            deg[b] = ( deg[b] == -1 )? 1:deg[b]+1;
            a = b;
        }
    }

    priority_queue< int, vector<int>, comp >pq;
    for( int i = 0; i < mx; i++ )
    {
        if( deg[i] == 0 ) pq.push(i);
    }
    while( !pq.empty() )
    {
        int v = pq.top();
        ans.pb(v);
        pq.pop();
        int l = edge[v].size();
        for( int i = 0; i < l; i++ )
        {
            deg[ edge[v][i] ]--;
            if( deg[ edge[v][i] ] == 0 )
                pq.push(edge[v][i]);
        }
    }
    int l = ans.size();
    printf("%d", ans[0]);
    for( int i = 1; i < l; i++ )
    {
        printf(" %d", ans[i]);
    }
    puts("");

    return 0;
}



