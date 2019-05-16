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

map<int,int>mm;
int p[3000000], c[10][500000], x[100], cur[410], col[3000000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n ;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> p[i];
        mm[ p[i] ] = 1;
    }

    for( int i = 0; i < n; i++ )
    {
        int a;
        cin >> a;
        col[i] = a;
        c[a][ x[a] ] = p[i];
        x[a]++;
    }
    for( int i = 0; i < n; i++ )
    {
        int a;
        cin >> a;
        if( col[i] == a ) continue;
        c[a][ x[a] ] = p[i];
        x[a]++;
    }
    for( int i = 1; i <= 3; i++ )
    {
        if( x[i] < 2 ) continue;
        sort( c[i], c[i]+x[i] );
    }

    int m,q;
    cin >> m;
    //what_is(m);
    for( int i = 0; i < m; i++ )
    {
        cin >> q;
        //what_is(q);
        if( cur[q] >= x[q] )
        {
            cout << -1 << " ";
            continue;
        }

        while( cur[q] < x[q] && mm[ c[q][ cur[q] ] ] == 0 )
        {
            cur[q]++;
        }

        if( cur[q] >= x[q] )
        {
            cout << -1 << " ";
        }
        else
        {
            cout << c[q][ cur[q] ] << " ";
            mm[c[q][ cur[q] ] ] = 0;
            cur[q]++;
        }
    }
    return 0;
}




