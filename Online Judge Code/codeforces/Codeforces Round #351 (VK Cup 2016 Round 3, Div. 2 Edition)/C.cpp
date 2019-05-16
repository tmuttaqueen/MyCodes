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
    int n;
    cin >> n;
    int ara[n], ans[n] = {};
    for( int i = 0; i < n; i++ ) cin >> ara[i];
    for( int i = 0; i < n; i++ ) ara[i]--;
    for( int i = 0; i < n; i++ )
    {
        int mx = 0, flag[n] = {}, ind = 0;
        for( int j = i; j < n; j++ )
        {
            flag[ara[j]]++;

            if( flag[ara[j]] > mx )
            {
                mx = flag[ara[j]];
                ind = ara[j];
                ans[ind]++;
            }
            else if( flag[ara[j]] == mx && ara[j] < ind )
            {
                mx = flag[ara[j]];
                ind = ara[j];
                ans[ind]++;
            }
            else
            {
                ans[ind]++;
            }
        }
    }

    for( int i = 0; i < n; i++ ) cout << ans[i] << " ";
    cout << endl;

    return 0;
}


