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

vector<int> vec(1002);
int n, m;

bool ispos( int a )
{
    int temp = 0, x = 0, i = 0;
    while( i < n )
    {
        temp += vec[i];
        if( temp > a )
        {
            temp = vec[i];
            x++;
        }
        i++;
    }
    x++;
    return (x<=m);
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int ans, h = 0, l=0, mid;
        cin >> n >> m;
        for( int i = 0; i < n; i++ )
        {
            cin >> vec[i];
            h += vec[i];
            if( vec[i] > l )
                l = vec[i];
        }

        while( l <= h )
        {
            mid = (h+l)>>1;
            if( ispos(mid) )
            {
                ans = mid;
                h = mid -1;
            }
            else
                l = mid + 1;
        }

        cout << "Case " << caseno++ << ": " << ans << '\n';
    }

    return 0;
}



