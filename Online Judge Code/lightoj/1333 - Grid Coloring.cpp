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

intl mod = 1000000000;

long long exponentiation( long long a, long long b, long long mod )
{
    long long ans = 1;
    while( b > 0 )
    {
        if( b&1 )
            ans = (a*ans)%mod;
        a = (a*a)%mod;
        b /= 2;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        vector<pii>vec;
        intl m, n, k, b, x, y;
        scanf("%lld %lld %lld %lld", &m, &n, &k, &b);
        intl all = n, oneless = (m-1)*n;

        for( int i = 0; i < b; i++ )
        {
            scanf("%lld %lld", &x, &y);
            vec.pb( mp(y,x) );
        }
        if( m == 1 )
        {
            printf("Case %d: %lld\n", caseno++, exponentiation(k, all-b, mod ) );
            continue;
        }
        sort( vec.begin(), vec.end() );
        for( int i = 0; i < b; i++ )
        {
            if( vec[i].yy == 1 )
                all--;
            else
                oneless--;
            int j = i+1;
            while( vec[i].xx == vec[j].xx && (vec[j].yy - vec[j-1].yy) == 1 && j < b )
            {
                oneless--;
                j++;
            }
            j--;
            if( vec[j].yy != m )
            {
                oneless--;
                all++;
            }
            i = j;
        }
        intl ans = (exponentiation( k, all, mod )*exponentiation( k-1, oneless, mod ))%mod;
        printf("Case %d: %lld\n", caseno++, ans );
        vec.clear();
    }

    return 0;
}




