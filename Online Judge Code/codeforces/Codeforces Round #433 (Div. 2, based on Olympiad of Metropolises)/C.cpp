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
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<intl, intl>
#define piii        pair<pii, int>
#define double      long double

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

priority_queue<pii>pq;
intl ara[333333];
intl v[333333];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl n ,k;
    cin >> n >> k;
    for( int i = 1; i <= n; i++ )
    {
        cin >> ara[i];
        if( i <= k )
        {
            pq.push( mp( ara[i], i ) );
        }
    }
    intl ans = 0;
    for( intl i = k+1; i<= n+k; i++  )
    {
        if( i <= n )
        {
            pq.push( mp( ara[i], i ) );
        }
        pii t = pq.top();
        pq.pop();
        ans += ( i - t.yy )*t.xx;
        v[ t.yy ] = i;
    }
    cout << ans << endl;
    for( int i = 1; i <= n; i++ )
    {
        cout << v[i] << ' ';
    }
    cout << endl;
    return 0;
}
