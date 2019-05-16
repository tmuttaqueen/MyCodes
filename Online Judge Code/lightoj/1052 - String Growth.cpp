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

intl mod = 1000000007, f0, f1;
intl arr[2][2] = {1,1,1,0}, ans[2][2], temp[2][2];
bool flag;

void multiply( intl ara1[2][2], intl ara2[2][2] )
{
    for( int i = 0; i < 2; i++ )
    {
        for( int j = 0; j < 2; j++ )
        {
            intl sum = 0;
            for( int k =0 ; k < 2; k++ )
            {
                sum += ara1[i][k]*ara2[k][j];
            }
            sum %= mod;
            temp[i][j] = sum;
        }
    }
    for( int i = 0; i < 2; i++ )
        for( int j = 0; j < 2; j++ )
            ara1[i][j] = temp[i][j];
}

void power( intl ans[2][2], intl x )
{
    if( x == 0 )
    {
        ans[0][1] = 0;
        return;
    }
    if( x == 1 )
        return;
    power(ans, x/2);
    multiply( ans, ans );
    if( x&1)
        multiply( ans, arr );
}

void ispos( intl a1, intl b1, intl c1, intl a2, intl b2, intl c2 )
{
    intl d = a1*b2 - a2*b1, dx = c1*b2 - c2*b1, dy = a1*c2-a2*c1;
    if( d == 0 )
    {
        flag = 0;
        return;
    }
    if( dx%d != 0 || dy%d != 0 )
    {
        flag = 0;
        return;
    }
    f0 = dy/d;
    f1 = dx/d;
    if( f0 > f1 || f0 < 0 || f1 < 0 )
        flag = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        intl n,x,m,y,k, n1, n2, m1, m2;
        scanf("%lld %lld %lld %lld %lld", &n, &x, &m, &y, &k);
        for( int i = 0; i < 2; i++ )
            for( int j = 0; j < 2; j++ )
                ans[i][j] = arr[i][j];

        power(ans, n-1);
        n1 = ans[0][0];
        n2 = ans[0][1];
        for( int i = 0; i < 2; i++ )
            for( int j = 0; j < 2; j++ )
                ans[i][j] = arr[i][j];
        power(ans, m-1);
        m1 = ans[0][0];
        m2 = ans[0][1];
        flag = 1;
        ispos( n1, n2, x, m1, m2, y );
        if( flag )
        {
            f0 = (f0+mod)%mod;
            f1 = (f1+mod)%mod;
            for( int i = 0; i < 2; i++ )
                for( int j = 0; j < 2; j++ )
                    ans[i][j] = arr[i][j];
            power( ans, k-1 );
            intl sol = ans[0][0]*f1 + ans[0][1]*f0;
            sol %= mod;
            printf("Case %d: %lld\n", caseno++, sol);
        }
        else
        {
            printf("Case %d: Impossible\n", caseno++);
        }
    }

    return 0;
}



