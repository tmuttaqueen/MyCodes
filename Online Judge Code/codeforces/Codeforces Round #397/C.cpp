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
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double


int main()
{
    ios::sync_with_stdio(false);

    //filein;
    intl a, b, k;
    cin >> k >> a >> b;
    intl x = max(a,b);
    intl y = min(a,b);
    if( x < k )
    {
        cout << -1 << endl;
    }
    else if( y < k )
    {
        if( x % k == 0 )
        {
            cout << x/k << endl;
        }
        else
            cout << -1 << endl;
    }
    else
    {
        cout << x/k + y/k << endl;
    }

    return 0;
}



