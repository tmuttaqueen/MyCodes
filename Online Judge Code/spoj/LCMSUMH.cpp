#include <bits/stdc++.h>
using namespace std;
#define MAXL (50000>>5)+1
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5] |= 1<<(x&31))
#define intl long long
#define pb push_back


int mark[50000];
int prime[50000], Pt = 0;
const intl LIM = LLONG_MAX;
intl mod = 1e9+7;

void sieve()
{
    prime[Pt++] = 2;
    int n = 47000;
    for( int i = 3; i <= n; i++ )
    {
        if( mark[i] == 0 )
        {
            prime[Pt++] = i;
            if( i > 10000 )
                continue;
            for( int j = i*i; j <= n; j += i )
                mark[j] = 1;
        }
    }
}

intl mul(unsigned long long a, unsigned long long b, unsigned long long mod)
{
    intl x, res;
    if (a < b) swap(a, b);
    if (!b) return 0;
    if (a < (LIM / b)) return ((a * b) % mod);

    res = 0, x = (a % mod);
    b %= mod;
    while (b)
    {
        if (b & 1)
        {
            res = res + x;
            if (res >= mod) res -= mod;
        }
        b >>= 1;
        x <<= 1;
        if (x >= mod) x -= mod;
    }
    return res%mod;
}

intl expo(intl x, intl n, intl mod)
{
    intl res = 1;
    while (n)
    {
        if (n & 1) res = mul(res, x, mod);
        x = mul(x, x, mod);
        n >>= 1;
    }

    return (res % mod);
}

intl gcd(intl x, intl y)
{
    if (!x || !y)    return x + y;
    intl t;
    while (x%y)
        t = x, x = y, y = t%y;
    return y;
}

int isPrime( long long n )
{
    if( n == 2 )
        return 1;
    if( n % 2 == 0 )
        return 0;
    long long d = n-1;
    while(d%2==0)
    {
        d/=2;
    }
    int test[] = {2,3,5,7,11,13,17,19,23,29};
    for( int i = 0; i < 10; i++ )
    {
        unsigned long long x = test[i]%(n-2), temp = d;
        if(x < 2) x += 2;
        //use mulmod() in exponentiation for n>1e9
        long long a = expo(x,d,n);
        while( temp != n-1 && a != 1 && a != n-1 )
        {
            a = mul(a,a,n);
            temp *= 2;
        }
        if( a != n-1 && temp%2==0 )
            return 0;
    }
    return 1;
}

intl pollard_rho(intl n, intl c)
{
    //cout << "n is  " << n << endl;
    intl x = 2, y = 2, i = 1, k = 2, d;
    while (true)
    {
        x = ( mul(x, x, n) + c);
        if (x >= n)	x -= n;
        d = gcd( abs(x - y), n);
        if (d > 1) return d;
        if (++i == k) y = x, k <<= 1;
    }
    return n;
}

void llfactorize(intl n, vector<intl> &f)
{
    if (n == 1)
        return ;
    if (n < 1e+9)
    {
        for (int i = 0; i < Pt && prime[i]*prime[i] <= n; i++)
        {
            if (n%prime[i] == 0)
            {
                while (n%prime[i] == 0)
                    f.push_back(prime[i]), n /= prime[i];
            }
        }
        if (n != 1)	f.push_back(n);
        return ;
    }
    if (isPrime(n))
    {
        f.push_back(n);
        return ;
    }
    intl d = n;
    for (int i = 2; d == n; i++)
        d = pollard_rho(n, i);
    llfactorize(d, f);
    llfactorize(n/d, f);
}

void factorize( intl n, vector< pair<intl,intl> > &ans )
{
    vector<intl> v;
    llfactorize(n, v);
    sort( v.begin(), v.end() );
    intl a = v[0], b = 1;
    for( int i = 1; i < (int)v.size(); i++ )
    {
        if( v[i] == v[i-1] )
        {
            b++;
        }
        else
        {
            ans.pb( make_pair(a,b) );
            a = v[i];
            b = 1;
        }
    }
    ans.pb( make_pair(a,b) );
}


int main()
{
    sieve();
    int testcase;
    intl n;
    scanf("%d", &testcase);
    while (testcase--)
    {
        scanf("%lld", &n);
        //n = testcase+1;
        if( n == 1 )
        {
            cout << 1 << endl;
            continue;
        }
        vector< pair<intl, intl> >ans;
        factorize( n, ans );
        intl val = 1;
        for( int i = 0; i < (int)ans.size(); i++ )
        {
            pair<intl,intl> a = ans[i];
            intl p = a.first, q = a.second;
            //cout << p << "^" << q << "  ";
            intl d = 1, x = mul( p%mod, (p-1)%mod, mod), r = mul(p%mod, p%mod, mod);
            for( int j = 0; j < q; j++ )
            {
                d = (d+x)%mod;
                x = mul(x, r, mod);
            }
            val = mul(val, d, mod);
        }
        val--;
        val = (val+mod)%mod;
        val = mul( val, expo(2, mod-2, mod), mod );
        val = mul( n%mod, val, mod );
        val = (val+n%mod)%mod;
        /*intl v = 0;
        for( intl i = 1; i <= n; i++ )
        {
            v += i*n/gcd(i,n);
            v %= mod;
        }
        if( v != val )
        {
            cout << "- ----- -- " << n << endl;
        }*/
        cout << val << endl;

    }
    return 0;
}
