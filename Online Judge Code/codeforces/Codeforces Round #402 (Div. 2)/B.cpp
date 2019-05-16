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
    int k;
    cin >> k;
    int d = -1,c =0;
    for( int i = s.length()-1; i>= 0; i-- )
    {
        if( s[i] == '0' ) c++;
        if( c == k )
        {
            d = s.length() - i;
            break;
        }
    }
    if( d == -1 )
    {
        cout << s.length() - 1<< endl;
        return 0;
    }
    cout << d - k << endl;

    return 0;
}



