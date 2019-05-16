//it took 4 years for me to fall in love again, and you just ignored me, not even bothered to reply any of my text. you are reminding me the pain i endured
//4 years ago
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
    bool a = 1;
    string s;
    cin >> s;
    for( int i = 0; i < s.size() && a; i++ )
    {
        if( s[i] >= 'b' && s[i] <= 'z' )
        {
            while( s[i] >= 'b' && s[i] <= 'z' )
            {
                s[i] -= 1;
                i++;
            }
            a = 0;
        }
    }
    if( a == 1 )
    {
        s[s.size()-1] = 'z';
    }
    cout << s << endl;
    return 0;
}



