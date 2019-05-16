#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;
intl mod = 1e9+7;

long long expo( long long a, long long b, long long mod )
{
    long long ans = 1;
    while( b > 0 )
    {
        if( b&1 )
            ans = (a*ans)%mod;
        a = (a*a)%mod;
        b /= 2;
    }
    return ans;
}

intl ara[2][2];

void mul( intl a[2][2], intl b[2][2] )
{
    intl temp[2][2];
    for( int i = 0; i < 2; i++ )
    {
        for( int j = 0; j < 2; j++ )
        {
            intl s = 0;
            for( int k = 0; k < 2; k++ )
                s = s + a[i][k]*b[k][j]%mod;
            s %= mod;
            temp[i][j] = s;
        }
    }
    for( int i = 0; i < 2; i++ )
            for( int j = 0; j < 2; j++ )
                a[i][j] = temp[i][j];
}

void matrixexpo( intl mat[2][2], intl pow )
{
    if( pow == 0 ) return;
    if( pow == 1 )
    {
        for( int i = 0; i < 2; i++ )
            for( int j = 0; j < 2; j++ )
                mat[i][j] = ara[i][j];
        return;
    }
    matrixexpo( mat, pow/2 );
    mul( mat, mat );
    if( pow%2 )
    {
        mul(mat, ara);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t;
    cin >> t;
    while(t--)
    {
        intl d, l, x;
        cin >> l >> d >> x;
        intl c = 2*d*expo( l, mod-2, mod )%mod;
        ara[0][0] = c;
        ara[0][1] = mod-1;
        ara[1][0] = 1;
        ara[1][1] = 0;
        if( x == 1 )
        {
            cout << d << endl;
        }
        else
        {
            intl mat[2][2];
            matrixexpo(mat, x-1);
            intl ans = mat[0][0]*d%mod*expo( l, mod-2, mod )%mod + mat[0][1];
            ans %= mod;
            ans = l*ans%mod;
            cout << ans << endl;
        }
    }
    return 0;
}
