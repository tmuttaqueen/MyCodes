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
int ara[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) cin >> ara[i];
    sort( ara+1, ara+n+1 );
    int ans = n;
    for( int i = 1; i <= n; i++ )
    {
        int sum = 0;
        for( int j = i; j <= n; j++ ) sum += ara[j];
        sum += (i-1)*5;
        if( 2*sum >= 9*n )
        {
            ans = i-1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
