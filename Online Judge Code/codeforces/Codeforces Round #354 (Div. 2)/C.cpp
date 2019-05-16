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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if( k == 0 )
    {
        int ans = -1, ind = 0;
        for( int i = 1; i < n; i++ )
        {
            if( s[i] != s[i-1] )
            {
                ans = max( ans, i - ind );
                ind = i;
            }
        }
        ans = max( ans, n- ind );
        cout << ans << endl;
        return 0;
    }

    int ans = -1, prev = -1, c = 0, pp;
    vector<int>temp;
    temp.pb(-1);
    for( int i = 0; i < n; i++ )
    {
        if( s[i] == 'b' )
        {
            temp.pb(i);
            if( temp.size() > k+1 )
            {
                ans = max( ans, temp[k+1+c] - temp[c] - 1 );
                c++;
            }
        }
    }

    ans = max( ans, n - temp[c] - 1 );
    prev = -1;
    c = 0;
    temp.clear();
    temp.pb(-1);
    //what_is(ans);
    for( int i = 0; i < n; i++ )
    {
        if( s[i] == 'a' )
        {
            temp.pb(i);
            if( temp.size() > k+1 )
            {
                ans = max( ans, temp[k+1+c] - temp[c] - 1 );
                c++;
            }
        }
    }
    ans = max( ans, n - temp[c] - 1 );

    cout << ans << endl;
    return 0;
}


