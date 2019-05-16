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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl a, b;
    cin >> a >> b;
    while(1)
    {
        if( a == 0 || b == 0 ) break;
        else if( a >= 2*b )
        {
            a = a%(2*b);
        }
        else if( b >= 2*a )
        {
            b = b%(2*a);
        }
        else
            break;
    }
    cout << a << " " << b << endl;
    return 0;
}
