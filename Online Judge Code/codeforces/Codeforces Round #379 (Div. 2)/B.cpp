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
    int k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6 ;
    intl d = min( k2, min(k5,k6) );
    intl ans = d*256;
    k2 -= d;
    d = min(k3,k2);
    ans += d*32;
    cout << ans << endl;

    return 0;
}



