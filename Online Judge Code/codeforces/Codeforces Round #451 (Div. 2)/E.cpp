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

set<intl>sq;
vector< pair<int,int> >ans;
vector<int>vec;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    for( intl i = 0; i <= 31623; i++ )
    {
        sq.insert(i*i);
    }
    int n, a;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> a;
        vec.pb(a);
    }
    for( int i = 0; i < n; i++ )
    {
        a = vec[i];
        int d = sqrt(a);
        int v = min( a - d*d, (d+1)*(d+1)-a  );
        ans.pb( mp(v, a) );
    }
    sort( ans.begin(), ans.end() );
    intl s = 0;
    for( int i = 0; i < n; i++ )
    {
        if( i < n/2 )
        {
            s += ans[i].xx;
        }
        else
        {
            a = ans[i].yy;
            if( a == 0 ) s += 2;
            else if( sq.count(a) ) s++;
        }
    }
    cout << s << endl;
    return 0;
}
