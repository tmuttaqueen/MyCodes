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

const int mx = 4;
intl mod = 10007, arr[4][4], temp[4][4];

void multiply( intl ara1[4][4], intl ara2[4][4] )
{
    for( int i = 0; i < mx; i++ )
    {
        for( int j = 0; j < mx; j++ )
        {
            intl sum = 0;
            for( int k = 0; k < mx; k++ )
            {
                sum += ara1[i][k]*ara2[k][j];
            }
            sum %= mod;
            temp[i][j] = sum;
        }
    }

    for( int i = 0; i < mx; i++ )
    {
        for( int j = 0; j < mx; j++ )
        {
            ara1[i][j] = temp[i][j];
        }
    }
}

void power( intl ans[mx][mx], intl x )
{
    if( x == 1 )
        return;
    power(ans, x/2);
    multiply( ans, ans );
    if( x&1 )
    {
        multiply( ans, arr );
    }

}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    memset( arr, 0, sizeof(arr) );
    arr[0][0] = arr[0][1] = arr[0][3] = arr[1][0] = arr[2][2] = arr[3][2] = 1;
    arr[2][0] = 2;
    int t, caseno = 1;
    scanf("%d", &t);
    intl ans[mx][mx];
    while(t--)
    {
        for( int i = 0; i < mx; i++ )
        {
            for( int j = 0; j < mx; j++ )
            {
                ans[i][j] = arr[i][j];
                //cout << ans[i][j] << ' ';
            }
            //cout << endl;
        }

        intl n, anss;
        scanf("%lld", &n);
        if( n == 1 )
        {
            anss = 1;
        }
        else
        {
            power(ans, n-1);
            //debug;
            anss = ans[0][0] + ans[0][1] + 2*ans[0][2];
        }
        anss %= mod;
        printf("Case %d: %lld\n", caseno++, anss);
    }

    return 0;
}


