#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", "stdout")
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>


int main()
{
    //filein;
    intl n, a, b, c, ans, x;
    cin >> n >> a >> b >> c;
    if( b - c < a && n >= b )
    {
        //n = c;
        ans = (n-c)/(b-c);
        n -= (b-c)*ans;
        ans += n/a;
    }
    else
    {
        ans = n/a;
    }

    cout << ans << "\n";

    return 0;
}




