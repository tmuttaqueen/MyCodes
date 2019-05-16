#include<bits/stdc++.h>

using namespace std;

#define ld             long double
#define intl           long long
#define pii            pair<int,int>
#define xx             first
#define yy             second
#define mp             make_pair
#define pb             push_back
#define SZ(x)          (int)(x).size()
#define ALL(x)         begin(x), end(x)
#define REP(i, n)      for (int i = 0; i < n; ++i)
#define FOR(i, a, b)   for (int i = a; i <= b; ++i)
#define RFOR(i, a, b)  for (int i = a; i >= b; --i)

const int MAXN = 300005, inf = 1e9+5;
const intl INF = 1e18+5;
const ld eps = 1e-9;

string s, t, a;

int dp[1005][55][55];

int snext[55][55], tnext[55][55];


int solve( int i, int j, int k )
{
    int v = 0;
    if( j == s.length() - 1 )
    {
        v++;
    }
    if( k == t.length() - 1 )
    {
        v--;
    }
    //cout << "i: " << i << " j: " << j << " k: " << k << " v: " << v << endl;
    if( i >= a.length() )
    {
        //if(v)
            //cout << "00000 " << i << " " << j << " " << k << endl;
        return v;
    }
    int &val = dp[i][j][k];

    if( val != 0x0F0F0F0F ) return val;



    int d = -1e9;
    if( a[i] == '*' )
    {
        for( int p = 0; p < 26; p++ )
        {
            //cout << i << ' ' << j << " " << k << " to " << i+1 << " " << snext[j][p] << " " << tnext[k][p] << endl;
            d = max( d, v + solve( i+1, snext[j][p], tnext[k][p] ) );
        }
    }
    else
    {
        int p = a[i] - 'a';
        d = v + solve( i+1, snext[j][p], tnext[k][p] );
    }
    val = d;
    //cout << i << " " << j << " " << k << " " << val << endl;
    return val;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset( dp, 15, sizeof dp );
    cout << dp[0][0][0] << " " << (int)0x0f0f0f0f << endl;
    cin >> a >> s >>  t;

    a = "#" + a;
    s = "#" + s;
    t = "#" + t;

    snext[0][ s[1] - 'a' ] = 1;
    for( int i = 1; i < s.length(); i++ )
    {
        for( int j = 0; j < 26; j++ )
        {
            snext[i][j] = snext[0][j];
            for( int k = 0; k <= i; k++ )
            {
                string temp = "#";
                for( int l = k; l <= i; l++ )
                {
                    temp += s[l];
                }
                temp += char(j+'a');
                int f = 1;
                for( int l = 0; l < temp.length(); l++ )
                {
                    if( s[l] != temp[l] )
                    {
                        f = 0;
                        break;
                    }
                }
                if( f )
                {
                    snext[i][j] = temp.length() - 1;
                }
            }

            //cout << i << " " << j << " " << snext[i][j] << endl;
        }
    }

    tnext[0][ t[1] - 'a' ] = 1;
    for( int i = 1; i < t.length(); i++ )
    {
        for( int j = 0; j < 26; j++ )
        {
            tnext[i][j] = tnext[0][j];
            for( int k = 0; k <= i; k++ )
            {
                string temp = "#";
                for( int l = k; l <= i; l++ )
                {
                    temp += t[l];
                }
                temp += char(j+'a');
                int f = 1;
                for( int l = 0; l < temp.length(); l++ )
                {
                    if( t[l] != temp[l] )
                    {
                        f = 0;
                        break;
                    }
                }
                if( f )
                {
                    tnext[i][j] = temp.length() - 1;
                }
            }

            //cout << i << " " << j << " " << tnext[i][j] << endl;
        }
    }

    cout << solve(1,0,0) << endl;



    return 0;
}
