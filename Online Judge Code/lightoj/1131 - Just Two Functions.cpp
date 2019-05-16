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


const int mx = 6;
intl mod, arr[mx][mx];
intl temp[mx][mx];

void multiply( intl ara1[mx][mx], intl ara2[mx][mx] )
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
        for( int j = 0; j < mx; j++ )
            ara1[i][j] = temp[i][j];
    return;
}


void power( intl ans[mx][mx], intl x )
{
    //what_is(x);
    if( x == 1 )
    {
        return;
    }
    power( ans, x/2 );
    multiply(ans, ans);
    if( x&1 )
    {
        multiply( ans, arr );
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        intl q, f0, f1, f2, g0, g1, g2, ans[mx][mx];
        memset( arr, 0, sizeof(arr) );
        scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld %lld", &arr[0][0], &arr[0][1], &arr[0][5], &arr[3][3], &arr[3][4], &arr[3][2], &f0, &f1, &f2, &g0, &g1, &g2, &mod);
        arr[1][0] = arr[2][1] = arr[4][3] = arr[5][4] = 1;
        scanf("%lld", &q);
        printf("Case %d:\n", caseno++);

        /*for( int i = 0; i < mx; i++ )
        {
            for( int j = 0; j < mx; j++ )
                cout << arr[i][j] << " ";
            cout << endl;
        }*/
        while(q--)
        {
            intl n, ans1, ans2;
            scanf("%lld", &n);
            for( int i = 0; i < mx; i++ )
                for( int j = 0; j < mx; j++ )
                    ans[i][j] = arr[i][j];

            if( n == 0 )
            {
                ans1 = f0;
                ans2 = g0;
            }
            else if( n == 1 )
            {
                ans1 = f1;
                ans2 = g1;
            }
            else if( n == 2 )
            {
                ans1 = f2;
                ans2 = g2;
            }
            else
            {
                power( ans, n-2 );
                ans1 = ans[0][0]*f2+ans[0][1]*f1+ans[0][2]*f0 + ans[0][3]*g2 + ans[0][4]*g1 + ans[0][5]*g0;
                ans2 = ans[3][0]*f2+ans[3][1]*f1+ans[3][2]*f0 + ans[3][3]*g2 + ans[3][4]*g1 + ans[3][5]*g0;
                //debug;
            }
            ans1 %= mod;
            ans2 %= mod;
            printf("%lld %lld\n", ans1, ans2);
        }
    }

    return 0;
}


