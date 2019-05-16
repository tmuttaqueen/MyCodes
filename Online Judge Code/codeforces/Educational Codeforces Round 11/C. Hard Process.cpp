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
    int n, k;
    cin >> n >> k;
    int ara[n];
    vector<int>vec;
    for( int i = 0; i < n; i++ ) cin >> ara[i];
    vec.pb(0);
    for( int i = 0; i < n; i++ )
    {
        if( ara[i] == 0 )
        {
            vec.pb(i+1);
        }
    }
    if( (vec.size() - 1) <= k )
    {
        cout << n << endl;
        for( int i = 0; i < n; i++ )
        {
            cout << 1 << " ";
        }
        cout << endl;
        return 0;
    }
    vec.pb(n+1);
    /*for( int i = 0; i < vec.size(); i++ )
    {
        cout << vec[i] << endl;
    }*/
    int ans = 0;
    int ind = 0;
    for( int i = 0; i < (vec.size() - k); i++ )
    {
        int l = i + k + 1;
        if( l < vec.size() )
        {
            if( (vec[l] - vec[i] - 1) > ans )
            {
                ans = vec[l] - vec[i] - 1 ;
                ind = vec[i];
            }
            //what_is(vec[i]);
            //what_is(ans);
        }

    }
    //what_is(ind);
    int c = 0;
    for( int i = ind; c < k && i < n ;i++)
    {
        if( ara[i] == 0 )
        {
            ara[i] = 1;
            c++;
        }
    }
    cout << ans << endl;
    for( int i = 0; i < n; i++ )
    {
        cout << ara[i] << " ";
    }
    cout << endl;
    return 0;
}



