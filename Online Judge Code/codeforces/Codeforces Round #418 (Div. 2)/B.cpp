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

int a[1111], b[1111], c[1111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, p[2], t = 0;
    //filein;
    cin >> n;
    for( int i = 0; i < n; i++ )
        cin >> a[i];
    for( int i = 0; i < n; i++ )
    {
        cin >> b[i];
        if( a[i] != b[i] )
        {
            p[t++] = i;
        }
    }
    //what_is(t);
    if( t == 1 )
    {
        for( int i =0; i < n; i++ ) c[i] = a[i];
        int ara[1044];
        memset( ara, 0, sizeof ara );
        for( int i = 0; i < n; i++ )
        {
            if( i != p[0] )
                ara[ c[i] ]++;
        }
        for( int i = 1; i <= n; i++ )
            if( ara[i] == 0 )
        {c[p[0]] = i;
        break;

        }

    }
    else
    {
        for( int i =0; i < n; i++ ) c[i] = b[i];
        c[ p[0] ] = b[ p[0] ];
        c[ p[1] ] = a[ p[1] ];

        int f = 1;
        for( int i = 0; i < n && f ; i++ )
        {
            for( int j = i+1; j < n && f; j++ )
            {
                if( c[i] == c[j] )
                {
                    f = 0;

                }
            }
        }
        if( f == 0 )
        {
            c[ p[0] ] = a[ p[0] ];
                    c[ p[1] ] = b[ p[1] ];
        }
    }
    for( int i = 0; i < n; i++ ) cout << c[i] << " ";
    cout << endl;
    return 0;
}



