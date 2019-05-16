#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const intl INF = 1e18;
const int MAXN = 100005;

struct Data
{
    int val,d;
};

bool operator<( const Data &a, const Data &b )
{
    if( a.val == b.val )
        return a.d > b.d;
    return a.val > b.val;
}

vector<pii>s[MAXN], t[MAXN];
pii tt[MAXN];
int n, m ,k;
intl dp[MAXN][205];

intl solve( intl cur, int rem )
{
    if( n+1 == cur )
    {
        dp[cur][rem] = 0;
        return dp[cur][rem];
    }
    if( dp[cur][rem] != INF )
        return dp[cur][rem];
    dp[cur][rem] = min( dp[cur][rem], solve( tt[cur].yy+1, rem) + tt[cur].xx );
    if( rem > 0 )
        dp[cur][rem] = min( dp[cur][rem], solve( cur+1, rem-1 ) );
    //cout << cur << " " << rem << " " << dp[cur][rem] << endl;
    return dp[cur][rem];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    multiset<Data>ss;

    cin >> n >> m >> k;

    for( int i = 0; i <= n; i++ )
    {
        for( int j = 0; j <= m; j++ )
            dp[i][j] = INF;
    }

    for( int i = 0; i < k; i++ )
    {
        int p, q, v, w;
        cin >> p >>  q >> v >> w;
        s[p].pb( mp(w,v) );
        t[q].pb( mp(w,v) );
    }
    for( int i = 1; i <= n; i++ )
    {
        for( pii a: s[i] )
        {
            Data tm;
            tm.val = a.xx;
            tm.d = a.yy;
            ss.insert( tm );
        }
        if( ss.size() == 0 )
        {
            tt[i] = mp(0,i);
            continue;
        }
        Data tm = *ss.begin();
        tt[i] = mp( tm.val, tm.d );
        for( pii a: t[i] )
        {
            Data tm;
            tm.val = a.xx;
            tm.d = a.yy;
            ss.erase( ss.find(tm) );
        }
    }
//    for( int i = 1; i <= n; i++ )
//    {
//        cout << tt[i].xx << " " << tt[i].yy << endl;
//    }

    cout << solve(1, m) << endl;


    return 0;
}

