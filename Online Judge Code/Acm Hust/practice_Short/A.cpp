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
const int M = 35;
intl mod = 1e9+7;

int t, n, m, l, r, tot;
intl ara[M][M], sol[M][M];
int pos[1001];
int gcd[1001][1001], divv[1000];

void multiply( intl a[M][M], intl b[M][M] )
{
    intl temp[M][M];
    for( int i = 0; i < tot; i++ )
    {
        for( int j = 0; j < tot; j++ )
        {
            intl s = 0;
            for( int k = 0; k < tot; k++ )
            {
                s += (a[i][k]*b[k][j])%mod;
                s %= mod;
            }
            temp[i][j] = s;
        }
    }
    for( int i = 0; i < tot; i++ )
    {
        for( int j = 0; j < tot; j++ )
        {
            a[i][j] = temp[i][j];
        }
    }
}

void expo( int n )
{
    if( n == 0 )
    {
        return;
    }
    expo(n/2);
    multiply( sol, sol );
    if(n&1)
        multiply(sol, ara);
}

int GCD( int a, int b )
{
    if(b==0) return a;
    return GCD(b,a%b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    for( int i = 0; i <= 1000; i++ )
    {
        gcd[i][i] = i;
        for( int j = i+1; j <= 1000; j++ )
        {
            gcd[i][j] = ((i == 0)?j: gcd[i][j-i]);
            gcd[j][i] = gcd[i][j];
        }
    }

    cin >> t;
    while(t--)
    {
        cin >> n >> m >> l >> r;
        intl ans = 0;
        for( int x = l; x <= r; x++ )
        {
            memset( pos, -1, sizeof pos );
            memset( ara, 0, sizeof ara );
            memset( sol, 0, sizeof sol );
            tot = 0;
            for( int i = 1; i <= x; i++ )
            {
                if( x%i == 0 )
                {
                    pos[i] = tot;
                    divv[tot++] = i;
                }
            }
            for( int i = 0; i < tot; i++ )
            {
                sol[i][i] = 1;
                int d = divv[i];
                for( int j = 1; j <= m; j++ )
                {
                    int g = gcd[d][j];
                    int to = d*gcd[j/g][x/d];//GCD(x, p);
                    ara[pos[to]][i]++;
                }
            }

            expo(n);

            ans += sol[tot-1][0];
            if(ans>mod) ans -= mod;
            //debug;

        }
        cout << (ans%mod+mod)%mod << endl;
    }

    return 0;
}

