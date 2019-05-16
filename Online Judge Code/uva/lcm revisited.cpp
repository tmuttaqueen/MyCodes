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

intl gcd( intl a, intl b )
{
    if( b==0 ) return a;
    return gcd( b, a%b );
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n;
    while( scanf("%lld", &n) )
    {
        if( n == 0 ) break;
        intl sn = sqrt(n), d = 0, ans = 0;
        vector<intl>vec;
        //what_is(n);
        //what_is(sn);
        for( int i = 1; i <= sn; i++ )
        {
            if( n%i == 0 )
            {
                vec.pb( i );
                vec.pb(n/i);
                d+=2;
            }
        }
        if( sn*sn == n ) d--;
        //what_is(d);
        for( int i = 0; i < d; i++ )
        {
            //what_is(vec[i]);
            for( int j = i + 1; j < d; j++ )
            {
                intl g = gcd( vec[i], vec[j] );
                //what_is(g);
                if( (vec[i]*vec[j]/g) == n )
                {
                    ans++;
                    //what_is(ans);
                }
            }

        }

        ans++;
        printf("%lld %lld\n", n,  ans);
        //cout << ans << "\n";
    }

    return 0;
}



