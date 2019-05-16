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

intl ara[123][2]; //starting with 0, starting with 1

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    ara[0][0] = ara[0][1] = 0;
    ara[1][0] = ara[1][1] = 0;
    for( int i = 2; i <= 32; i++ )
    {
        ara[i][0] = ara[i-1][0] + ara[i-1][1];
        ara[i][1] = ara[i][0] + (1LL<<(i-2));
    }

    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        intl n;
        scanf("%lld", &n);
        intl ans = 0, x = 1;
        for( intl i = 32; i >= 0; i-- )
        {
            if( (n&(x<<i)) == 0 )
                continue;
            else
            {
                //cout << i << endl;
                ans += ara[i+1][0];
                if( (n&(x<<(i+1))) )
                {
                    //cout << i;
                    intl d = n>>(i);
                    d <<= i;
                    //cout << " - " << d << endl;
                    ans += (n-d+1);
                }
            }
        }
        //if( (n&1) && ( n&2 )) ans++;
        printf("Case %d: %lld\n", caseno++, ans);
    }
}
