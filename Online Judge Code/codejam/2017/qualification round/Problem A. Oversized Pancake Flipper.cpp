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
#define filein      freopen("A-large.in", "r", stdin)
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

char str[2000];

void flip( int a, int k, int len )
{
    for( int i = 0; i < k; i++ )
    {
        if( str[a+i] == '-' ) str[a+i] = '+';
        else str[a+i] = '-';
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    filein;
    fileout;
    int t, k, caseno = 1;
    scanf("%d\n", &t);
    while(t--)
    {
        int ans= 0;
        scanf("%s %d", str, &k);
        //cout << str << " " << k << endl;
        int len = strlen(str);
        for( int i = 0; i <= len - k; i++ )
        {
            if( str[i] == '-' )
            {
                flip(i, k, len);
                ans++;
            }
        }
        int f = 1;
        for( int i = 0;str[i]; i++  )
        {
            if( str[i] == '-' ) f = 0;
        }
        if(f)
        {
            printf("Case #%d: %d\n", caseno++, ans );
        }
        else
            printf("Case #%d: IMPOSSIBLE\n", caseno++);
    }
    return 0;
}




