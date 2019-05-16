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
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int SZ = 1000005, mod = 1000000007;

int ans[200][1555];
string s;
int c[2100];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int l;
    cin >> l;
    cin.ignore();
    cin >> s;
    for( int i = 0; i < l; i++ )
    {
        memset( c, 0, sizeof c );
        for( int j = i; j < l; j++ )
        {
            c[ s[j] - 'a' ]++;
            for( int k = 0; k < 26; k++ )
            {
                ans[k][ j-i+1 - c[k] ] = max( ans[k][ j-i+1 - c[k] ], j-i+1 );
            }
        }
    }
    for( int i = 0; i < 26; i++ )
    {
        for( int j  = 1; j < 1505; j++ )
        {
            ans[i][j] = max( ans[i][j], ans[i][j-1] );
        }
    }
    memset( c, 0, sizeof c );
    for( int i = 0; i < l; i++ )
    {
        c[ s[i] - 'a' ]++;
    }
    int q;
    cin >> q;
    while(q--)
    {
        char x;
        int m;
        cin >> m >> x;
        if( l - c[x -'a'] <= m )
        {
            cout << l << endl;
        }
        else
        {
            cout << ans[ x-'a' ][m] << endl;
        }
    }


    return 0;
}



