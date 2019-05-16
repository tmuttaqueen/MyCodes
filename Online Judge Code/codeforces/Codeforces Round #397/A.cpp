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
    filein;
    int n, c = 0;
    cin >> n;
    string s, d;
    cin >> d;
    for( int i = 0; i < n; i++ )
    {
        cin >> s;
        //cout << s;
        string s1 = "", s2 = "";
        for( int j = 0; j < 3; j++ )
        {
            s1 += s[j];
            s2 += s[5+j];
        }
        if( s1 != s2 )
            c++;
    }

    if( c%2 )
        cout << "contest\n";
    else
        cout << "home\n";

    return 0;
}




