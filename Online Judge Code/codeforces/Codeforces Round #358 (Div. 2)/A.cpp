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

intl aa[5], bb[5];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n, a, b, c, ans = 0;
    cin >> a >> b;
    intl k = a/5, l = b/5;

    for( int i = 1; i <= a; i++ )
        aa[i%5]++;
    for( int i = 1; i <= b; i++ )
        bb[i%5]++;
    ans = aa[0]*bb[0] + aa[1]*bb[4] + aa[2]*bb[3] + aa[3]*bb[2] + aa[4]*bb[1];
    cout << ans << endl;
    return 0;
}


