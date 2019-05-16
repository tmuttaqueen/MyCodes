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

string s;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    cin >> s;
    int c = 0;
    char ch = 'a';
    for( int i = 0; i < s.length(); i++ )
    {
        if( s[i] != 'z' && ch <= 'z' && ch >= s[i] )
        {
            s[i]= ch;
            ch++;
        }
    }

    ch = 'a';
    for( int i = 0; i < s.length(); i++ )
    {
        if( s[i] == ch )
            ch++;
    }
    if( ch <= 'z' )
    {
        cout << -1 << endl;
    }
    else
        cout << s << endl;

    return 0;


}
