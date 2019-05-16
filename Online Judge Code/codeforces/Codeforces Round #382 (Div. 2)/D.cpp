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

bool prime(  intl n)
{
    for( intl i = 2; i*i <= n; i++ )
    {
        if( n % i == 0 )
            return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;



        intl n = 2e9-  1;
        //cin >> n;
        cout << n << " ";
        if( prime(n) )
        {
            cout << 1 << endl;
        }
        else if( n%2 == 0 || ((n%2 == 1) && prime(n-2)) )
        {
            cout << 2 << endl;
        }
        else
            cout << 3 << endl;

    return 0;
}



