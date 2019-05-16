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


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n;
    cin >> n;
    intl x = 2, d = 2;
    if( n == 1 )
    {
        cout << "WIN\n";
        return 0;
    }
    if( n == 2 )
    {
        cout << "LOSE\n";
        return 0;
    }
    int flag = 1;
    intl pr, prev = 1;
    while( x < n )
    {
        pr = sqrt(x+d);
        if( pr != prev )
        {
            x += d+1;
            d++;
            prev = pr;
        }
        else
            x += d;
        if(x == n) flag = 0;
        //what_is(x);
    }
    if( flag )
        cout << "WIN\n";
    else
        cout << "LOSE\n";
    return 0;
}




