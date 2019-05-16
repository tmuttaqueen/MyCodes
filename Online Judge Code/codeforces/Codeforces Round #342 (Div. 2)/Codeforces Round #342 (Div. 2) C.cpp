#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", "stdout")
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>


int main()
{
    //filein;
    int n, k;
    cin >> n >> k;
    int x = 1;
    k--;
    int ara[n][n];
    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < k; j++ )
        {
            ara[i][j] = x++;
        }
    }
    for( int i = 0; i < n; i++ )
    {
        for( int j = k; j < n; j++ )
        {
            ara[i][j] = x++;
        }
    }
    int sum = 0;
    for( int i = 0 ;i < n; i++ )
    {
        sum += ara[i][k];
    }
    cout << sum << "\n";

    for( int i = 0; i < n; i++ )
    {
        cout << ara[i][0];
        for( int j = 1; j < n; j++ )
        {
            cout << " " << ara[i][j];
        }
        cout << "\n";
    }
    return 0;
}



