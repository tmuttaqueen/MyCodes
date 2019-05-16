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
const int M = 100005;

string s;
map<string, int>mm;
vector<int> buy, vec[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m, b, c = 1;
    cin >> n;
    cin >> m;
    for( int i = 0; i < m; i++ )
    {
        cin >> b >> s;
        if( mm[s] == 0 ) mm[s] = c++;
        vec[b].pb( mm[s] );
    }
    for( int i = 0; i < n; i++ )
    {
        sort( vec[i].begin(), vec[i].end() );
    }
    cin >> b;
    int f = 0;
    buy.pb(-1);
    for( int i = 0; i < b; i++ )
    {
        cin >> s;
        buy.pb( mm[s] );
        if( buy[ buy.size()-1 ] == 0 ) f = 1;
    }

    if(f)
    {
        cout << "impossible" << endl;
        return 0;
    }
    int okay = 1, cur = 1;
    for( int i = 0; i < n; i++ )
    {

        if( binary_search( vec[i].begin(), vec[i].end(), buy[cur-1] ) )
        {
            okay = 0;
        }
        while( cur <= b && binary_search( vec[i].begin(), vec[i].end(), buy[cur] ) )
        {
            cur++;
        }
    }
    if( cur < buy.size() )
    {
        cout << "impossible" << endl;
        return 0;
    }
    if( okay == 0 )
        cout << "ambiguous" << endl;
    else
        cout << "unique" << endl;
    return 0;
}
