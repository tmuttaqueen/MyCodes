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
map<string,  vector<string> >mm;
vector<string> ans;
bool comp( string &a, string &b )
{
    return a.size() < b.size();
}

bool isSuffix( string &a, string &b )
{
    int r = b.size()-1;
    for( int i = a.size()-1; i >= 0; i-- )
    {
        if( a[i] != b[r--] )
        {
            return 0;
        }
    }
    return 1;
}

void process( vector<string> &vec )
{
    ans.clear();
    sort( vec.begin(), vec.end(), comp );
    for( int i = 0; i < vec.size(); i++ )
    {
        int f = 0;
        for( int j = i+1; j < vec.size(); j++ )
        {
            if( isSuffix( vec[i], vec[j] ) )
                f = 1;
        }
        if(!f)
            ans.pb(vec[i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        string s, ss;
        cin >> s;
        int j;
        cin >> j;
        for( int k = 0; k < j; k++ )
        {
            cin >> ss;
            mm[s].pb(ss);
        }
    }
    cout << mm.size() << endl;
    for( auto it = mm.begin(); it != mm.end(); it++ )
    {
        string s = it->xx;
        vector<string> &vec = mm[s];
        process( vec );
        cout << s << " " << ans.size() << " ";
        for( int i = 0; i < ans.size(); i++ )
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
