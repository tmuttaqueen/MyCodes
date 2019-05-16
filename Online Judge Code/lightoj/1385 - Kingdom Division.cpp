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
#define ldb         long double


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        double a, b, c, p, q=-1;
        scanf("%lf %lf %lf", &a, &b, &c);
        p = a*c/b;
        if( b != p )
            q = (a+p)*(p+c)/(b-p);
        if( q >= 0 )
        {
            printf("Case %d: %.10f\n", caseno++, p+q );
        }
        else
            printf("Case %d: -1\n", caseno++ );
    }

    return 0;
}




