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

long long gcd( long long a, long long b )
{
    if( b == 0 )
        return a;
    return gcd( b, a%b );
}

int main()
{
    //filein;
    long long a, ans = 0, t, x, y;
    cin >> a;
    t = a*(a-1)*(a-2)*(a-3)*(a-4)/120;
    ans += t;
    //what_is(ans);
    x = gcd(6, t);
    t = t/x;
    y = gcd(6/x, a - 5);
    y = (a-5)/y;
    t = t*y;
    ans += t;
    //what_is(ans);
    x = gcd(7, t);
    t = t/x;
    y = gcd(7/x, a - 6);
    y = (a-6)/y;
    t = t*y;
    ans += t;
    //what_is(ans);
    cout << ans << endl;

    return 0;
}



