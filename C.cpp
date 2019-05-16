#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<intl,intl>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

const intl mod = 1e9+7;

const intl mm[2] = {86027699,982555337}, base[2] = {137, 43};

string no[4] = { "0011", "0101", "1110", "1111" };

set<intl>ss;
string s = " ";
intl hh[3003][3003];
intl dp[3003][3003];
pii occur[3003][3003];
int m;
void precal()
{

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> m;

    for( int i = 1; i <= m; i++ )
    {
        string t ;
        cin >> t ;
        s = s + t;
    }

    for( int i = 1; i <= m; i++ )
    {
        dp[i][i-1] = dp[i][i] = 1;

        for( int j = i-1; j >= 1; j-- )
        {
            intl ans = 0, k = 1;
            while( j-1 <= i-k && k <= 3 )
            {
                ans = (ans+ dp[j][i-k] )%mod;
                k++;
            }
            if( i-k+1 >= 1 )
            {
                string t = s.substr(i-k+1, 4);
                if( t != no[0] && t != no[1] && t != no[2] && t != no[3] )
                {
                    ans = (ans+ dp[j][i-k] );
                }
            }
            //cout <<
            dp[j][i] = ans;
        }

    }
    intl ans = 0;
    for( int i = 1; i <= m; i++ )
    {
        for( int j = 1; j <= i; j++ )
        {
            hh[j][i] = hashVal(j,i);
            if( ss.find( hh[j][i] ) == ss.end())
            {
                ans = (ans+dp[j][i])%mod;
                ss.insert(hh[j][i]);
            }

        }
        cout << ans << endl;
    }


    return 0;
}
