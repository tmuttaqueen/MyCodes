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


pii vec[100010];

bool comp( pii a, pii b )
{
    if(a.xx < b.xx)
        return true;
    else if( a.xx == b.xx )
    {
        if( a.yy == 1 )
            return true;
        else
            return false;
    }
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t , caseno = 1;
    cin >> t;
    while( t-- )
    {
        int n, a;
        cin >> n;
        n = n*2;
        for( int i = 0; i < n; i+=2 )
        {
            cin >> vec[i].xx >> vec[i+1].xx;
            vec[i].yy = 1;
            vec[i+1].yy = 2;
        }
        sort( vec, vec+n, comp );

        int ans = 0, s = 0;
        for( int i = 0; i < n; i++ )
        {
            //what_is(vec[i].xx);
            if( vec[i].yy == 1 )
                s++;
            else
                s--;
            ans = max(ans, s);
        }
        cout << "Case " << caseno++ << ": " << ans << "\n";
    }

    return 0;
}



