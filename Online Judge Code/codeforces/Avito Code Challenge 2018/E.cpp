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
#define piii        pair<pii, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 10002;

bool dp[M][M];

vector<piii>all;
int ans[M];

bool comp( piii &a, piii &b )
{
    if( a.xx.xx == b.xx.xx )
        return a.xx.yy < b.xx.yy;
    return a.xx.xx < b.xx.xx;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, q, a, b, c;
    cin >> n >> q;
    for( int i = 0; i < q; i++ )
    {
        cin >> a >> b >> c;
        all.pb( mp( mp(a,b), c ) );
    }
    sort( all.begin(), all.end(), comp );
    int prev = 0;
    for( int i = 0; i < all.size(); i++ )
    {
        if( all[i].xx.xx <= prev ) continue;
        prev = all[i].xx.yy;
        vector<int>vec;
        vec.pb(0);
        vec.pb( all[i].yy );
        for( int j = i+1; j < all.size(); j++ )
        {
            if( all[i].xx.yy >= all[j].xx.xx )
                vec.pb(all[j].yy);
            else
                break;
        }

        int d = vec.size();
        for( int i = 0; i < d; i++ )
        {
            dp[i][0] = 1;
            for( int j = 1; j <= n; j++ )
                dp[i][j] = 0;
        }
        //dp[0][0] = 1;
        //what_is(i);
        for( int i = 1; i < d; i++ )
        {
            for( int j = 1; j <= n; j++ )
            {
                //cout << i << " " << j << " "<< dp[i][j] << endl;
                dp[i][j] = dp[i-1][j];
                if( j - vec[i] >= 0 && dp[i-1][j- vec[i] ] == 1 )
                {

                    dp[i][j] = 1;
                    ans[j] = 1;

                }
            }
        }
    }
    c = 0;
    for( int i = 1; i <= n; i++ )
    {
        c += ans[i];
    }
    cout << c << endl;
    for( int i = 1; i <= n; i++ )
    {
        if( ans[i] )
            cout << i << " ";
    }
    cout << endl;
    return 0;
}
