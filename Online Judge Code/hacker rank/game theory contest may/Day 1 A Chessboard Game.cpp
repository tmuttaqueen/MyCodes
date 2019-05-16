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

int ans[20][20];

void process()
{
    memset( ans, 0, sizeof(ans) );
    for( int i = 1; i <= 15; i+=4 )
    {
        for( int j = 1; j <= 15; j+=4 )
        {
            ans[i][j] = ans[i][j+1] = ans[i+1][j] = ans[i+1][j+1] = 1;
        }
    }
    /*for( int i = 1; i <=15; i++ )
    {
        for( int j = 1; j <= 15; j++ )
            cout << ans[i][j] << " ";
        cout << endl;
    }*/
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    process();
    int t;
    cin >> t;
    while(t--)
    {
        int x, y;
        cin >> x >> y;
        if( !ans[x][y] ) cout << "First\n";
        else cout << "Second\n";
    }
    return 0;
}


