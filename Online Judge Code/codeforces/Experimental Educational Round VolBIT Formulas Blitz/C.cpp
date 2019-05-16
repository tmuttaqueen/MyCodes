#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", "stdout")
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>


int main()
{
    //filein;
    int n;
    cin >> n;
    long long ans  = 0, x = 1;
    for( int i = 1; i <=n; i++ )
    {
        x = x*2;
        ans += x;
    }
    cout << ans << endl;
    return 0;
}



