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
    int x;
    //filein;
    char a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;
    long long num = 0, mod = 100000;
    num += (b-'0')*1;
    num += (d-'0')*10;
    num += (e-'0')*100;
    num += (c-'0')*1000;
    num += (a-'0')*10000;
    //what_is(num);
    long long ans = 1;
    ans = ans*num;
    ans %= mod;
    ans = ans*num;
    ans %= mod;
    ans = ans*num;
    ans %= mod;
    ans = ans*num;
    ans %= mod;
    ans = ans*num;
    ans %= mod;
    if( ans > 0 )
        x = log10(ans) + 1;
    else
    {
        cout << "00000" << endl;
        return 0;
    }

    if( x < 5 )
    {
        for( int i = 0; i < (5-x); i++ )
            cout << 0;
    }

    cout << ans << endl;

    return 0;
}



