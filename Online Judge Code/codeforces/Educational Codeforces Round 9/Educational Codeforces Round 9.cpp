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
    vector<string> v(100);
    int n, k;
    cin >> n >> k;
    for( int i =0; i < n; i++ )
    {
        cin >> v[i];
    }
    long long x = 0, a = 0;
    for( int i =  n -1; i >= 0; i-- )
    {
        if( v[i] == "halfplus" )
        {
            x = x*2 + 1;
            a++;
        }

        else
            x *= 2;
    }
    cout << (long long)(x*k - a*(k/2)) << endl;
    return 0;
}



