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

intl a[1234], b[1234];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, k1, k2, k;
    cin >> n >> k1 >> k2;
    k = k1+k2;
    for( int i = 0; i < n; i++ )
        cin >> a[i];
    for( int i = 0; i < n; i++ )
        cin >> b[i];
    priority_queue<intl>pq;
    for( int i = 0; i < n; i++ )
    {
        pq.push( abs( a[i]-b[i] ) );
    }
    for( int i = 1; i <= k; i++ )
    {
        intl t = pq.top();
        pq.pop();
        if( t == 0 ) t++;
        else t--;
        pq.push(t);
    }
    intl ans = 0;
    while( !pq.empty() )
    {
        intl t = pq.top();
        pq.pop();
        ans += t*t;
    }
    cout << ans << endl;
    return 0;
}
