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
    ios::sync_with_stdio(0);
    int n, d, h;
    cin >> n >> d >> h;
    if( d > 2*h || d < h || (n > 2 && h == d && h == 1) )
    {
        cout << -1 << "\n";
        return 0;
    }
    if( d == h )
    {
        int a = 1;
        for( int i = 0; i < h; i++ )
        {
            cout << a++ << " " << a << "\n";
        }
        for( int i = 1; i < (n-h); i++ )
        {
            cout << 2 << " " << ++a << "\n";
        }
        return 0;
    }
    int a = 1, temp ;
    for( int i = 0; i < h; i++ )
    {
        cout << a++ << " " << a << "\n";
    }
    cout << 1 << " " << ++a << "\n";
    for( int i = 1; i < (d-h); i++ )
    {
        cout << a++ << " " << a << "\n";
    }

    for( int i = 1; i < (n-d); i++ )
    {
        cout << 1 << " " << ++a << "\n";
    }

    return 0;
}
