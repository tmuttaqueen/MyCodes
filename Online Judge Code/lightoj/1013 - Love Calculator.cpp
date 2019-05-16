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

intl ara[32][32], ans[32][32];
string a, b;
intl l, ll;

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    cin >> t;
    getchar();
    while( t-- )
    {
        getline(cin, a);
        getline(cin, b);
        l = a.length();
        ll = b.length();
        for( int i = 0; i < 32; i++ )
        {
            ara[0][i] = 0;
            ara[i][0] = 0;
            ans[0][i] = 1;
            ans[i][0] = 1;
        }
        for( int i = 1; i <= l; i++ )
        {
            for( int j = 1; j <= ll; j++ )
            {
                if( a[i-1] == b[j-1] )
                {
                    ara[i][j] = ara[i-1][j-1] + 1;
                    ans[i][j] = ans[i-1][j-1];
                }

                else
                {
                    ara[i][j] = max( ara[i][j-1], ara[i-1][j] );

                    if( ara[i][j-1] > ara[i-1][j] )
                    {
                        ans[i][j] = ans[i][j-1];
                    }
                    else if( ara[i][j-1] < ara[i-1][j] )
                    {
                        ans[i][j] = ans[i-1][j];
                    }
                    else
                    {
                        ans[i][j] = ans[i][j-1] + ans[i-1][j];
                    }
                }
                //cout << ara[i][j] << " ";
            }
            //cout << endl;
        }
        cout << "Case #" << caseno++ << ": " << l+ll-ara[l][ll] << " " << ans[l][ll] << endl;
    }

    return 0;
}


