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
    int k = n/7;
    int ans1 = k*2, ans2 = k*2;
    int l = n - k*7;
    if( l == 1 )
        ans1 ++;
    if( l >= 2 )
        ans1 += 2;
    if( l == 6 )
        ans2++;
    cout << ans2 << ' ' << ans1 << endl;
    return 0;
}


