#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("fuck\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define ldb        long double

intl mod = 1e9+7;
intl n, ara[105][105], ans[105][105], temp[105][105], val[105];

void multiply( intl ara1[105][105], intl ara2[105][105] )
{
    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < n; j++ )
        {
            intl s = 0;
            for( int k = 0; k < n; k++ )
            {
                s += (ara1[i][k]*ara2[k][j])%mod;
                s %= mod;
            }
            temp[i][j] = s;
        }
    }
    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < n; j++ )
        {
            ara1[i][j] = temp[i][j];
        }
    }
}

void bigmod(intl q )
{
    if( q == 1 )
        return;
    bigmod(q/2);
    multiply(ans, ans);
    if(q&1)
        multiply(ans, ara);
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl p;
    cin >> n >> p;
    for( int i = 0; i < n; i++ )
        cin >> val[i];
    if( p == 1 )
    {
        cout << n << endl;
        return 0;
    }

    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < n; j++ )
        {
            intl d = __builtin_popcountll(val[i]^val[j]);
            if( d%3==0 )
            {
                ara[i][j] = ans[i][j] = 1;

            }
        }
    }

    /*for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < n; j++ )
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }*/

    bigmod(p-1);
    /*cout << endl;
    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < n; j++ )
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }*/
    intl sum = 0;
    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < n; j++ )
        {
            sum += ans[i][j];
            //what_is(sum);
            sum %= mod;
        }
    }

    cout << sum << endl;
    return 0;
}




