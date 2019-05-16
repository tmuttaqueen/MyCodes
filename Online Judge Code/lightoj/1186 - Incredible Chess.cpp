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
        int n;
        cin >> n;
        int ara[n];
        for( int i = 0; i < n; i++ )
        {
            cin >> ara[i];
        }
        for( int i = 0; i < n; i++ )
        {
            int a;
            cin >> a;
            ara[i] = a - ara[i] - 1;
            //what_is(ara[i]);
        }
        int ans = 0;
        for( int i =0 ; i  < n; i++ )
        {
            ans ^= ara[i];
        }
        if(ans == 0 )
            cout << "Case "<< caseno++ << ": black wins\n";
        else
            cout << "Case "<< caseno++ << ": white wins\n";
    }

    return 0;
}



