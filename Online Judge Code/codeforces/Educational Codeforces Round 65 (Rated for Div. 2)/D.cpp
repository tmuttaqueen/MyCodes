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

int corres[MAXN];
string col;
string s;
int n;

bool isPosssible( int lim )
{
    int curred = 0, curblue = 0, maxred = lim, maxblue = lim;
    col = "";
    for( int i = 0; i < n; i++ )
    {
        col += '0';
    }
    for( int i = 0; i < n; i++ )
    {
        if( s[i] == ')' )
        {
            if( col[i] == '0' ) maxred++;
            else maxblue++;
        }
        else
        {
            if( maxred > 0 )
            {
                col[i] = '0';
                col[ corres[i] ] = '0';
                maxred--;
            }
            else if( maxblue > 0 )
            {
                col[i] = '1';
                col[ corres[i] ] = '1';
                maxred--;
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;

    cin >> s;
    stack<int>st;
    memset( corres, -1, sizeof corres );
    for( int i = 0; i < n; i++ )
    {
        if( s[i] == '(' )
        {
            st.push(i);
        }
        else
        {
            int d = st.top();
            st.pop();
            corres[d] = i;
        }
    }

    //for( int i = 0; i < n; i++ ) cout << corres[i] << " ";
    int l = 1, r = n;
    string ans = "";
    for( int i = 0; i < n; i++ ) ans += '0';
    while(l <= r)
    {
        int m = (l+r)/2;
        if( isPosssible(m) )
        {
            ans = col;
            r = m - 1;
        }
        else
        {
            l = m+ 1;
        }
    }

    cout << ans << endl;


    return 0;
}
