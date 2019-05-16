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

string ara[2];

int dp1[M], dp2[M], dp3[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    cin >> ara[0] >> ara[1];
    int n = ara[0].size();
    for( int i = 1; i <= n; i++ )
    {
        dp1[i] = max( dp1[i-1], max( dp2[i-1], dp3[i-1] ) );
        if( ara[0][i] == '0' && ara[1][i-1] == '0' && ara[0][i-1] == '0' )
        {
            dp1[i] = max( dp1[i], 1 + dp3[i-2] );
        }

        dp2[i] = max( dp1[i-1], max( dp2[i-1], dp3[i-1] ) );
        if( ara[1][i] == '0' && ara[1][i-1] == '0' && ara[0][i-1] == '0' )
        {
            dp2[i] = max( dp2[i], 1 + dp3[i-2] );
        }

        dp3[i] = max( dp3[i-1], max( dp1[i], dp2[i] ) );
        if( ara[0][i] == '0' && ara[1][i] == '0' && ara[1][i-1] == '0' )
        {
            dp3[i] = max( dp3[i], 1 + dp1[i-1] );
        }
        if( ara[0][i] == '0' && ara[1][i] == '0' && ara[0][i-1] == '0' )
        {
            dp3[i] = max( dp3[i], 1 + dp2[i-1] );
        }
    }
    cout << dp3[n] << endl;
    return 0;
}
