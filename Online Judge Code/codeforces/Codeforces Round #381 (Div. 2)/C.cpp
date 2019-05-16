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
    int n, k, a, b;
    cin >> n >> k;
    int ans = 1e9;
    for( int i = 0; i < k; i++ )
    {
        cin >> a >> b;
        ans = min( ans, b - a + 1 );
    }
    cout << ans << endl;
    cout << 0;
    for( int i = 1; i < n; i++ )
    {
        cout << " " << i%ans;
    }
    cout << endl;
    return 0;
}



