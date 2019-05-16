#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define xx first
#define yy second
#define intl long long


intl mod = 1e8+7;


string s;
bool dp[1002][1002];
int cnt[1002][1002][26];

string pp[1000002];
int tot;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie();
    int t;
    cin >> t;
    while(t--)
    {

        int n, q;
        cin >> n >> q;
        cin >> s;

        memset( dp, 0, sizeof dp );
        int cur = 0;
        for( int j = 0; j < n; j++ )
        {
            for( int i = j; i >= 0; i-- )
            {
                if( i == j )
                    dp[i][j] = 1;
                else if( s[i] == s[j] && ( j-i == 1 || dp[i+1][j-1] == 1 ) )
                {
                    dp[i][j] = 1;
                }
                if( dp[i][j] )
                {
                    string ss = "";
                    for( int k = i; k <= j; k++ )
                    {
                        ss += s[k];

                    }
                    pp[cur++] = ss;
                }
            }
        }
        sort( pp, pp + cur );

        while(q--)
        {
            int k, ans = 0; char ch;
            cin >> k >> ch;
            k--;
            //cout << pp[k] << endl;
            for( int i = 0; i <  pp[k].size(); i++  )
            {
                if( pp[k][i] == ch )
                    ans++;
            }
            cout << ans << endl;
        }

    }




    return 0;
}
