#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;
intl mod = 998244353;

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

long long mulmod( long long a, long long b, long long mod )
{
    long long x = 0, y = a%mod;
    while( b > 0 )
    {
        if(b&1)
            x = (x+y)%mod;
        y = (y*2)%mod;
        b /= 2;
    }
    return x%mod;
}


int is_prime( long long n )
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

    for( int i = 0; i < 10; i++ )
    {
        long long x = 2 + rand()%(n-2), temp = d;
        long long a = exponentiation(x,d,n);
        while( temp != n-1 && a != 1 && a != n-1 )
        {
            a = mulmod(a,a,n);
            temp *= 2;
        }
        if( a != n-1 && temp%2==0 )
            return 0;
    }
    return 1;
}

int totpr;
int pr[MAXN], two[MAXN*10];
bool pp[MAXN*10];

void sieve()
{
    for( int i = 2; i <= 1000000; i++ )
    {
        if( pp[i] == 0 ) pr[totpr++] = i;
        for( int j = i+i; j <= 1000000; j += i )
        {
            pp[j] = 1;
        }
    }

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    two[0] = 1;
    for( int i = 1; i < 2000000; i++ )
    {
        two[i] = two[i-1]<<1;
        if( two[i] >= mod ) two[i] -= mod;

    }
    sieve();
    intl n;
    cin >> n;
    vector<int>power;
    for( int i = 0; i < totpr; i++ )
    {
        int cur = 0;
        while( n%pr[i] == 0 )
        {
            n /= pr[i];
            cur++;
        }
        if(cur) power.push_back(cur);
    }
    if( n > 1 )
    {
        intl rt = sqrt(n*1.0) + 0.5;
        for( intl i = rt - 2; i <= rt + 2; i++ )
        {
            if( i*i == n )
            {
                power.push_back(2);
                n = 1;
            }
        }
    }
    if( n > 1 )
    {
        if( is_prime(n) )
        {
            power.push_back(1);
        }
        else
        {
            power.push_back(1);
            power.push_back(1);
        }
    }
    sort( power.begin(), power.end() );
    for( int x: power ) cout <<x << endl;




    return 0;
}
