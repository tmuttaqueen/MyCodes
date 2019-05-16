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
    while(t--)
    {
        int n, m, ans = 0, flag = 0;
        cin >> n;
        int c = n;
        while(c--)
        {
            cin >> m;
            ans ^= m;
            if(m>1) flag = 1;
        }
        if( flag )
        {
            if( ans ) cout << "First\n";
            else cout << "Second\n";
        }
        else
        {
            if(n&1) cout << "Second\n";
            else cout << "First\n";
        }
    }

    return 0;
}


