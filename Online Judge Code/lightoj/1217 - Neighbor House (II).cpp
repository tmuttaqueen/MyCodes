#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", "stdout")
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>


int main()
{
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while( t-- )
    {
        int n;
        scanf("%d", &n);
        int ara[n], ara2[n];
        for( int i = 0; i < n; i++ )
        {
            scanf("%d", &ara[i]);
            ara2[i] = ara[i];
        }
        ara[1] = max(ara[0], ara[1]);
        for( int i = 2; i < (n-1); i++ )
        {
            ara[i] = max( ara[i-1], ara[i-2] + ara[i] );
        }
        if( n > 3 )
            ara2[2] = max( ara2[2], ara2[1] );
        for( int i = 3; i < n; i++ )
        {
            ara2[i] = max( ara2[i-1], ara2[i-2] + ara2[i] );
        }
        printf("Case %d: %d\n", caseno++, max( ara[n-2], ara2[n-1] ));
    }
    return 0;
}


