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
    int n;
    cin >> n;
    int flag = 1, c = 0, a;
    for( int i = 0; i < n; i++ )
    {
        cin >> a;
        if( a%2 )
            c++;
        if( a == 0 || i == n-1 )
        {
            if( c % 2 == 1 )
                flag  = 0;
            c = 0;
        }
    }
    if(flag)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}




