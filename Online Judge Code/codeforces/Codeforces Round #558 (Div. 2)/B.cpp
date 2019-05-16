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

multiset<int>ss;
int cnt[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 1;
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ )
    {
        int c;
        cin >> c;
        int p = cnt[c];
        if( p != 0 )
            ss.erase( ss.find(p) );
        ss.insert( ++cnt[c] );
        //cout << i << endl;
        if( ss.size() > 1 )
        {
            auto it = ss.begin();
            int v1 = *it, v2 ;
            it++;
            v2 = *it;
            auto itt = ss.rbegin();
            int l1 = *itt,l2;
            itt++;
            l2 = *itt;
            if( ((l1-v1) == 1 && v1 == l2) || ( v1 == 1 && v2 == l1 ) )
            {
                //cout << i << " " << v1 << " " << v2 << " " << l1 << " " << l2 << endl;
                ans = i;
            }

        }
        else
            ans = i;

        //cout << i << endl;

    }
    cout << ans << endl;
    return 0;
}
