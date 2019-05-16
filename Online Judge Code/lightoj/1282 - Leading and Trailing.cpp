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

const int mx = 10000000000;

double bigmod1( double x, intl y )
{
    //what_is(y);
    if(y==1)
        return x;
    double dd = bigmod1(x, y/2);
    dd = dd*dd;
    while( dd >= mx )
        dd/=10;
    if( y&1 )
        dd = dd*x;
    while( dd >= mx )
        dd/=10;
    return dd;
}

intl bigmod( intl x, intl y )
{
    if(y==1)
        return x%1000;
    intl dd = bigmod(x, y/2);
    dd = (dd*dd)%1000;
    if( y&1 )
        dd = dd*x;
    return dd%1000;
}

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        intl ans1 = bigmod1(n,k);
        intl ans2 = bigmod(n,k);
        while(ans1 >= 1000)
            ans1/=10;
        printf("Case %d: %03lld %03lld\n", caseno++, ans1, ans2);
    }

    return 0;
}



