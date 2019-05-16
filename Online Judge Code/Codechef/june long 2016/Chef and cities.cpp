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

const intl mod = 1e9+7;
long double ddivv = 1.0e10;

intl invmod( intl x, intl y )
{
    if( y == 1 )
        return x;
    intl tt = invmod(x, y/2);
    tt = (tt*tt)%mod;
    if( y&1 ) tt = (tt*x)%mod;
    return tt;
}

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int n;
    scanf("%d", &n);
    intl rem[n+5], ara[n+5];
    for( int i  = 1; i <= n; i++ ) scanf("%lld", &ara[i] );
    long double ff[n+5];
    rem[1] = ff[1] = 1;
    for( int i = 1; i <= n; i++ )
    {
        int j = 1+i;
        intl t = ara[1];
        long double d = ara[1];
        while( j <= n )
        {
            //cout << j << ' ';
            t = (t*ara[j])%mod;
            d = (d*ara[j]);
            while( d >= ddivv )
                d /= 10;
            j += i;
        }
        //cout << endl;
        rem[i] = t;
        ff[i] = d;
    }

    int q;
    scanf("%d", &q);
    while(q--)
    {
        intl a, b, val;
        scanf("%lld", &a);
        if( a== 1 )
        {
            scanf("%lld %lld", &b, &val);
            intl prev = ara[b];
            ara[b] = val;
            b--;
            for( int i = 1; i*i <= b; i++ )
            {
                if( b%i == 0 )
                {
                    int x = b/i, y = i;
                    //what_is(x);
                    //what_is(y);
                    if( x != y )
                    {
                        ff[x] = ff[x]/prev;
                        ff[x] = ff[x]*val;
                        while( ff[x] >= ddivv )
                            ff[x]/=10;
                        while( ff[x] <= ddivv )
                            ff[x]*=10;
                        ff[y] = ff[y]/prev;
                        ff[y] = ff[y]*val;
                        while( ff[y] >= ddivv )
                            ff[y]/=10;
                        while( ff[y] <= ddivv )
                            ff[y]*=10;

                        intl iv = invmod(prev, 1e9+5);
                        rem[x] = (rem[x]*iv)%mod;
                        rem[x] = (rem[x]*val)%mod;
                        rem[y] = (rem[y]*iv)%mod;
                        rem[y] = (rem[y]*val)%mod;
                    }
                    else
                    {
                        ff[x] = ff[x]/prev;
                        ff[x] = ff[x]*val;
                        while( ff[x] >= ddivv )
                            ff[x]/=10;
                        while( ff[x] <= ddivv )
                            ff[x]*=10;
                        intl iv = invmod(prev, 1e9+5);
                        rem[x] = (rem[x]*iv)%mod;
                        rem[x] = (rem[x]*val)%mod;
                    }
                }
            }
        }
        else
        {
            scanf("%lld", &b);
            intl ans1 = rem[b];
            long double ans3 = ff[b];
            while( ans3 >= 10 ) ans3/=10;
            intl ans2 = ans3;
            printf("%lld %lld\n", ans2, ans1);
        }
    }



    return 0;
}



