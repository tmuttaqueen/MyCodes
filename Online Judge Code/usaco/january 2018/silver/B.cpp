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
#define filein      freopen("rental.in", "r", stdin)
#define fileout     freopen("rental.out", "w", stdout)
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<intl, intl>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 145678;

intl milk[M], rentPrice[M], premilk[M];
pii milkPrice[M];
intl sumRent[M], sumMilk[M], totPrice[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    filein;
    fileout;
    int n, shop, rent;
    cin >> n >> shop >> rent;
    for( int i = 0; i < n; i++ ) cin >> milk[i];
    sort( milk, milk+n);
    reverse( milk, milk+n );
    for( int i = 0; i < shop; i++ )
        cin >> milkPrice[i].yy >> milkPrice[i].xx;
    sort( milkPrice, milkPrice + shop );
    reverse( milkPrice, milkPrice + shop );
    for( int i = 0; i < rent; i++ )
    {
        cin >> rentPrice[i];
    }
    sort( rentPrice, rentPrice + rent );
    reverse( rentPrice, rentPrice + rent );
    premilk[0] = milk[0];
    for( int i = 1; i < n; i++ )
    {
        premilk[i] = milk[i] + premilk[i-1];
    }
    sumRent[0] = rentPrice[0];
    for( int i = 1; i < rent; i++ )
    {
        sumRent[i] = sumRent[i-1] + rentPrice[i];
    }
    sumMilk[0] = milkPrice[0].yy;
    totPrice[0] = milkPrice[0].yy*milkPrice[0].xx;
    for( int i = 1; i < shop; i++ )
    {
        sumMilk[i] = sumMilk[i-1] + milkPrice[i].yy;
        //cout << i << " " << sumMilk[i] << endl;
        totPrice[i] = milkPrice[i].yy*milkPrice[i].xx + totPrice[i-1];
    }
    intl ans = 0;
    intl sell, r;
    int lim = min(rent, n);
    for( int i = 0; i <= lim; i++ )
    {
        int cow = i-1;
        if( cow < 0 )
            r = 0;
        else
        {
            r = sumRent[cow];
        }
        cow = n - i - 1;
        intl m = 0;
        if( cow >= 0 )
            m = premilk[cow];
        //what_is(m);
        int d = lower_bound( sumMilk, sumMilk + shop, m ) - sumMilk;
        d--;
        if( d >= shop-1 )
        {
            sell = totPrice[shop-1];
        }
        else
        {
            intl rem = m - sumMilk[d];
            sell = totPrice[d];
            sell += milkPrice[d+1].xx*rem;
        }
        //cout << "-> " << sell << " " << r << " " << sell + r << endl;
        ans = max( ans, sell + r );
    }
    cout << ans << endl;
    return 0;
}
