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

char s1[100], s2[100], s3[100];
int dp[60][60][60];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%s %s %s", s1, s2, s3);
        int l1 = strlen(s1), l2 = strlen(s2), l3 = strlen(s3);
        //cout <<s1 << endl;

        memset( dp, 0, sizeof dp );
        //if( s1[0] == s2[0] && s2[0] == s3[0] ) dp[0][0][0] = 1;

        for( int i = 1; i <= l1; i++ )
        {
            for( int j = 1; j <= l2; j++ )
            {
                for( int k = 1; k <= l3; k++ )
                {
                    if( s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1] )
                    {
                        dp[i][j][k] = max( max( dp[i-1][j][k], max( dp[i][j-1][k], dp[i][j][k-1] ) ), dp[i-1][j-1][k-1] + 1);
                    }
                    else
                    {
                        dp[i][j][k] =  max( dp[i-1][j][k], max( dp[i][j-1][k], dp[i][j][k-1] ) );
                    }
                    //cout << i << j << k << " " << dp[i][j][k] << endl;
                }
            }
        }
        printf("Case %d: %d\n", caseno++, dp[l1][l2][l3] );
    }
    return 0;
}




