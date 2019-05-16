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
#define pii         pair<int, int>
#define piii        pair<pii, int>

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int SZ = 1000005, mod = 1000000007;

set<int>ss;
int ara[111];
int ans[111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m, f = 1;
    cin >> n >> m;
    for( int i = 0; i < m; i++ ) cin >> ara[i];
    for( int i = 1; i <= n; i++ ) ss.insert(i);
    if( n == 1 )
    {
        cout << 1 << endl;
        return 0;
    }
    for( int i = 0; i < m-1 && f == 1; i++ )
    {
        int ind = ara[i], next = ara[i+1];
        int diff = next-ind;
        if( diff <= 0 ) diff += n;
        //cout << ind << " next " << next << ' ' << diff << endl;
        if( (ans[ind] != 0 || ss.find(diff) == ss.end()) && ans[ind] != diff )
            f = 0;
        else
        {
            ans[ind] = diff;
            ss.erase(diff);
        }

    }
    if( f ==0  )
    {
        cout << -1 << endl;
    }
    else
    {
        while( !ss.empty() )
        {
            int t = *ss.begin();
            ss.erase( ss.begin() );
            for( int i = 1; i <= n; i++ )
            {
                if( ans[i] == 0 )
                {
                    ans[i] = t;
                    break;
                }
            }
        }
        for(  int i = 1; i <= n; i++ )
        {
            cout << ans[i] << " ";
        }
    }

    return 0;
}



