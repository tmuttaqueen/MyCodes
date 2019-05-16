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

int zero( int n )
{
    int s = 0;
    for( int i = 0; i < 6; i++ )
    {
        if( (n&(1<<i)) == 0)
            s++;
    }
    return s;
}

intl mn = 1e9 +7;

long long int  bigmod ( long long a, intl p, intl m )
{
    if ( p == 0 )return 1; // If power is 0, then a ^ 0 = 1 for any value of a, And 1 Mod m=1 for any value of m, So return 1

    if ( p % 2 ) // If power is odd, Split it : a ^ 5 =( a )* (a ^ 4) --> left and right child respectively.
    {
        return ( ( a % m ) * ( bigmod ( a, p - 1, m ) ) ) % m;
    }
    else //If power is even then split it equally and return the result...
    {
        long long c = bigmod ( a, p / 2, m );
        return ( (c%m) * (c%m) ) % m;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int ara[200] = {};
    int c = 0;
    string s;
    cin >> s;

    for( int i = '0'; i <= '9'; i++ )
    {
        ara[(int)i] = zero( i - '0' );
    }

    for( int i = 'A'; i <= 'Z'; i++ )
    {
        ara[(int)i] = zero( 10+i - 'A' );
    }
    for( int i = 'a'; i <= 'z'; i++ )
    {
        ara[(int)i] = zero( 36+i - 'a' );
    }
    ara[(int)'-'] = zero(62);
    ara[(int)'_'] = zero(63);

    intl ans = 0;

    for( int i = 0; i < s.size(); i++ )
        ans += ara[(int)s[i]];

    //what_is(ans);
    ans = bigmod( 3, ans, mn );
    cout << ans << endl;

    return 0;
}


