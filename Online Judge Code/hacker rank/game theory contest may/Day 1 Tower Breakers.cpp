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

/*const int mx = 1000005;
int ans[mx];
int temp[mx][20];

void process()
{
    ans[0] = ans[1] = 0;
    for( int i = 1; i <= 1000000; i++ )
    {
        int k = 0;
        while( temp[i][k] == -1 ) k++;
        ans[i] = k;
        for( int j = i+i; j <= 1000000; j+=i )
        {
            temp[j][k] = -1;
        }
    }
}*/

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    //process();
    int t, n, m;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        if( m == 1 )
        {
            cout << 2 << endl;
            continue;
        }
        if( n&1 ) cout << 1 << endl;
        else cout << 2 << endl;
    }

    return 0;
}

