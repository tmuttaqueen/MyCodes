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

unsigned int pr[5800000], flag[3125005], s = 0, pre[5800000];

bool checkbit( int n, int k )
{
    return (bool)(n&(1<<k));
}

int setbit( int n, int k )
{
    return (n|(1<<k));
}

void sieve()
{
    int lim = 10005;
    pr[s++] = 2;
    for( int i = 3; i < lim; i+=2 )
    {
        if( checkbit( flag[i>>5], i&31 ) == 0)
        {
            int k = i<<1;
            for( int j = i*i; j < 100000000; j+=k )
            {
                flag[j>>5] = setbit( flag[j>>5], j&31 );
            }
        }
    }

    for( int i = 3; i < 100000000; i+=2 )
    {
        if( checkbit( flag[i>>5], i&31 ) == 0 )
            pr[s++] = i;
    }
    pre[0] = 2;
    for( int i = 1; i < s; i++ )
        pre[i] = pre[i-1]*pr[i];
    pre[s] = pre[s-1];

    return;
}


int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    sieve();
    /*for( int i = 0; i < 10; i++ )
    {
        cout << pre[i] << " " << pr[i] << endl;
    }*/
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        unsigned int ans;
        int a;
        scanf("%d", &a);
        int n = lower_bound( pr, pr+s, a ) - pr;
        //what_is(n);
        if( pr[n] == a  )
            ans = pre[n];
        else
            ans = pre[n-1];
        //what_is(ans);
        int sq = sqrt(a) + 1;
        for( int i = 0; pr[i] <= sq; i++ )
        {
           unsigned int d = 1, temp = a/pr[i];
           while( temp >= pr[i] )
           {
               temp /= pr[i];
               d *= pr[i];
           }
           ans *= d;
        }
        printf("Case %d: %u\n", caseno++, ans);
    }
    return 0;
}



