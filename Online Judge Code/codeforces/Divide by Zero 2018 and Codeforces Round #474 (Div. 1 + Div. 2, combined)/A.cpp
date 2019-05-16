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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
string s;
    cin >> s;
    int ab = 0, bc = 0, ex = 0, a = 0, b = 0, c = 0;
    for( int i = 0; i < s.length(); i++ )
    {
        if( s[i] == 'a' ) a++;
        else if( s[i] == 'b' ) b++;
        else c++;
        if( i > 0 && s[i] == 'b' && s[i-1] == 'a' ) ab++;
        else if( i > 0 && s[i] == 'c' && s[i-1] == 'b' ) bc++;
        else if( i > 0 && s[i] != s[i-1] ) ex++;
    }
    if( ex == 0 && ab== 1 && bc == 1 && ( a == c || b == c ) )
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}
