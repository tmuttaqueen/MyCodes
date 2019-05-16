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
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n, ans = 0, a, k =0;
        cin >> n;
        for( int i = 0; i < n; i++ )
        {
            cin >> a;
            if( a == 1 )
                k++;
            ans ^= a;
        }
        if( k == n )
        {
            if( n%2==1 )
                cout << "Case " << caseno++ << ": Bob\n";
            else
                cout << "Case " << caseno++ << ": Alice\n";
            continue;
        }

        if( ans ==0 )
            cout << "Case " << caseno++ << ": Bob\n";
        else
            cout << "Case " << caseno++ << ": Alice\n";
    }

    return 0;
}



