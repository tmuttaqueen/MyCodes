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
        intl n, m;
        string s;
        cin >> n >> m;
        if( m < n )
        {
            intl k = n;
            n = m;
            m = k;
        }
        if( n == 1 )
        {
            if( m == 2 ) s = "Yes";
            else s = "No";
        }
        else
        {
            if( n%2==0 || m%2==0 )
                s = "Yes";
            else
                s = "No";
        }
        cout << s << endl;
    }

    return 0;
}


