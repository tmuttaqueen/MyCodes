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
const int M = 145678;
vector<int>from[M];
int in[M];
int sign[M];
int done[M];
vector<pii>vec;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m;
    cin >> n >> m;
    for( int i = 0; i < n; i++ )
    {
        cin >> sign[i];
        sign[i] = 1-sign[i];
    }
    priority_queue<pii>pq;
    for( int i = 0; i < m; i++ )
    {
        int a, b;
        cin >> a >> b;
        from[b].pb(a);
        in[a]++;
    }
    int ans = 0;
    for( int i = 0; i < n; i++ ) if( in[i] == 0 ) pq.push( mp( sign[i], i ) );
    while( !pq.empty() )
    {
        pii a;
        if( pq.top().xx == 1 )
        {
            a = pq.top();
            pq.pop();
            for( int i = 0 ; i < from[a.yy].size(); i++ )
            {
                in[ from[a.yy][i] ]--;
                if( in[ from[a.yy][i] ] == 0 )
                {
                    pq.push( mp( sign[from[a.yy][i]], from[a.yy][i] ) );
                }
            }
        }
        else
        {
            ans++;
            while( !pq.empty() && pq.top().xx == 0 )
            {
                a = pq.top();
                pq.pop();
                for( int i = 0 ; i < from[a.yy].size(); i++ )
                {
                    in[ from[a.yy][i] ]--;
                    if( in[ from[a.yy][i] ] == 0 )
                    {
                        if( sign[from[a.yy][i]] == 0 )
                            pq.push( mp( sign[from[a.yy][i]], from[a.yy][i] ) );
                        else
                            vec.pb( mp( sign[from[a.yy][i]], from[a.yy][i] ) );
                    }
                }
            }
            for( int i = 0; i < vec.size(); i++ )
                pq.push( vec[i] );
            vec.clear();
        }
    }
    cout << ans << endl;
    return 0;
}
