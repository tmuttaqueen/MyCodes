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
#define pii         pair<intl, intl>
#define piii        pair<pii, int>
#define double      long double

pii ara[100005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n;
    intl l = 0, r = 0;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i].xx >> ara[i].yy;
        l += ara[i].xx;
        r += ara[i].yy;
    }
    intl beauty = abs(l-r);
    intl ans = 0;
    for( int i = 0; i < n; i++ )
    {
        intl pl = l, pr = r;
        l = l - ara[i].xx + ara[i].yy;
        r = r - ara[i].yy + ara[i].xx;
        if( beauty < abs(l-r) )
        {
            beauty = abs(l-r);
            ans = i+ 1;
        }
        l = pl;
        r = pr;
    }
    cout << ans << endl;
    return 0;
}



