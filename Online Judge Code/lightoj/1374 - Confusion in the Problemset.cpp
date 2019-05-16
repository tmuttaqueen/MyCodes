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
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n, a;
        bool flag = true;
        cin >> n;
        bool ara[n];
        memset(ara, 0, sizeof(ara));
        for( int i = 0; i < n; i++ )
        {
            cin >> a;
            if( flag )
            {
                if( a >= n )
                    flag = 0;
                else if( ara[a] == false )
                    ara[a] = 1;
                else if( ara[n-a-1] == false )
                    ara[n-a-1] = 1;
                else
                    flag = 0;

            }
        }
        if( flag )
            cout << "Case " << caseno++ << ": yes\n";
        else
            cout << "Case " << caseno++ << ": no\n";
    }
    return 0;
}



