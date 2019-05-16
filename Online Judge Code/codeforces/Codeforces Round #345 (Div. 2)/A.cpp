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
    int n, m, ans = 0;
    cin >> n >> m;
    while( m > 2 || n > 2)
    {
        if( m < n )
            while( n > 2 )
            {
                m++;
                n -= 2;
                ans++;
                if( n == 0 )
                {
                    ans--;
                    m--;
                    n+=2;
                }
            }
        else
            while( m > 2 )
            {
                n++;
                m -= 2;
                ans++;
                if( m == 0 )
                {
                    ans--;
                    n--;
                    m+=2;
                }
            }
        //what_is(n);
        //what_is(m);
        //what_is(ans);
    }
    if( m == 2 )
        ans++;
    if( n == 2 )
        ans++;
    if( m == 2 && n == 2 )
        ans--;
    cout << ans << endl;

    return 0;
}



