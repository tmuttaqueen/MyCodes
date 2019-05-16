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
    //filein;
    int t;
    cin >> t;
    while( t-- )
    {
        bool x = 1;
        string a, b;
        cin >> a;
        //getchar();
        cin >> b;
        int ara[50];
        memset( ara, 0, sizeof(ara) );
        for( int i = 0; i < a.size(); i++ )
        {
            ara[a[i]-'a'] = 1;
        }
        for( int i = 0; i < b.size(); i++ )
        {
            if( ara[b[i]-'a'] == 1 )
            {
                cout << "Yes\n";
                x = 0;
                break;
            }
        }
        if( x )
            cout << "No\n";
    }

    return 0;
}


