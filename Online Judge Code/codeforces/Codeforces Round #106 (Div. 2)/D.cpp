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

typedef tree < intl, null_type,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

intl dp[800][800][10];
stack<int>st;
map<int,int>mm;

int mod = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n;
    string s;
    cin >> s;
    for( int i = 0; i < s.length(); i++ )
    {
        if( s[i] == '(' )
        {
            st.push(i);
        }
        else
        {
            int d = st.top();
            mm[d] = i;
            st.pop();
            if( i - d == 1 )
            {

            }
            else if( mm[d+1] == i-1 )
            {



            }
            else
            {
                //what_is(d);
                int d1 = d+1, d2 = mm[d1], d3 = d2+1, d4 = mm[d3];
                //cout << d1 << " " << d2 << " " << d3 << " " << d4 << endl;
                while(1)
                {


                    if( d4 == i-1 )
                        break;
                    else
                    {
                        d2 = d4;
                        d3 = d4+1;
                        d4 = mm[d3];
                    }

                }


                //what_is(i);
                //cout << dp[d][i][0] << " " << dp[d][i][1] << " " << dp[d][i][2] << " " << dp[d][i][3] << endl;

            }
        }
    }
    intl ans = 0;
    int l = s.length() - 1;
    if( mm[0] == l )
    {
        ans = (dp[0][l][0] + dp[0][l][1] + dp[0][l][2] + dp[0][l][3])%mod;
    }
    else
    {
        int d1 = 0, d2 = mm[d1], d3 = d2+1, d4 = mm[d3];
        while(1)
        {

            if( d4 == s.length()-1 )
                break;
            else
            {
                d2 = d4;
                d3 = d4+1;
                d4 = mm[d3];
            }
        }

    }

    cout << ans << endl;

    return 0;
}




