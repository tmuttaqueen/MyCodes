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
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double
typedef struct touple
{
    int xx,yy,zz;
    touple( int x = 0, int y = 0, int z = 0 ){xx=x; yy=y; zz=z;}
    bool operator<(const touple &a )
    {
        if( xx == a.xx )
		{
            if( yy == a.yy )
                return zz < a.zz;
            return yy < a.yy;
        }
        return xx<a.xx;
    }

} tii;
//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 111, mod = 1e9+7;

int cnt[10];
intl ara[111][111];
intl n, b, k, x, a;
 intl temp[M][M];

void multiply( intl P[M][M], intl Q[M][M] )
{
    intl T[x][x];
    for( int i = 0; i < x; i++ )
    {
        for( int j = 0; j < x; j++ )
        {
            intl ans = 0;
            for( int k = 0; k < x; k++ )
            {
                ans = (ans+ P[i][k]*Q[k][j] )%mod;
            }
            T[i][j] = ans;
        }
    }
    for( int i = 0; i < x; i++ )
    {
        for( int j = 0; j < x; j++ )
        {
            P[i][j] = T[i][j];
        }
    }
}

void power( intl arr[M][M], intl n )
{
    //what_is(n);
    if( n == 1 )
    {
        return;
    }
    power( arr, n/2 );
    multiply( arr, arr );
    if( n%2 )
    {
        multiply( arr, temp );
    }
    return;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    //cin >> b >> x;
    cin >> n >> b >> k >> x;
    for( int i = 0; i < n; i++ )
    {
        cin >> a;
        cnt[a]++;
    }

    for( int i = 0; i < x; i++ )
    {
        for( int j = 0; j < x; j++ )
        {
            intl sum = 0;
            for( int p = 1; p <= 9; p++ )
            {
                if( (j*10+p)%x == i )
                {
                    sum += cnt[p];
                }
            }
            ara[i][j] = sum;
            temp[i][j] = sum;
            //cout << sum << " ";
        }
        //cout << endl;
    }

    power( ara, b );
    cout << ara[k][0]%mod << endl;





    return 0;
}
