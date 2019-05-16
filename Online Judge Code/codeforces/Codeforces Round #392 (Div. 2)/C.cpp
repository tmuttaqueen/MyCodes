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
    intl n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;
    if( k <= m )
    {
        if( x == 1 && y <= k )
        {
            cout << 1 << " " << 0 << " " << 1 << endl;
        }
        else
        {
            cout << 1 << " " << 0 << " " << 0 << endl;
        }
        return 0;
    }
    k -= m;
    intl d = n*m - m;
    intl mn = k/d;
    intl mx = mn;
    if( k % d != 0 )
        mx++;
    intl s;
    if( x > 1 && x < n )
    {

    }

    if( mn % 2 == 0 )
        mn = mn/2;
    else
        mn = mn/2 + 1;


    cout << mx << " " << mn << " " << s << endl;

    return 0;
}



