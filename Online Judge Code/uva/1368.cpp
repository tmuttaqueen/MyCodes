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
    int t;
    cin >> t;
    while(t--)
    {
        int temp[26];
        vector<string>vec(60);
        int n, m, d = 0;
        string ans;
        cin >> n >> m;
        for( int i = 0; i < n; i++ )
        {
            cin >> vec[i];
        }

        for( int i = 0; i < m; i++ )
        {
            pair<char, int>mx('A', 0);
            memset( temp, 0, sizeof(temp) );
            for( int j  = 0; j < n; j++ )
            {
                temp[ vec[j][i] - 'A' ]++;
                if( temp[ vec[j][i] - 'A' ] == mx.yy && vec[j][i] < mx.xx )
                {
                    mx = mp(vec[j][i], temp[ vec[j][i] - 'A' ]);
                }
                if( temp[ vec[j][i] - 'A' ] > mx.yy )
                {
                    mx = mp(vec[j][i], temp[ vec[j][i] - 'A' ]);
                }
            }
            ans += mx.xx;
            d += (n-mx.yy);
        }

        cout << ans << "\n" << d << "\n";
    }

    return 0;
}



