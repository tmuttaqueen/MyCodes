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


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    double p, q, r, ans;
    p = 4.0*c/(pi*a*a);
    if( p < d || (p==d && b == 0)  )
        cout << "NO\n";
    else
    {
        q = p - d;
        ans = b/q;
        printf("YES\n%.10lf\n", ans);
    }
    return 0;
}


