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
string s, t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;

    int x, y;
    cin >> x >> y;
    cin >> s >> t;
    if( s[0] == '*' )
    {
        int j = t.length()-1;
        for( int i = s.length()-1; i >= 1; i--, j-- )
        {
            if( j < 0 || s[i] != t[j] )
            {
                cout << "NO" << endl;
                return 0;
            }

        }
        cout << "YES" << endl;
        return 0;
    }
    else if( s[ s.length()-1 ] == '*' )
    {
        int j = 0;
        for( int i = 0; i + 1 < s.length(); i++, j++ )
        {
            if( j >= t.length() || s[i] != t[j] )
            {
                cout << "NO" << endl;
                return 0;
            }

        }
        cout << "YES" << endl;
        return 0;
    }
    else
    {
        int f = 0;
        while( f < s.length() )
        {
            if( s[f] == '*' ) break;
            f++;
        }

        int j = 0;
        for( int i = 0; i < f; i++, j++ )
        {
            if( j >= t.length() || s[i] != t[j] )
            {
                cout << "NO" << endl;
                return 0;
            }
        }
        int k = t.length()-1;
        for( int i = s.length()-1; i > f; i--, k-- )
        {
            if( k < j || s[i] != t[k] )
            {
                cout << "NO" << endl;
                return 0;
            }
        }
        cout << "YES" << endl;
        return 0;
    }
    return 0;
}
