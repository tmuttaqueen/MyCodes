#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;
int a[MAXN], b[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n, lm;
        cin >> n >> lm;
        for( int i = 1; i <= n; i++ ) cin >> a[i];
        for( int i = 1; i <= n ;i++ ) cin >> b[i];
        int ans = 0;
        for( int i = 1; i <= n; i++ )
        {
            for( int j = i; j <= n; j++ )
            {
                int mxa = 0, mxb = 0;
                for( int k = i; k <= j; k++ )
                {
                    mxa = max(a[k], mxa);
                    mxb = max(b[k], mxb);
                }
                if( abs(mxa-mxb) <= lm ) ans++;
            }
        }
        cout << "Case #" << caseno++ << ": " << ans << endl;
    }

    return 0;
}
