#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

typedef tree < intl, null_type,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
int ara[100005];
///1D BIT O(logn)
const int mx = 100002;
int bit[mx];
void update( int x, int val ) //add val to index x
{
    while( x <= mx )
    {
        bit[x] += val;
        x += (x&(-x));
    }
}

int query( int x ) //sum from 1 to x (inclusive)
{
    if(x==0) return 0;
    int sum = 0;
    while( x > 0 )
    {
        sum += bit[x];
        x -= (x&(-x));
    }
    return sum;
}


int main()
{
    ios::sync_with_stdio(false);
    __int128_t s;
    //filein;
    int n, q;
    cin >> n >> q;
    for( int i = 1; i <= n; i++ )
    {
        ara[i] = 1;
        update( i, 1 );
    }
    int cl = 1;
    int cr = n;
    for( int i = 0; i < q; i++ )
    {
        //for( int i = cl; i <= cr; i++ ) cout << ara[i] << " ";
        //cout << endl;
        int t;
        cin >> t;
        if( t == 1 )
        {

            int a;
            cin >> a;
            int len = cr - cl + 1;
            if( 2*a <= len )
            {
                int x = cl + a;
                int t = x - 1;
                cl = x;
                for( int i = 0; i < a; i++ )
                {
                    //what_is(x);
                    ara[x] += ara[t];
                    update( x, ara[t] );
                    x++;
                    t--;
                }
            }
            else
            {
                a = len - a;
                int x = cr - a;
                t = x+1;
                cr = x;
                for( int i = 0; i < a; i++ )
                {
                    ara[x] += ara[t];
                    update( x, ara[t] );
                    x--;
                    t++;
                }
            }
        }
        else
        {
            int a, b;
            cin >> a >> b;
            a = cl+a-1;
            b = cl+b-1;
            //what_is(a);
            //what_is(b);
            int q1 = query(b);
            int q2 = query(a);
            //what_is(q1);
            //what_is(q2);
            int ans = q1 - q2;
            cout << ans << endl;
        }
    }
    return 0;
}




