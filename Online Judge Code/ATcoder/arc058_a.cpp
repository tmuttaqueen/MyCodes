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
int n, sz, allow[12], k;

int dijktra()
{
    queue<int>pq;
    pq.push(0);
    while( !pq.empty() )
    {
        int d = pq.front();
        if( (-d) >= n ) return -d;
        pq.pop();
        for( int i = 0; i < sz; i++ )
        {
            int z = allow[i];
            if( d == 0 && z == 0 ) continue;
            pq.push( -((-d)*10+z ));
        }
    }
}

int ara[12];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int a;
    cin >> n >> k;
    for( int i = 0; i < k; i++ )
    {
        cin >> a;
        ara[a] = 1;
    }
    for( int i = 0; i < 10; i++)
    {
        if( ara[i] == 0 )
        {
            allow[sz++] = i;
        }
    }
    int ans = dijktra();
    cout << ans << endl;
    return 0;
}
