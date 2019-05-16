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
    int n, ans = 1;
    cin >> n;
    int ara[n];
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i];
    }
    sort( ara, ara+n );
    vector<int>vec;
    for( int i = 0; i < n-1; i++ )
    {
        if( ara[i] == ara[i+1] )
            ans++;
        else
        {
            vec.pb(ans);
            ans = 1;
        }
    }
    vec.pb(ans);
    ans = 0;
    int n1 = vec.size(), e = n;
    for( int i = 0; i < n1; i++ )
    {
        //what_is(vec[i]);
    }
    while(e)
    {
        e = n1;
        int temp  = 0;
        for( int i = 0; i < n1; i++ )
        {
            if( vec[i] > 0  )
            {
                vec[i]--;
                temp++;
            }

            if( vec[i] == 0 )
            {
                e--;
            }
        }
        ans += temp - 1;

    }

    cout << ans<< endl;

    return 0;
}



