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

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

intl ara[111111];
intl cnt[111111];
intl dbl[1111111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl t;
    cin >> t;
    while(t--)
    {
        intl n, k;
        cin>> n >> k;
        ara[0] = 0;
        for( int i = 1; i <= n; i++ )
        {
            cin >> ara[i];
            ara[i] = ara[i]^ara[i-1];
        }
        k--;
        intl ans = 0;
        if( k )
        {
            intl shift = 0;
            for( intl i = 30; i >= 0; i-- )
            {
                if( k&(1<<i) )
                {
                    shift = i+1;
                    break;
                }
            }
            memset( cnt, 0, sizeof cnt );
            cnt[0] = 1;
            for( int i = 1; i <= n; i++ )
            {
                intl d = ara[i]>>shift;
                ans += cnt[d];
                cnt[d]++;
                //what_is(d);
            }
        }
        else
        {
            memset(dbl, 0, sizeof dbl);
            for( int i = 0; i <= n; i++ )
                dbl[ara[i]]++;
            for( int i = 0; i<= 1000000; i++ )
            {
                ans += dbl[i]*(dbl[i]-1)/2;
            }
        }
        cout << ans << endl;

    }

    return 0;
}
