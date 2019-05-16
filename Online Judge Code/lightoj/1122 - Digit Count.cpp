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


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno =1;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        int ara[m][n], vec[n];
        for( int i = 0; i < n; i++ )
        {
            cin >> vec[i];
            ara[0][i] = 1;
        }
        for( int i = 1; i < m; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                long long s = 0;
                for( int k = 0; k < n; k++ )
                {
                    if( abs(vec[k] - vec[j]) <= 2 )
                    {
                        s += ara[i-1][k];
                    }
                }
                ara[i][j] = s;
            }
        }
        long long ans = 0;
        for( int i = 0; i < n; i++ )
        {
            ans += ara[m-1][i];
        }
        cout << "Case "  << caseno++ << ": " << ans << endl;
    }

    return 0;
}



