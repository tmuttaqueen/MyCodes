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
    int n, t1, t2 ;
    long long x = 0, y = 0, xy = 0, ans = 0;
    map<pii, int> mp;
    map<int, int> vx, vy;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        int a, b;
        cin >> a >> b;
        ans += vx[a] + vy[b] - mp[{a,b}];
        vx[a]++;
        vy[b]++;
        mp[{a,b}]++;
    }

    cout << ans << endl;
    return 0;
}



