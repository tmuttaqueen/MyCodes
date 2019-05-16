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
    string s;
    cin >> s;
    int ans = 0;
    s = "a" + s;
    for( int i = 1; i<s.size(); i++ )
    {
        ans += min( abs(s[i] - s[i-1]), abs(26 - abs(s[i] - s[i-1]))  );
        //what_is(ans);
    }
    cout << ans << endl;
    return 0;
}




