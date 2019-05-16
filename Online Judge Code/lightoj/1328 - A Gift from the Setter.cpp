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
    int t, caseno =1;
    cin >> t;
    while(t--)
    {
        intl k, c, n;
        cin >> k >> c >> n;
        intl ara[n];
        cin >> ara[0];
        for( int i =1; i < n; i++ ) ara[i] = (k*ara[i-1]+c)%1000007;
        sort( ara, ara+n );
        intl sum = 0;
        intl temp[n];
        temp[0] = ara[0];
        for( int i = 1; i < n; i++ )
        {
            temp[i] = temp[i-1] + ara[i];
        }
        for( int i = 1; i < n; i++ )
        {
            sum += i*ara[i] - temp[i-1];
        }
        cout << "Case " << caseno++ << ": " << sum << endl;
    }

    return 0;
}



