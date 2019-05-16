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

vector<pii>vec;
int dp[5005][5005];
vector<int>from[5005];
vector<int>tot[5005];
int val[5005];
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    cin >> s;
    //for( int i = 0; i < 1000; i++ ) s = s + "?";
    int n = s.length();
    //what_is(n);
    stack<int>st;
    for( int j = 0; j < n; j++ )
    {
        for( int i = j-1; i >= 0; i-- )
        {
            if( !(s[i] == ')' || s[j] == '(' ) && (( j-1 < i+1 ) || dp[i+1][j-1] == 1)  )
            {
                from[i].pb(j);
                tot[i].pb(1);
                dp[i][j] = 1;
                cout << i << ' ' << j << endl;
            }
        }
    }
    int ans = 0;
    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < tot[i].size(); j++ )
        {
            tot[i][j] += val[i];
            cout << i << ' ' << from[i][j] << " " << tot[i][j] << endl;
            ans += tot[i][j];
        }
        val[i] = 0;
        for( int j = 0; j < from[i].size(); j++ )
        {
            int d = from[i][j]+1;
            val[d] += tot[i][j];
        }
    }

    cout << ans << endl;
    return 0;
}
