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
    int n,xx,yy;
    int flagx = 1, flagy = 1;
    cin >> n;
    cin >> xx >> yy;
    n--;
    while( n-- )
    {
        int x, y;
        cin >> x >> y;
        if( x != xx )
            flagx = 0;
        if( y != yy )
            flagy = 0;
    }

    if( flagx == 0 && flagy == 0 )
        cout << "NO\n";
    else
        cout << "YES\n";

    return 0;
}



