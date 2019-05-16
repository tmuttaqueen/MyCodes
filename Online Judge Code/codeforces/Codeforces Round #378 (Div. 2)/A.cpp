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
    int prev = -1;
    int ans = -1, flag = 0;
    for( int i = 0; i < s.size(); i++ )
    {

        if( s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'Y' )
        {
            flag = 1;
            ans = max( ans, i - prev );
            prev = i;
        }
    }
    ans = max(ans, (int)s.size() - prev );
    if( flag == 0 )
        ans = s.size() + 1;
    cout << ans << endl;
    return 0;
}



