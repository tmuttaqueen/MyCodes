#include<bits/stdc++.h>

using namespace std;

#define psi pair<string, int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

map<string, int>mm, val;
map<int,int>node[405*55*55];
int n, c;
psi ara[405];
vector<int>edge[405*55*55], cost[405*55*55];

int dfs( string s, int nd )
{
    for( int i = 0; i < n; i++ )
    {
        if( s.length() < ara[i].xx.length() ) continue;
        int d = s.find( ara[i].xx );
        while( d != string::npos )
        {
            string s1 = s.substr(0, d ) + s.substr(d+ara[i].xx.length());
            int u;
            if( mm[s1] == 0 )
            {
                mm[s1] = ++c;
                u = c;
            }
            else
            {
                u = mm[s1];
            }
            if( node[nd][u] == 0 )
            {
                node[nd][u] = 1;
                edge[nd].pb(u);
                cost[nd].pb(ara[i].yy);
                dfs(s1, u);
            }
            d = s.find( ara[i].xx, d+1 );
        }
    }
}

int in[405*55*55], dp[405*55*55];

void solve(int u)
{
    queue<int>q;
    q.push(u);
    while( !q.empty() )
    {
        int u = q.front();
        //cout << u << endl;
        q.pop();
        for( int i = 0; i < edge[u].size(); i++ )
        {
            int v = edge[u][i];
            dp[v] = max( dp[v], dp[u] + cost[u][i] );
            in[v]--;
            if( in[v] == 0 )
                q.push(v);
        }
    }
}

string rever( string s )
{
    string s1 = "";
    for( int i = s.length()-1; i >= 0; i-- )
    {
        s1 += s[i];
    }
    return s1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    string s1;
    int v;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> s1 >> v;
        string s2 = rever(s1);
        //cout <<s1 << " " <<s2 << endl;
        val[s1] = max( val[s1], v );
        val[s2] = max( val[s2], v );
    }
    n = 0;

    for( map<string, int>::iterator it = val.begin(); it != val.end(); it++ )
    {
        ara[n++] = *it;
        //cout << ara[n-1].xx << " " << ara[n-1].yy << endl;
    }
    mm[s] = ++c;
    dfs( s, 1 );
    cout << c << endl;
    dp[1] = 0;
    for( int i = 1; i <= c; i++ )
    {
        //cout << "i: " << i << endl;
        for( int j = 0; j < edge[i].size(); j++ )
        {
            //cout << edge[i][j] << " " << cost[i][j] << endl;
            in[ edge[i][j] ]++;
        }
        //cout << endl;
    }
    //for( int i = 1; i <= c; i++ )
        //cout << "in: " << in[i] << endl;
    solve(1);
    int ans = 0;
    for( int i = 1; i <= c; i++ )
    {
        ans= max( ans, dp[i] );
        //cout << i << " : " << dp[i] << endl;
    }
    cout << ans << endl;
    return 0;
}
