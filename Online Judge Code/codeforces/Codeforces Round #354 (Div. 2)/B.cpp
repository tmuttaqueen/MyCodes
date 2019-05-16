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
    int n, t;
    cin >> n >> t;
    if( t == 0 )
    {
        cout << 0 << endl;
        return 0;
    }

    intl ara[15][15], temp[15][15], flag[15][15];
    memset( flag, 0, sizeof(flag) );
    ara[0][0] = 1;
    for( int i = 1; i <= 12; i++)
    {
        for( int j = 0; j <= i; j++ )
        {
            if( j == 0 || j == i )
            {
                ara[i][j] = 1;
            }
            else
                ara[i][j] = ara[i-1][j-1] + ara[i-1][j];
        }
    }
    for( int i = 1; i <= 12; i++)
    {
        for( int j = 0; j <= i; j++ )
        {
            temp[i][j] = 0;
        }
    }
    temp[0][0] = 2;
    t--;
    intl val[12] = {1,2,4,8,16,32,64,128,256,512,1024,2048};
    int ans = 0, s = 0, c = 1;
    flag[0][0] = 1;
    for( int k = 0; k < t; k++ )
    {
        for( int i = 1; i < n; i++ )
        {
            for( int j = 0; j <= i; j++ )
            {
                if( j == 0 && flag[i-1][0] == 1 )
                    temp[i][j]++;
                else if( j == i && flag[i-1][i-1] == 1 )
                    temp[i][j]++;
                else
                {
                    if( flag[i-1][j-1] == 1 )
                        temp[i][j]++;
                    if( flag[i-1][j] == 1 )
                        temp[i][j]++;
                }

            }

            for( int j = 0; j < i; j++ )
            {
                if( temp[i-1][j] >= val[i-1] )
                    flag[i-1][j] = 1;
            }
        }
    }
    ans++;
    for( int i = 1; i < n; i++ )
    {
        for( int j = 0; j <= i; j++ )
        {
            //cout << temp[i][j] << ' ';
            if( temp[i][j] >= val[i] )
                ans++;
        }
        //cout << endl;
            //what_is(i);
            //what_is(ans);
    }
    cout << ans << endl;
    return 0;
}


