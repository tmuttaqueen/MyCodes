#include <bits/stdc++.h>

using namespace std;

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


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, n, d, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &d);
        int ara[n+5];
        for( int i = 0; i < n; i++ ) scanf("%d", &ara[i]);
        deque<pii>mxx, mnn;
        for( int i = 0; i < d; i++ )
        {
            while( !mxx.empty() && mxx.back().xx <= ara[i] )
                mxx.pop_back();
            mxx.push_back(mp(ara[i], i));
            while( !mnn.empty() && mnn.back().xx >= ara[i] )
                mnn.pop_back();
            mnn.push_back(mp(ara[i], i));
        }
        int ans = -1e9;
        for( int i = d; i <= n; i++ )
        {
            while( mxx.front().yy < (i-d) )
                mxx.pop_front();
            int mx = mxx.front().xx;

            while( mnn.front().yy < (i-d) )
                mnn.pop_front();
            int mn = mnn.front().xx;
            ans = max(ans, mx-mn);
            //what_is(mx);
            //what_is(mn);
            if(i==n) break;
            while( !mxx.empty() && mxx.back().xx <= ara[i] )
                mxx.pop_back();
            mxx.push_back(mp(ara[i], i));
            while( !mnn.empty() && mnn.back().xx >= ara[i] )
                mnn.pop_back();
            mnn.push_back(mp(ara[i], i));
        }

        printf("Case %d: %d\n", caseno++, ans);
    }
    return 0;
}




