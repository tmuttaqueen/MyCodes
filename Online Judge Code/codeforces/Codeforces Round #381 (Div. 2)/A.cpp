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
    intl n,a,b,c;
    cin >> n >> a >> b >> c;
    if( n%4 ==0 )
        cout << 0 << endl;
    else if( n%4 == 1 )
    {
        cout << min( min(c, b+a), a*3LL ) << endl;
    }
    else if( n%4 == 2 )
    {
        cout << min( b , min(a*2, c*2)  ) << endl;
    }
    else
        cout << min( min(a, b+c),c*3LL) << endl;

    return 0;
}



