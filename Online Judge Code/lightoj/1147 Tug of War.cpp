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

//typedef tree < intl, null_type,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

bitset<103> bit[100005];
int ara[106];


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        getchar();
        for( int i = 0; i < 100002; i++ ) bit[i].reset();
        int n, s = 0;
        scanf("%d", &n);
        for( int i = 0; i < n; i++ )
        {
            scanf("%d", &ara[i]);
            s += ara[i];
        }
        //sort( ara, ara + n );
        int k = (n+1)/2;
        bit[0][0] = 1;
        bit[ ara[0] ][1] = 1;

        for( int i = 1; i < n; i++ )
        {
            for( int j = s/2-ara[i]; j >= 0; j-- )
            {
                bit[ j+ara[i] ] |= ( bit[j] << 1 );
            }
        }
        for( int i = s/2; i >= 0; i-- )
        {
            if( n % 2 == 0 && bit[i][k] == 1 )
            {
                printf("Case %d: %d %d\n", caseno++, i, s - i );
                break;
            }
            else if( n%2 == 1 && (bit[i][k] == 1 || bit[i][k-1] == 1) )
            {
                printf("Case %d: %d %d\n", caseno++, i, s - i );
                break;
            }

        }

        //printf("Case %d: %d %d\n", caseno++, min( ans, s - ans ), max( ans, s - ans ) );
        //for( int i = 1; i <= k; i++ ) ss[i].clear();
    }
    return 0;
}




