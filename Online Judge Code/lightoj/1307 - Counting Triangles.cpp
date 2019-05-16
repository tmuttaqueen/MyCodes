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

vector<int> ara(2005);

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for( int i = 0; i < n; i++ )
        {
            cin >> ara[i];
        }
        int n1 = n - 2, n2 = n - 1;

        sort( ara.begin(), ara.begin()+n);
        int ans = 0;
        for( int i = 0; i < n1; i++ )
        {
            for( int j = i+1; j < n2; j++ )
            {
                int temp = ara[i] + ara[j];
                temp--;
                vector<int>::iterator low = upper_bound( ara.begin() + j + 1, ara.begin()+n, temp );
                //what_is(*low);
                ans += (low - ara.begin());
                ans -= j;
            }
        }
        ans -= ((n-2)*(n-1))>>1;
        cout << "Case " << caseno++ << ": " << ans << '\n';
    }

    return 0;
}



