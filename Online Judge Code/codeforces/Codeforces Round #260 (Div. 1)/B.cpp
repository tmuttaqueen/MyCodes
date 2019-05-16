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
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int max_len = 123456, alpha = 26;

int tree[max_len][alpha];
int szT = 1, root = 1;
int win[max_len], lose[max_len];
int newT()
{
    return ++szT;
}

void insert( char *s )
{
    int from = root;
    for( int i = 0; s[i]; i++ )
    {
        int c = s[i] - 'a';
        if( tree[from][c] == 0 ) tree[from][c] = newT();
        from =  tree[from][c];
    }
}

void dfs( int from )
{
    int leaf = 1;
    for( int i = 0; i < alpha; i++ )
    {
        int to = tree[from][i];
        if( to )
        {
            //what_is(to);
            leaf = 0;
            dfs( to );
            win[from] |= !win[to];
            lose[from] |= !lose[to];
        }
    }
    if( leaf )
    {
        lose[from] = 1;
    }
}

char s[max_len];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, k;
    cin >> n >> k;
    for( int i = 0; i < n; i++ )
    {
        cin >> s;
        insert( s );
    }
    dfs(root);
    if( win[root] && lose[root]  )
    {
        cout << "First" << endl;
    }
    else if( win[root] )
    {
        if( k%2 )
        {
            cout << "First" << endl;
        }
        else
            cout << "Second" << endl;
    }
    else //if( lose[root] )
    {
        cout << "Second" << endl;
    }
    return 0;
}
