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
#define pii         pair<intl, intl>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 3e5+5;
intl mod = 1e9+9;
intl fib[M];
intl ara[M], sum[M], fsum[M];
pii buffer[M];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    fib[1] = fib[2] = 1;
    fsum[1] = 1;
    fsum[2] = 2;
    for( int i = 3; i < M; i++ )
    {
        fib[i] = ( fib[i-1] + fib[i-2] )%mod;
        fsum[i] = (fib[i] + fsum[i-1])%mod;
    }
    int n, q, mx = 550;
    cin >> n >> q;
    for( int i = 1; i <= n; i++ )
    {
        cin >> ara[i];
        sum[i] = (sum[i-1] + ara[i])%mod;
    }
    int cur = 0;
    while(q--)
    {
        intl type, l, r;
        cin >> type >> l >> r;
        if( type == 1 )
        {
            buffer[cur++]= mp(l, r);
        }
        if( cur == mx )
        {
            for( int i = 1; i <= n; i++ )
            {
                intl add = 0;
                for( int j = 0; j < cur; j++ )
                {
                    if( buffer[j].xx <= i && buffer[j].yy >= i )
                    {
                        (add += fib[i-buffer[j].xx+1])%mod;
                    }
                }
                (ara[i] += add)%mod;
                sum[i] = (ara[i] + sum[i-1])%mod;
            }
            cur = 0 ;
        }
        if( type == 2 )
        {
            intl prev = sum[r] - sum[l-1];
            intl add = 0;
            for( int i = 0; i < cur; i++ )
            {
                if( buffer[i].xx > r || buffer[i].yy < l  ) continue;
                int st = max(l - buffer[i].xx + 1, 1LL);
                int en = max( min( buffer[i].yy, r ) - max( buffer[i].xx, l ), 0LL ) + st;
                //cout << st << ' ' << en << endl;
                (add += fsum[en] - fsum[st-1])%mod;
            }
            (prev += add)%mod;
            cout << (prev + mod)%mod << endl;
        }
    }
    return 0;
}
