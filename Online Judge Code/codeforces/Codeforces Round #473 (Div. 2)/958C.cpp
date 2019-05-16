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
#define endl        "\n"

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    if( n < 6 )
    {
        cout << -1 << endl;
    }
    else
    {
        for( int i = 2; i <= n-2; i++ )
        {
            cout << 1 << " " << i << endl;
        }
        cout << 2 << " " << n-1 << endl;
        cout << 2 << " " << n << endl;
    }
    for( int i =2 ; i <= n; i++ )
    {
        cout << i-1 << " " << i << endl;
    }
    return 0;
}
