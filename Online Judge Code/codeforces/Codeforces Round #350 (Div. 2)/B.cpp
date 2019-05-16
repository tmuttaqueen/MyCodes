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
    intl n, k;
    cin >> n >> k;
    intl ara[n+1];
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i+1];
    }
    double p = -1 + sqrt(1.0+8.0*k);
    p /= 2.0;
    //what_is(p);
    intl x = floor(p);
    intl y = x*(x+1)/2;
    //what_is(x);
    intl ans = k - y;
    //what_is(ans);
    if( ans == 0 )
        ans = x;
    cout << ara[ans] << endl;

    return 0;
}



