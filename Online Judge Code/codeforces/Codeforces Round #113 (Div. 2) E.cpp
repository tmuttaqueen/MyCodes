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

intl mod = 1000000007;

intl ara[4][4] ={
                {0,1,1,1},
                {1,0,1,1},
                {1,1,0,1},
                {1,1,1,0}};

intl ans[4][4];

void multi( intl a1[4][4], intl a2[4][4] )
{
    intl temp[4][4];
    for( int i = 0; i < 4; i++ )
    {
        for( int j = 0; j < 4; j++ )
        {
            intl sum = 0;
            for( int k = 0; k < 4; k++ )
            {
                sum += a1[i][k]*a2[k][j];
            }
            sum %= mod;
            temp[i][j] = sum;
        }
    }
    for( int i = 0; i < 4; i++ )
    {
        for( int j = 0; j < 4; j++ )
        {
            a1[i][j] = temp[i][j];
        }
    }
    return;
}

void bigmod( intl n )
{
    if( n == 1)
    {
        for( int i = 0; i < 4; i++ )
        {
            for( int j = 0; j < 4; j++ )
            {
                ans[i][j] = ara[i][j];
            }
        }
        return;
    }
    bigmod(n/2);
    multi( ans, ans );
    if( n&1 )
    {
        multi( ans, ara );
    }
    return;
}


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n;
    cin >> n;
    bigmod(n);
    cout << ans[0][0] << endl;
    return 0;
}



