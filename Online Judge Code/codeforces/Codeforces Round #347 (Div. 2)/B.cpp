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


int main()
{
    ios::sync_with_stdio(false);
    filein;
    int n;
    cin >> n;
    cin.ignore();
    for( int i = 0; i < n; i++ )
    {
        string s;
        cin >> s;
        s = s.substr( 4, s.size() );
        if( s.size() == 1 )
        {
            if( s[0] == '9' )
            {
                cout << 1989 << endl;
            }
            else
            {
                cout << 199 << s[0] << endl;
            }
        }
        if( s.size() == 2 )
        {
            if( s == "99" )
            {
                cout << 1999 << endl;
            }
            else
            {
                cout << 20 << s << endl;
            }
        }
        if( s.size() == 3 )
        {
            cout << 2 << s << endl;
        }
        if( s.size() == 4 )
        {
            if( s[0] >= '3' )
            {
                cout << s << endl;
            }
            else
                cout << 1 << s << endl;
        }
        if( s.size() > 4 )
        {
            if( s[0] >=  )
        }
    }

    return 0;
}



