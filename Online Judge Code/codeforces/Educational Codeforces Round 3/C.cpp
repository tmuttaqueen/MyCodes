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
#define piii        pair<pii, int>


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n;
    intl sum = 0;
    cin >> n;
    int ara[n];
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i];
        sum += ara[i];
    }
    sort( ara, ara + n);
    intl low = sum/n, ans = 0;
    intl high = low + 1;
    intl nh = sum - low*n;
    intl nl = n - nh;
    intl left = 0, right = n-1, x=0, y=0;
    for( int i = n-1; i >= 0; i-- )
    {
        if( y < nh )
        {
            y++;
            ans += abs( ara[i]-high );
        }
        else
        {
            ans += abs( ara[i]-low );
        }
    }
    cout << ans/2 << endl;

    return 0;
}



