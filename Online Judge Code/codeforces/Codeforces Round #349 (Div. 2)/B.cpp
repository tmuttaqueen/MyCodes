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
    intl mx=-1, sum=0, n;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        intl a;
        cin >> a;
        mx = max(mx, a);
        sum+=a;
    }
    sum -= mx;
    intl t = mx-sum + 1;
    if( t <= 0 )
        t = 1;
    cout << t << endl;
    return 0;
}


