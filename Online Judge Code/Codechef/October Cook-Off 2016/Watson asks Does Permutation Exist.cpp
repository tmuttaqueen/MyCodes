#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

int ara[200006];

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for( int i = 0; i < n; i++ )
        {
            scanf("%d", &ara[i]);
        }
        sort( ara, ara + n );
        int flag = 1;
        for( int i = 1; i < n; i++ )
        {
            if( ara[i] - ara[i-1] > 1 )
                flag = 0;
        }
        (flag == 0)? printf("NO\n"):printf("YES\n");

    }


    return 0;
}




