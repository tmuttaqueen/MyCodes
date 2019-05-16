#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

vector<int>edge[30];
int in[30], out[30], vis[30];
stack<string> mm[30][30];
int sz;
vector<int>ans;
int matrix[30][30];
int e, s;
int par[30];
int n, used;
int find_par( int p )
{
    return (par[p] == p) ? p:find_par(par[p]);
}

void dfs2( int u )
{
    //what_is(u);
    ans.pb(u);
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if( (matrix[u][v] > 0 && out[v] > 0) || (matrix[u][v] > 0 && used == n-1 ) )
        {
            matrix[u][v]--;
            used++;
            in[v]--;
            out[u]--;
            dfs2(v);
        }
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        for( int i = 0; i < 30; i++ ) edge[i].clear();
        for( int i = 0; i < 30; i++ )
            for( int j = 0; j < 30; j++ )
                while( !mm[i][j].empty() )
                    mm[i][j].pop();
        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);
        memset(vis, 0, sizeof vis);
        memset(matrix, 0, sizeof matrix);
        ans.clear();
        cin >> n;
        cin.ignore();
        string ss;
        for( int i = 0; i < n; i++ )
        {
            cin >> ss;
            int a = ss[0] - 'a';
            int b = ss[ss.size()-1] - 'a';
            in[b]++;
            out[a]++;
            matrix[a][b]++;
            mm[a][b].push(ss);
            edge[a].pb(b);
            s = a;
            e = b;
            //what_is(a);
            //what_is(b);
        }
        //debug;
        int num = 0, x = 0;
        bool ispos = 1;
        for( int i = 0; i < 26; i++ )
        {
            if( abs(in[i]-out[i]) > 1 )
                ispos = 0;
            if( in[i] != out[i] )
                num++;
            if( out[i] > in[i] )
                s = i;
            if( out[i] < in[i] )
                e = i;
        }
        //debug;
        if(num > 2)
            ispos = 0;

        int temp  = 0;
        for( int i = 0; i < 26; i++ ) par[i] = i;
        for( int i = 0; i < 26; i++ )
        {
            for( int j = 0; j < edge[i].size(); j++ )
            {
                int u = i, v = edge[i][j];
                int up = find_par(u);
                int vp = find_par(v);
                if( up != vp )
                {
                    par[up] = vp;
                }
            }
        }
        set<int>se;
        for( int i = 0; i < 26; i++ )
        {
            int p = find_par(i);
            if( in[i] || out[i] )
                se.insert(p);
        }
        if( se.size() > 1 )
            ispos = 0;
        //debug;
        if(!ispos)
        {

            cout << "Case " << caseno++ << ": No\n";
        }
        else
        {

            cout << "Case " << caseno++ << ": Yes\n";
            used = 0;
            dfs2(s);
            //debug;
            //what_is(e);
            //ans.pb(e);
            int l = ans.size();
            //what_is(l);
            //for( int i = 0; i < l; i++ ) cout << ans[i] << " ";
            cout << mm[ans[0]][ans[1]].top();
            mm[ans[0]][ans[1]].pop();
            //debug;
            for( int i = 2; i < l; i++ )
            {
                //what_is(i);
                if( !mm[ans[i-1]][ans[i]].empty() )
                {
                    cout << " " << mm[ans[i-1]][ans[i]].top();
                    mm[ans[i-1]][ans[i]].pop();
                }

            }
            //debug;
            cout << endl;
        }
    }

    return 0;
}




