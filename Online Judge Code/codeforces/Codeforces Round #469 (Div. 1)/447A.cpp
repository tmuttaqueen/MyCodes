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
#define endl        "\n"
//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;

string s;
vector<int>ans[M];
set<int>zero, one;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int f = 1;
    cin >> s;
    int n = s.length(), z = 0, e = 0;
    for( int i = 0; i < n; i++ )
    {
        if( s[i] == '0' ) z++;
        else e++;
    }
    int tot = 0;
    if( z <= e )
    {
        cout << -1 << endl;
        return 0;
    }
    tot = z - e;
    for( int i = 1; i <= tot; i++ ) one.insert(i);
    for( int i = 0; i < n; i++ )
    {
        if( s[i] == '0' )
        {
            if( one.size() == 0 )
            {
                cout << -1 << endl;
                return 0;
            }
            int a = *one.begin();
            one.erase(a);
            zero.insert(a);
            ans[a].pb(i);
        }
        else
        {
            if( zero.size() == 0 )
            {
                cout << -1 << endl;
                return 0;
            }
            int a = *zero.begin();
            zero.erase(a);
            one.insert(a);
            ans[a].pb(i);
        }
    }
    if( one.size() != 0 )
    {
        cout << -1 << endl;
        return 0;
    }
    cout << tot << endl;
    for( int i = 1; i <= tot; i++ )
    {
        cout << ans[i].size() << " ";
        for( int x: ans[i] )
        {
            cout << x+1 << " ";
        }
        cout << endl;
    }
    return 0;
}
