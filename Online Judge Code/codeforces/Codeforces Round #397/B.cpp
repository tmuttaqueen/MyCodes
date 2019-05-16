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

int ara[50];

int sum( int a, int b )
{

    int s = 0;
    for( int i = a; i<= b; i++ )
    {
        s += ara[i];
    }
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    filein;
    string s;
    cin >> s;
    for( int i = 0; i < s.length(); i++ )
    {
        //cout << sum( 0, s[i] - 'a') << endl;
        int d = sum( 0, s[i] - 'a');
        if( ara[s[i] - 'a'] == 1 ) d--;
        if( d != s[i] - 'a' )
        {
            cout << "NO\n";
            return 0;
        }
        ara[s[i] - 'a'] = 1;
    }

    cout << "YES\n";

    return 0;
}




