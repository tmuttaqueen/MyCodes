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

map<int,int>mm;
int cnt[M], inv[M], ara[M];
set<int>ss;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, k;
    cin >> n >> k;
    for( int i = 1; i <= n; i++ )
    {
        cin >> ara[i];
        mm[ ara[i] ];
    }
    int tot = 1;
    for( auto it = mm.begin(); it != mm.end(); it++ )
    {
        it->yy = tot;
        inv[tot++] = it->xx;
    }
    for( int i = 1; i <= n; i++ )
    {
        ara[i] = mm[ ara[i] ];
    }


    for( int i = 1; i <= k; i++ )
    {
        if( cnt[ ara[i] ] == 0 )
        {
            ss.insert( ara[i] );
            cnt[ ara[i] ]++;
        }
        else
        {
            ss.erase( ara[i] );
            cnt[ ara[i] ]++;
        }
    }
    for( int i = k+1; i <= n; i++ )
    {
        if( !ss.empty() )
        {
            auto it = ss.end();
            it--;
            int ans = inv[ *it ];
            cout << ans << endl;
        }
        else
            cout << "Nothing" << endl;

        ss.erase( ara[i-k] );
        cnt[ ara[i-k] ]--;
        if( cnt[ ara[i-k] ] == 1 ) ss.insert( ara[i-k] );
        if( cnt[ ara[i] ] == 0 )
        {
            ss.insert( ara[i] );
            cnt[ ara[i] ]++;
        }
        else
        {
            ss.erase( ara[i] );
            cnt[ ara[i] ]++;
        }

    }

    if( !ss.empty() )
    {
        auto it = ss.end();
        it--;
        int ans = inv[ *it ];
        cout << ans << endl;
    }
    else
        cout << "Nothing" << endl;

    return 0;
}
