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
#define filein      freopen("measurement.in", "r", stdin)
#define fileout     freopen("measurement.out", "w", stdout)
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;

struct data
{
    intl d, id, c;
} ;

data ara[123456];
map<intl, intl>mm;
multiset<intl>ss;
bool comp( data a, data b )
{
    return a.d < b.d;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    //fileout;
    int n;
    intl id, c, init;
    cin >> n >> init;
    int ans = 0;
    char ch;

    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i].d >> ara[i].id >> ch >> c;
        if( ch == '-' ) c = -c;
        ara[i].c = c;
        mm[ara[i].id] = init;
    }
    sort( ara, ara+n, comp );
    for( int i = 0; i < 2*n; i++ )
        ss.insert(init);
    for( int i = 0; i < n; i++ )
    {
        intl pre = mm[ ara[i].id ];
        mm[ ara[i].id ] += ara[i].c;
        intl v = pre+ara[i].c;
        auto it = ss.end();
        it--;
        intl mx = *it;
        /*if( i+1 < n && ara[i+1].d == ara[i].d )
        {
            ss.erase( ss.find(pre) );
            ss.insert(v);
            continue;
        }*/
        if( !(mx > pre && mx > v) )
        {
            ans++;
        }
        ss.erase( ss.find(pre) );
        ss.insert(v);
        /*for( auto it = ss.begin(); it != ss.end(); it++ )
        {
            cout << *it << " ";
        }
        cout << endl;*/
    }
    cout << ans << endl;
    return 0;
}
