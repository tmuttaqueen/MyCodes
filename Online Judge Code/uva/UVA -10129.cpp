#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       cout << "YES" << endl
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double
typedef struct touple
{
    int xx,yy,zz;
    touple( int x = 0, int y = 0, int z = 0 ){xx=x; yy=y; zz=z;}
    bool operator<(const touple &a )
    {
        if( xx == a.xx )
		{
            if( yy == a.yy )
                return zz < a.zz;
            return yy < a.yy;
        }
        return xx<a.xx;
    }

} tii;
//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 127;

int in[M], out[M], ara[M];
string s;
int flag[M];
vector<int>adj[M];

void dfs(int u)
{
    flag[u] = 1;
    for( int i = 0; i < adj[u].size(); i++ )
    {
        int v = adj[u][i];
        if( flag[v] == 0 )
        {
            dfs(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        memset( ara, 0 , sizeof ara );
        for( int i = 0; i < 26; i++ )
        {
            adj[i].clear();
        }

        memset( flag, 0, sizeof flag );
        for( int i = 0; i < n; i++ )
        {
            cin >> s;
            adj[ s[0] - 'a' ].pb( s[ s.length()-1 ] - 'a' );
            adj[  s[ s.length()-1 ] - 'a'].pb( s[0] - 'a' );
            ara[ s[0] ]--;
            ara[ s[ s.length()-1 ] ]++;
        }
        int c = 0;
        for( int i = 0; i < 26; i++ )
        {
            if( adj[i].size() > 0 && flag[i] == 0 )
            {
                dfs(i);
                c++;
            }
        }
        int one = 0, mone = 0, other = 0;
        for( int i = 0; i < M; i++ )
        {
            if( ara[i] == 1 ) one++;
            else if( ara[i] == -1 ) mone++;
            else if( ara[i] != 0 ) other++;
        }
        if( one <= 1 && mone <= 1 && other == 0 && c == 1 )
        {
            cout << "Ordering is possible." << endl;
        }
        else
        {
            cout << "The door cannot be opened." << endl;
        }

    }
    return 0;
}
