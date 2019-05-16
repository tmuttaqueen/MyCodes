#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

typedef tree < intl, null_type,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

int a, dd[104];
int ara[104];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, k;
    cin >> n >> k;
    for( int i = 0; i < n; i++ )
    {
        ara[i+1] = i+1;
        if( i < k )
            cin >> dd[i];
    }
    int s = 1;
    //debug;
    for( int i = 0; i < k; i++ )
    {
        int e = (s+dd[i])%n;
        //what_is(e);
        if( e == 0 )
            e = n;
        //what_is(e);
        cout << ara[e] << " ";
        //e--;
        //what_is(e);
        s = e%n;
        if( s == 0 ) s++;
        //if(  )
        //what_is(s);
        for( int j = e; j < n; j++ )
            ara[j] = ara[j+1];
        n--;
        //for( int i = 1; i <= n; i++ )
           // cout << ara[i] << " ";
           // cout << endl;
        //what_is(n);

    }

    return 0;
}




