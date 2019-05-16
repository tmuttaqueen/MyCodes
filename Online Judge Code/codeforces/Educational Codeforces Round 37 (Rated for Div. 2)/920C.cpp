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
const int M = 345678;

int ara[M];
char str[M];

int par[M];

int findpar( int u )
{
    if( par[u] == u ) return u;
    else return par[u] = findpar( par[u] );
}

void merge( int a, int b )
{
    int pa = findpar(a), pb = findpar(b);
    if( pa != pb )
    {
        par[pa] = pb;
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //filein;
    int n;
    scanf("%d", &n);
    for( int i = 1; i <= n; i++ )
    {
        scanf("%d", &ara[i]);
        par[i] = i;
    }
    getchar();
    scanf("%s", str+1);
    for( int i = 1; i < n; i++ )
    {
        if( str[i] == '1' )
        {
            merge( ara[i], ara[i+1] );
        }
    }
    int f = 1;
    for( int i = 1; i <= n; i++ )
    {
        int pi = findpar( i ), pa = findpar( ara[i] );
        //cout << i << " " << pi << " " << ara[i] << " " << pa << endl;
        if( pi != pa )
            f = 0;
    }
    if(f)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
