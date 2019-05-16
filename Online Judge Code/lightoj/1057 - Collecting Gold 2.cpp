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
char str[50][50];
int ara[20][20];
int cnt;
int dp[65732][20];
vector<pii>vec;
int x, y;
int solve( int bitmask, int last )
{
   // cout << bitmask << " - " << last << " " << endl;
    if( dp[bitmask][last] != -1 )
        return dp[bitmask][last];
    int t = bitmask&( ~(1<<last) );
    int mn;
    if( t == 0 )
    {
        dp[bitmask][last] = max(abs( vec[last].xx - x ), abs( vec[last].yy-y ));
    }
    else
    {
        mn = 1e9;
        for( int i = 0; i < cnt; i++ )
        {
            if( i != last && bitmask&(1<<i) )
            {
                mn = min( mn, solve( t, i ) +  max(abs( vec[i].xx-vec[last].xx ), abs(vec[i].yy-vec[last].yy))  );
            }
        }
        dp[bitmask][last] = mn;
    }
    //cout << "dp: " << bitmask << " " << last << " " << dp[bitmask][last] << endl;
    return dp[bitmask][last];
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        vec.clear();
        memset( dp, -1, sizeof dp );
        int n, m;
        scanf("%d %d", &n, &m);
        for( int i = 0; i < n; i++ )
        {
            scanf("%s", str[i]);
        }
        cnt = -1;
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < m; j++ )
            {
                if( str[i][j] == 'x' )
                {
                    x = i;
                    y = j;
                }
                if( str[i][j] == 'g' )
                {

                    vec.pb( mp(i, j) );
                    cnt++;
                    int d = cnt;
                    for( int k = i; k < n; k++ )
                    {
                        for( int l = (k==i?j+1:0); l < m; l++  )
                        {
                            if( str[k][l] == 'g' )
                            {
                                d++;
                                ara[cnt][d] = max(abs( k-i ), abs(l-j));
                                ara[d][cnt] = ara[cnt][d];
                            }
                        }
                    }
                }
            }
        }
        cnt++;
        for( int i = 0; i < cnt; i++ )
        {
            //cout << vec[i].xx << " " << vec[i].yy << endl;
        }
        int bitmask = 1<<(cnt);
        bitmask--;
        //cout << bitmask << endl;
        int ans = 1e9;
        //memset( dp, 63, sizeof dp );
        for( int i = 0; i < cnt; i++ )
        {
            ans= min( ans, solve(bitmask, i) + max(abs( vec[i].xx-x ), abs(vec[i].yy-y))  );
        }
        if( cnt == 0 ) ans = 0;
        printf("Case %d: %d\n", caseno++, ans);


    }
    return 0;
}
