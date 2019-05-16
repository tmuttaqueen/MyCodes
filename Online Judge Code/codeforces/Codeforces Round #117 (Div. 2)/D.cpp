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

typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

string s1, s2;

bool isdiv( int x, int n, string &s1 )
{
    int c = 0;
    for( int i = 0; i < n; i++ )
    {
        if( s1[i] != s1[c++] )
            return 0;
        if(c == x)
            c = 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;

    cin >> s1 >> s2;
    intl l1 = s1.length(), l2 = s2.length();
    intl g = __gcd( l1, l2 );
    intl ans = 0;
    for( int i = 1; i <= g; i++ )
    {
        if( g % i == 0 )
        {
            int f = 1;
            for( int j = 0; j < i; j++  )
            {
                if( s1[j] != s2[j] )
                    f = 0;
            }
            if(f)
                ans += isdiv(i,l1, s1)&( isdiv(i,l2,s2) );
        }
    }
    cout << ans << endl;
    return 0;
}




