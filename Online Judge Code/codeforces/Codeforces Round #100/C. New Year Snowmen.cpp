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
#define piii        pair<pii, int>

int ara[100005];
bool flag[100005];

int cc = 1e9+7;

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n, ans = 0;
        cin >> n;
        for( int i = 0; i < n; i++ ) cin >> ara[i];
        ara[n] = 1e9+7;
        sort( ara, ara+n+1 );
        memset( flag, 0, sizeof(flag) );
        for( int i = 0; i < n; i++ )
        {
            int v1 = ara[i];
            int *it = upper_bound( ara + i+1, ara+n+1, v1 );
            while( flag[it-ara] == 1 )
            {
                *it = upper_bound( it+1, ara+n+1, v1 );
            }
            if( *it != ara[n] )
                v2 = *it;
            else
                break;

            int j = it-ara;
            *it = upper_bound( ara +j+1, ara+n+1, v2 );
            while( flag[it-ara] == 1 )
            {
                *it = upper_bound( it+1, ara+n+1, v2 );
            }
            if( *it != ara[n] )
                v3 = *it;
            else
                break;
            int k = it-ara;
            if( v1 != v2 && v2 != v3 )
            {
                flag[i] = flag[j] = flag[k] = 1;
            }
        }
    }

    return 0;
}



