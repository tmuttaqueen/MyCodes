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

typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

///1D BIT O(logn)
const int mx = 200005;
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
    int sum = 0;
    while( x > 0 )
    {
        sum += bit[x];
        x -= (x&(-x));
    }
    return sum;
}

bool comp( piii &a, piii &b )
{
    int d1 = sqrt(a.xx.xx), d2 = sqrt(b.xx.xx);
    if( d1 == d2 )
        return a.xx.yy < b.xx.yy;
    return d1 < d2;
}

piii q[50005];
intl ans[50005];
int ara[200005];
int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, k;
    cin >> n >> k;
    for( int i = 0; i < k; i++ )
    {
        cin >> q[i].xx.xx >> q[i].xx.yy;
        q[i].yy = i+1;
    }
    for( int i = 1; i <= n; i++ ) ara[i] = i;
    //sort( q, q + k, comp );
    int cl = 1, cr = 1;
    intl prev = 0;
    for( int i = 0; i < k; i++ )
    {
        int l = q[i].xx.xx, r = q[i].xx.yy;
        int ind= q[i].yy;
        //cout <<
        what_is(cl);
        what_is(cr);
        while( cr < r )
        {
            update( ara[cr], 1);
            cr++;
        }
        while(cr >= r)
        {
            update( ara[cr], -1);
            cr--;
        }
        while( cl <= l )
        {
            update( ara[cl], -1);
            cl++;
        }
        while(cl > l+1)
        {
            update( ara[cl], 1);
            cl--;
        }
        if( ara[r] > ara[l] )
            ans[ind] = 1;
        else
            ans[ind] = -1;
        int d1 = r - l - 1 - 2*query( ara[l] );
        int d2 = -r + l + 1 + 2*query( ara[r] );
        cout << "qr " << query( ara[r] )<< endl;
        cout << "ql " << query( ara[l] ) << endl;
        ans[ind] += d1 + d2 + prev;
        prev = ans[ind];
        swap( ara[l], ara[r] );
    }

    for( int i = 1; i <= k; i++ )
    {
        cout << ans[i] << endl;
    }




    return 0;
}
