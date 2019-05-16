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


int flag[26];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        vector<int>ev, od;
        memset( flag, 0, sizeof flag );
        for( int i = 0; i < s.length(); i++ )
        {
            flag[ s[i] - 'a' ]++;
        }
        for( int i = 0; i < 26; i++ )
        {
            if( flag[i] && i%2 == 0 )
                ev.push_back(i);
            if( flag[i] && i%2 == 1 )
                od.push_back(i);
        }
        int f = 1;
        if( ev.size() == 0 || od.size() == 0 || abs(ev.back() - od[0]) != 1 )
        {

        }
        else
        {
            if( od.size() > 1 && abs(od.back() - ev.back()) != 1 )
            {
                swap( od[0], od[od.size()-1] );
            }
            else if( ev.size() > 1 && abs(od[0] - ev[0]) != 1 )
            {
                swap( ev[0], ev[ev.size()-1] );
            }
            else if( od.size() > 1 && ev.size() > 1 && abs( ev[0] - od.back() ) != 1 )
            {
                swap( od[0], od[od.size()-1] );
                swap( ev[0], ev[ev.size()-1] );
            }
            else
            {
                f = 0;
            }
        }
        if( f )
        {
            for( int x: ev )
            {
                while(flag[x])
                {
                    cout << (char)('a' + x);
                    flag[x]--;
                }
            }
            for( int x: od )
            {
                while(flag[x])
                {
                    cout << (char)('a' + x);
                    flag[x]--;
                }
            }
            cout << endl;
        }
        else
        {
            cout << "No answer" << endl;
        }

    }

    return 0;
}
