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
#define double      long double

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

int pr[11111], f[111111], ara[111111], c;

void sieve()
{
    for( int i = 2; i <= 10000; i++ )
    {
        if( f[i] == 0 )
        {
            pr[c++] = i;
            for( int j = i; j <= 10000; j+=i )
            {
                f[j] = 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    sieve();
    //what_is(c);
    int t;
    cin >> t;
    while(t--)
    {
        int n, dd = 0;
        cin >> n;
        for( int i = 0; i < n; i++ )
        {
            cin >> ara[i];
            if( i > 0 && ara[i] < ara[i-1] )
            {
                dd += ( ara[i-1] - ara[i] );
                ara[i] = ara[i-1];
            }
        }
        int ans = 1000000000;
        for( int i = 0; i < c; i++ )
        {
            int cnt = dd;
            int d = pr[i];
            for( int j = 0; j < n; j++ )
            {
                if( ara[j]%d  )
                {
                    cnt += ( d- (ara[j]%d) );
                }
            }
            ans = min(ans, cnt);
        }
        cout << ans << endl;
    }
    return 0;
}
