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
    intl k, r;
    intl ans = 1;
    cin >> k >> r;
    for( int i = 0; i < 1000000; i++ )
    {
        if( (ans*k - r)%10 == 0 || ans*k%10==0 )
            break;
        ans++;
    }
    cout << ans << endl;

    return 0;
}



