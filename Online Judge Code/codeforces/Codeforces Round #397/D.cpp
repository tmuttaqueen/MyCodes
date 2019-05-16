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

int ara[100006];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int f = 1, g = 1;
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ )
    {
        cin >> ara[i];
        if( ara[i] != i ) f = 0;
    }
    for( int i = 2; i <= n; i++ )
    {
        if( ara[i] != ara[i-1] ) g = 0;
    }

    if( (f|g) == 0 )
        cout << -1 << endl;
    else
    {
        if( f == 0 && g == 1 )
        {
            cout << 1 << endl ;
            cout << 1;
            for( int i = 1; i < n; i++ )
            {
                cout << " 1";
            }
            cout << endl;
            cout << ara[1] << endl;
        }
        else if( f == 1 && g == 0 )
        {
            cout << n << endl;
            cout << "1";
            for( int i = 2; i <= n; i++ )
            {
                cout << " " << i;
            }
            cout << endl;
            cout << "1";
            for( int i = 2; i <= n; i++ )
            {
                cout << " " << i;
            }
        }
        else if( n == 1 && f == 1 && g == 1 )
        {
            cout << 1 << "\n" << 1 << "\n" << 1 << "\n";
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}



