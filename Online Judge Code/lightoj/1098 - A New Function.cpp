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


int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        unsigned long long ans, n, sq;
        scanf("%llu", &n);
        ans = n;
        if( n == 0 )
        {
            printf("Case %d: %lld\n", caseno++, ans);
            continue;
        }
        sq = sqrt(n);
        intl prev = n;
        for( int i = 2; i <= sq; i++  )
        {

            unsigned long long temp = n/i;

            ans += (prev*(prev+1)/2 - temp*(temp+1)/2)*(i-1);
            ans += i*temp;
            prev = temp;
        }

        ans += (prev*(prev+1)/2 - sq*(sq+1)/2)*sq;

        ans -= (n+ n*(n+1)/2-1 );
        printf("Case %d: %lld\n", caseno++, ans);
    }

    return 0;
}



