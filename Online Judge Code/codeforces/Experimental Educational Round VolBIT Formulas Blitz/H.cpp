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
    long long a, ans, t = 120, x;
    cin >> a;
    ans = a*a;
    x = gcd( ans, t );
    t /= x;
    ans /= x;

    ans *= (a-1)*(a-1);
    x = gcd( ans, t );
    t /= x;
    ans /= x;

    ans *= (a-2)*(a-2);
    x = gcd( ans, t );
    t /= x;
    ans /= x;

    ans *= (a-3)*(a-3);
    x = gcd( ans, t );
    t /= x;
    ans /= x;

    ans *= (a-4)*(a-4);
    x = gcd( ans, t );
    t /= x;
    ans /= x;

    cout << ans << endl;

    return 0;
}



