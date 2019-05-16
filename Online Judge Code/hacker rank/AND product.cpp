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
    int t;
    cin >> t;
    while( t-- )
    {
        intl a, b;
        cin >> a >> b;
        int k = 0;
        while( a != b )
        {
            a /= 2;
            b /= 2;
            k++;
        }
        a <<= k;
        cout << a << endl;
    }

    return 0;
}



