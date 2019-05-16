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

const int MAXN = 1000005, inf = 1e9+5;
const intl INF = 1e18+5;
const ld eps = 1e-9;

int mx[MAXN], mn[MAXN], tmx[MAXN], tmn[MAXN];
int ager[MAXN], porer[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    for( int i = 1; i <= n; i++ )
    {
        int a;
        cin >> a;
        mx[a] = i;
        if(mn[a] == 0)
            mn[a] = i;
    }

    int shuru = 0, shesh = x, prev = 0;

    for( int i = 1; i <= x; i++ )
    {
        if( mn[i]== 0 )
        {
            shuru = i;
        }
        else if( mn[i] > prev )
        {
            shuru = i;
            prev = mx[i];
        }
        else
            break;

    }
    prev = n+1;

    for( int i = x; i >= 1; i-- )
    {
        if( mn[i] == 0 )
        {
            shesh = i;
        }
        else if( mx[i] < prev )
        {
            shesh = i;
            prev = mn[i];
        }
        else
            break;
    }
    cout << shuru << " " << shesh << endl;
    vector<pii> v1, v2;
    v1.push_back( mp(0,0) );
    for( int i = 1; i <= shuru; i++ )
    {
        if( mx[i] == 0 )
        {
            v1.push_back( mp(v1.back().xx, i) );
        }
        else
        {
            v1.push_back( mp(mx[i], i) );
        }
    }
    v2.push_back(mp(n+1,x));
    for( int i = x; i >= shesh; i-- )
    {
        if( mn[i] == 0 )
        {
            v2.push_back( mp(v2.back().xx, i) );
        }
        else
        {
            v2.push_back( mp(mn[i], i) );
        }
    }
    reverse( v2.begin(), v2.end() );
    intl ans  = 0;
    //cout << shuru << " " << shesh << endl;

    for( pii a: v1 ) cout << a.xx << ' ';
    cout << endl;
    for( pii a: v2 ) cout << a.xx << ' ';
    cout << endl;
    for( int i = 0; i < v1.size(); i++ )
    {
        int v = v1[i].xx;
        int ind = upper_bound( v2.begin(), v2.end(), mp(v,i+1 ) ) - v2.begin();
        if( ind == 0 ) ind++;
        ans += ( v2.size() - ind );
    }

    cout << ans << endl;



    return 0;
}

/*
8 10
8 2 2 8 10 4 8 6
*/

