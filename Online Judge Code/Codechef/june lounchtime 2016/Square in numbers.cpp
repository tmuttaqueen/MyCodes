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
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define ldb        long double

intl gcd( intl a, intl b )
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    ios::sync_with_stdio(false);
    filein;
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        intl ans, ff = 1;
        cin >> n;
        intl ara[n];
        for( int i= 0; i < n; i++  ) cin >> ara[i];
        for( int i = 0; i < n && ff; i++ )
        {
            for( int j = i+1; j < n; j++ )
            {
                if( gcd(ara[i], ara[j]) > 1 )
                {
                    ans = gcd(ara[i], ara[j]);
                    ff = 0;
                    break;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}




