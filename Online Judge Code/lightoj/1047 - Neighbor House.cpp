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
    while(t--)
    {
        getchar();
        int n;
        scanf("%d", &n);
        int ara[2][3];
        scanf("%d %d %d", &ara[0][0], &ara[0][1], &ara[0][2]);

        for( int i = 1; i < n; i++ )
        {
            scanf("%d %d %d", &ara[i&1][0], &ara[i&1][1], &ara[i&1][2]);
            ara[i&1][0] += min( ara[(i-1)&1][1], ara[(i-1)&1][2] );
            ara[i&1][1] += min( ara[(i-1)&1][2], ara[(i-1)&1][0] );
            ara[i&1][2] += min( ara[(i-1)&1][0], ara[(i-1)&1][1] );
        }

        printf("Case %d: %d\n",caseno++, min(ara[(n-1)&1][0], min( ara[(n-1)&1][1], ara[(n-1)&1][2] ))  );
    }

    return 0;
}


