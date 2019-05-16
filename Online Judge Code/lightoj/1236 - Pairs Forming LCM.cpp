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

int mx = 10000000;

int pr[1000000];
int c = 0;
bool num[10000002];

void init()
{
    for( int i = 4; i <= mx; i+= 2  ) num[i] = 1;
    int q= sqrt(mx)+1;
    pr[c++] = 2;
    for( int i = 3; i <= q; i+=2 )
    {
        if( num[i]==0 )
        {
            pr[c++] = i;
            for( int j = i*i; j <= mx; j+=i ) num[j] = 1;
        }
    }
    for( int i = q+1; i <= mx; i++ )
        if(num[i]==0) pr[c++] = i;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    init();
    //what_is(c);
    //for(int i = 0; i < 10; i++) cout << pr[i] << " ";
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        intl n;
        scanf("%lld", &n);
        int sq = sqrt(n)+1;
        int i = 0;
        intl ans = 1;
        while( i < c && pr[i] <= n )
        {
            if( n%pr[i] == 0 )
            {
                intl l = 0;
                while( n%pr[i] == 0 )
                {
                    n /= pr[i];
                    l++;
                }
                ans *= (2*l+1);
            }
            i++;
        }
        if( n != 1 )
        {
            ans *= 3;
        }
        printf("Case %d: %lld\n", caseno++, (ans+1)/2 );
    }
    return 0;
}




