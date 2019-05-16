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
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double
typedef struct touple
{
    int xx,yy,zz;
    touple( int x = 0, int y = 0, int z = 0 ){xx=x; yy=y; zz=z;}
    bool operator<(const touple &a )
    {
        if( xx == a.xx )
		{
            if( yy == a.yy )
                return zz < a.zz;
            return yy < a.yy;
        }
        return xx<a.xx;
    }

} tii;
//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

int dp[3333], ft[3333];
int mm[333];
vector<string>ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    string s;
    cin >> s;
    mm['a'] = 1;
    mm[ 'e' ]= 1;
    mm['i'] = 1;
    mm['o'] = 1;
    mm['u'] = 1;
    int l = s.length();
    ft[0] = -1;
    ft[1] = -1;
    dp[0] = 0;
    dp[1] = 0;
    for( int i = 0; i < l; i++ )
    {
        int c = 0;
        //dp[i] = 10000;
        dp[i] = dp[i-1]+1;
        ft[i] = i-1;
        for( int j  = i; j >= 0; j-- )
        {
            if( i-j >= 2 && mm[ s[j] ] == 0 && mm[ s[j+1] ] == 0 && mm[ s[j+2] ] == 0 && !( s[j] == s[j+1] && s[j+1] == s[j+2] ) )
            {
                //
                //what_is(j);
                break;
            }
            else
            {
                //cout << i << ": " << j << endl;
                if( j > 0 )
                {
                    if( dp[i] > dp[j-1] + 1 )
                    {
                        dp[i] = dp[j-1]+1;
                        ft[i] = j-1;
                    }
                }
                else
                {
                    dp[i] = 0;
                    ft[i] = -1;
                }
            }
        }
        //wcout << i << " " << dp[i] << " " << ft[i] << endl;
    }
    ft[l] = l-1;
    int ss, ee = l-1;
    while(1)
    {
        ss = ft[ee];
        string temp = s.substr( ss+1, ee-ss );
        ans.pb( temp );
        ee = ss;
        if( ee == -1 )
            break;
    }
    reverse( ans.begin(), ans.end() );
    for( int i = 0; i < ans.size() ; i++ )
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}
