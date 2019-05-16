#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        unsigned long long
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

const intl mx = 3000005;

intl lcm[mx], totientSum[mx];
bool flag[mx];

void sieve()
{
    for( intl i = 1; i < mx; i++ ) totientSum[i] = i*i/2;
    for( int i=2; i<mx; i+=2 )
        totientSum[i] /=2;
    for( intl i = 3; i < mx; i+=2 )
    {
        if( flag[i] == 0 )
        {
            for( intl j = i; j < mx; j+=i )
            {
                flag[j] = 1;
                totientSum[j] = totientSum[j]*(i-1)/i;
            }
        }
    }
    for( int i = 1; i < mx; i+=2 ) totientSum[i]++;
    //for( int i =1 ; i < 10; i++ ) cout << totientSum[i] << endl;
    //debug;
    for( int i = 1; i < mx; i++ )
    {
        for( int j = i; j < mx; j+=i )
        {
            lcm[j] += totientSum[j/i];
        }
    }
    //for( int i =1 ; i < 10; i++ ) cout << lcm[i] << endl;
    //debug;
    for( int i = 1; i < mx; i++ )
        lcm[i] *=i;
    for( int i = 1; i < mx; i++ )
        lcm[i] -= i;
    for( int i = 2; i < mx; i++ )
        lcm[i] += lcm[i-1];
    //for( int i =1 ; i < 10; i++ ) cout << lcm[i] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    sieve();
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        printf("Case %d: %llu\n", caseno++, lcm[n] );
    }
    return 0;
}




