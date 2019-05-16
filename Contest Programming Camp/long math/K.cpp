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

double dp[1111111];
int pr[1111111], dv[1111111], tot = 0;
int mx = 1000000;
vector<int>vec[1111111];

void sieve()
{
    for( int i = 3; i <= mx; i++ )
        pr[i] = 1;
    pr[2] = 1;
    for( int i = 2; i <= mx; i++ )
    {
        if( pr[i] == 1 )
        {
            vec[i].pb(i);
            for( int j = i+i; j <= mx; j += i )
            {
                pr[j] = 0;
                vec[j].pb(i);
            }
        }
    }
    for( int i = 1; i <= mx; i++ )
        pr[i] += pr[i-1];
    for( int i = 2; i <= mx; i++ )
    {
        double sum = 0;
        int d = vec[i].size();
        for( int j =0; j < d; j++ )
        {
            sum += dp[ i/vec[i][j] ];
        }
        //if( pr[i] > pr[i-1] ) d++;
        //cout << i << " " << sum << " " << pr[i] << " " << d << endl;
        dp[i] = (1.0+ sum/pr[i] )*(double)pr[i]/d ;
        //cout << dp[i] << endl;
        //cout << i << " " << dp[i] << " " << sum << endl;
    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    sieve();
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << "Case " << caseno++ << ": " << setprecision(10) << fixed << dp[n] << "\n";
    }
    return 0;
}
