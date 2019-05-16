#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 100005;

int x[MAXN], y[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n, q;
        cin >> n >> q;
        memset( x, 0, sizeof x );
        memset( y, 0, sizeof y );
        for( int i = 0; i < n; i++ )
        {
            int a, b; string s;
            cin >> a >> b >> s;
            if( s[0] == 'N' )
            {
                y[b+1]++;
                y[q+1]--;
            }
            else if( s[0] == 'S' )
            {
                y[0]++;
                y[b]--;
            }
            else if( s[0] == 'E' )
            {
                x[a+1]++;
                x[q+1]--;
            }
            else
            {
                x[0]++;
                x[a]--;
            }
        }
        int mxx = 0, mxy = 0, xx = 0, yy = 0;
        for( int i = 0; i <= q; i++ )
        {
            if( i != 0 )
            {
                x[i] += x[i-1];
                y[i] += y[i-1];
            }
            //cout << i << " " << x[i] << " " << y[i] << endl;
            if( x[i] > mxx )
            {
                mxx = x[i]; xx = i;
            }
            if( y[i] > mxy )
            {
                mxy = y[i]; yy = i;
            }
        }
        cout << "Case #" << caseno++ << ": " << xx << " " << yy << endl;
    }

    return 0;
}

