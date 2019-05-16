#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("fuck\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, string>
#define piii        pair<pii, int>
#define ldb         long double

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl ans = 0, n, m, x =1, y=1;
    cin >> n >> m;
    int temp = 1;
    while(temp<n)
    {
        temp*=7;
        if( temp < n )
            x++;
    }
    temp = 1;
    while(temp<m)
    {
        temp*=7;
        if( temp < m )
            y++;
    }
    if( x+y > 7 )
    {
        cout << 0 << endl;
        return 0;
    }

    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < m; j++ )
        {
            int ara[7] = {},p=i, q=j;
            int flag = 1;
            for( int k = 0; k < x; k++ )
            {
                ara[p%7]++;
                if( ara[p%7] > 1 )
                    flag = 0;
                p/=7;
            }
            for( int k = 0; k < y; k++ )
            {
                ara[q%7]++;
                if( ara[q%7] > 1 )
                    flag = 0;
                q/=7;
            }
            if(flag)
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}




