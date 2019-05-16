#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>

pii vec[2005];
pii vv[500000];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n, l = 0;
        cin >> n;
        for( int i = 0; i < n; i++ )
            cin >> vec[i].xx >> vec[i].yy;
        int ans = 0;
        for( int i = 0; i < n; i++ )
        {
            for( int j = i+1; j < n; j++ )
            {
                int a = vec[i].xx + vec[j].xx, b = vec[i].yy + vec[j].yy;
                vv[l++] = {a,b};
            }
        }
        sort( vv, vv+l );
        for( int i = 0; i < l; )
        {
            int j;
            for( j = i; j < l && vv[i] == vv[j]; j++ );
            ans += (j-i)*(j-i-1);
            i = j;
        }
        //cout << ans << endl;
        ans >>= 1;
        cout << "Case " << caseno++ << ": " << ans << "\n";
    }

    return 0;
}


