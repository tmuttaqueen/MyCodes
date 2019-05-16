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
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, char>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;

vector< int > in[123], out[123];
int ans[123][123][30];
int din[123], dout[123];
char ara[123][123];
vector<int>luc, mx;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    stack<int>st;
    int n, m, u, v;
    char c;
    cin >> n >> m;

    for( int i = 0; i < m; i++ )
    {
        cin >> u >> v >> c;
        ara[u][v] = c;
        in[v].pb( u );
        out[u].pb( v );
        din[v]++;
        dout[u]++;
    }

    for( int i= 1; i <= n; i++ )
    {
        if( dout[i] == 0 )
            st.push(i);
    }
    while( !st.empty() )
    {
        mx.clear();
        int u = st.top();
        st.pop();
        for( int i = 0; i < out[u].size(); i++ )
        {
            mx.pb( out[u][i] );
        }
        for( int i = 0; i < in[u].size(); i++ )
        {
            dout[ in[u][i] ]--;
            if( dout[in[u][i]] == 0 )
                st.push( in[u][i] );
        }
        for( int v = 1; v <= n; v++ )
        {
            luc.clear();
            if( mx.size() == 0 )
            {
                for( int i = 0; i < 26; i++ )
                    ans[u][v][i] = 0;
                continue;
            }
            for( int i = 0; i < out[v].size(); i++ )
            {
                luc.pb( out[v][i] );
            }
            int f = 0;
            for( int i = 0; i < mx.size(); i++ )
            {
                int d = 0, e = 0;
                char a = 'a', b = '0';
                for( int j = 0; j < luc.size(); j++ )
                {
                    int p = mx[i], q = luc[j];
                    cout << u << " " << p << " - " << v << " " << q << endl;
                    char ch = max( ara[u][p], ara[v][q] );
                    if( ara[u][p] > ara[v][q] )
                    {
                        e++;
                        b = max( b, ch );
                    }
                    if( ans[p][q][ch-'a'] == 1 )
                    {
                        d++;
                        a = max( a, ch );
                    }
                }
                if( d == luc.size() )
                {
                    //what_is(u);
                    //what_is(a);
                    for( int i = 0; i <= a - 'a'; i++ )
                    {
                        ans[u][v][i] = 1;
                    }
                }
                if( e == mx.size() )
                {
                    for( int i = 0; i <= b - 'a'; i++ )
                    {
                        ans[u][v][i] = 1;
                    }
                }
            }
        }
    }
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            int d = 0;
            for( int k = 0; k < 26; k++ ) d += ans[i][j][k];
            if( d  )
                cout << "A";
            else
                cout << "B";
        }
        cout << endl;
    }

    return 0;
}
