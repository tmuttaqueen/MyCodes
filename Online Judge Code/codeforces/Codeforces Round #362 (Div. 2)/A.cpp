

#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("fuck\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define ldb        long double


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl t,s,x;
    cin >> t >> s >> x;
    intl y = (x-t)/s;
    if( x != t && t+s > x )
    {
        cout << "NO\n";
        return 0;
    }


    if( t+y*s == x || t+y*s+1 == x )
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}






